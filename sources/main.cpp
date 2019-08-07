/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:26:11 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 23:10:58 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <libproc.h>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"
#include "TestModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"
#include "FrameClock.hpp"
#include "DateTimeModule.hpp"
#include "WhoModule.hpp"
#include "NetworkModule.hpp"
#include "SystemInfoModule.hpp"
#include "GameOfLifeModule.hpp"

std::map<std::string, IMonitorModule *> moduleListInit()
{
	std::map<std::string, IMonitorModule *> ret;
	ret["who"] = new WhoModule;
	ret["os"] = new SystemInfoModule;
	ret["date"] = new DateTimeModule;
	ret["cpu"] = new CpuModule;
	ret["ram"] = new RamModule;
	ret["net"] = new NetworkModule;
	ret["test"] = new TestModule;
	ret["gol"] = new GameOfLifeModule;
	return ret;
}

const std::map<std::string, IMonitorModule *> g_moduleList = moduleListInit();

void exitWithUsage()
{
	std::cout << "usage: ./ft_gkrellm [";
	std::map<std::string, IMonitorModule *>::const_iterator it = g_moduleList.begin();
	std::map<std::string, IMonitorModule *>::const_iterator ite = g_moduleList.end();
	bool first = true;
	while (it != ite)
	{
		if (!first)
			std::cout << "|";
		first = false;
		std::cout << it->first;
		it++;
	}
	std::cout << "]+" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		exitWithUsage();
	std::vector<IMonitorModule *> modules;
	for (int i = 1; i < argc; i++)
	{
		std::map<std::string, IMonitorModule *>::const_iterator module;
		module = g_moduleList.find(std::string(argv[i]));
		if (module == g_moduleList.end())
			exitWithUsage();
		modules.push_back(module->second->clone());
	}
	IMonitorDisplay *display = new TerminalDisplay;

	srand(time(0));
	FrameClock clock;
	int framesBeforeUpdate = 0;
	for (;;)
	{
		if (clock.tick())
		{
			if (framesBeforeUpdate <= 0)
			{
				framesBeforeUpdate = 30;
				std::vector<IMonitorModule *>::iterator it = modules.begin();
				std::vector<IMonitorModule *>::iterator ite = modules.end();
				while (it != ite)
				{
					(*it)->update();
					it++;
				}
			}
			framesBeforeUpdate--;
			clear();
			display->draw(modules);
			move(0, 0);
			refresh();
		}
	}
	return (0);
}
