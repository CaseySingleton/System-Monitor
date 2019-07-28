/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:53:02 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 21:24:46 by nwhitlow         ###   ########.fr       */
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

void CpuModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	cpuInfo_t c = this->_cpuInfo;
	double onePercent = c["all"]["total"] / 100.0f;
	mvprintw(y, x, "system: %6.2f", c["all"]["system"] / onePercent);
	mvprintw(y + 1, x, "user:   %6.2f", c["all"]["user"] / onePercent);
	mvprintw(y + 2, x, "idle:   %6.2f", c["all"]["idle"] / onePercent);
	mvprintw(y + 3, x, "total:  %6.2f", c["all"]["used"] / onePercent);
}

CpuModule & CpuModule::operator=(const CpuModule & src)
{
	this->_cpu = src._cpu;
	this->_cpuInfo = src._cpuInfo;
	return *this;
}
