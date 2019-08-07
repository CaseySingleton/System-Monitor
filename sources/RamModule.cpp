/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:53:02 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:54:07 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

RamModule::RamModule() {}

RamModule::RamModule(const RamModule & src) : _ram(src._ram), _ramInfo(src._ramInfo) {}

RamModule::~RamModule() {}

void RamModule::update()
{
	this->_ramInfo = this->_ram.getMemoryUsage();
}

void RamModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	ramInfo_t r = this->_ramInfo;
	mvprintw(y, x, "free memory:  %" PRIu64, r["free"]);
	mvprintw(y + 1, x, "used memory:  %" PRIu64, r["used"]);
	float percent_used = static_cast<float>(r["used"]) / r["total"] * 100.0f;
	mvprintw(y + 2, x, "percent used: %f", percent_used);
	mvprintw(y + 3, x, "total memory: %.2f", r["total"] / 1073741824.0f);
}

IMonitorModule *RamModule::clone() const
{
	return new RamModule();
}

RamModule & RamModule::operator=(const RamModule & src)
{
	this->_ram = src._ram;
	this->_ramInfo = src._ramInfo;
	return *this;
}
