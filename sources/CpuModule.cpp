/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:53:02 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:53:55 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

CpuModule::CpuModule() {}

CpuModule::CpuModule(const CpuModule & src) : _cpu(src._cpu), _cpuInfo(src._cpuInfo) {}

CpuModule::~CpuModule() {}

void CpuModule::update()
{
	this->_cpuInfo = this->_cpu.getCpuUsage();
}

static void printCore(coreUsage c, std::string name, int x, int y)
{
	double onePercent;
	int len;
	std::string *s;

	mvprintw(y, x, "%s: ", name.c_str());
	x += name.length() + 2;

	onePercent = c["total"] / 100.0f;
	attron(COLOR_PAIR(3));
	s = new std::string(25, '#');
	mvprintw(y, x, "%s", s->c_str());
	delete s;
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(1));
	len = c["used"] / onePercent / 4;
	if (len > 0)
	{
		s = new std::string(len, '#');
		mvprintw(y, x, "%s", s->c_str());
	}
	attroff(COLOR_PAIR(1));
	if (c["user"] > c["system"])
	{
		attron(COLOR_PAIR(2));
		len = c["user"] / onePercent / 4;
		if (len > 0)
		{
			s = new std::string(len, '#');
			mvprintw(y, x, "%s", s->c_str());
		}
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(4));
		len = c["system"] / onePercent / 4;
		if (len > 0)
		{
			s = new std::string(len, '#');
			mvprintw(y, x, "%s", s->c_str());
		}
		attroff(COLOR_PAIR(4));
	}
	else
	{
		attron(COLOR_PAIR(4));
		len = c["system"] / onePercent / 4;
		if (len > 0)
		{
			s = new std::string(len, '#');
			mvprintw(y, x, "%s", s->c_str());
		}
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(2));
		len = c["user"] / onePercent / 4;
		if (len > 0)
		{
			s = new std::string(len, '#');
			mvprintw(y, x, "%s", s->c_str());
		}
		attroff(COLOR_PAIR(2));
	}
}

void CpuModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	cpuInfo_t c = this->_cpuInfo;
	char buf[100];
    size_t buflen = 100;
    sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);

	mvprintw(y++, x, "%s", buf);
	attron(COLOR_PAIR(3));
	mvprintw(y, x, "FREE ");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(1));
	mvprintw(y, x + 5, "USED ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	mvprintw(y, x + 10, "USER ");
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(4));
	mvprintw(y++, x + 15, "SYSTEM");
	attroff(COLOR_PAIR(4));
	for (int i = 0; i < _cpu.getNumberOfCores(); i++)
	{
		std::string name = "core" + std::to_string(i);
		printCore(c[name], "core" + std::to_string(i + 1), x, y++);
	}
	printCore(c["all"], "All  ", x, y);
}

IMonitorModule *CpuModule::clone() const
{
	return new CpuModule();
}

CpuModule & CpuModule::operator=(const CpuModule & src)
{
	this->_cpu = src._cpu;
	this->_cpuInfo = src._cpuInfo;
	return *this;
}
