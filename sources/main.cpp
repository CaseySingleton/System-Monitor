/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:26:11 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 01:21:22 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
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

int main()
{
	srand(time(0));
	IMonitorDisplay *display = new TerminalDisplay;
	std::vector<IMonitorModule *> modules;
	modules.push_back(new WhoModule);
//	modules.push_back(new OSInfoModule);
	modules.push_back(new DateTimeModule);
	modules.push_back(new CpuModule);
	modules.push_back(new RamModule);
	modules.push_back(new NetworkModule);
//	modules.push_back(new TestModule);

	FrameClock clock;
	int framesBeforeUpdate = 0;
	for (;;)
	{
		if (clock.tick())
		{
			if (framesBeforeUpdate <= 0)
			{
				framesBeforeUpdate = 60;
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
}
