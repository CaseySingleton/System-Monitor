/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemInfoModule.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:10:44 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:53:28 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SystemInfoModule.hpp"

SystemInfoModule::SystemInfoModule() {}

SystemInfoModule::SystemInfoModule(const SystemInfoModule & src) : _sys(src._sys), _sysInfo(src._sysInfo) {}

SystemInfoModule::~SystemInfoModule() {}

void SystemInfoModule::update()
{
	this->_sysInfo = this->_sys.getSystemInfo();
}

void SystemInfoModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	sysInfo_s s = this->_sysInfo;
	mvprintw(y, x, "System:  %s", s.name.c_str());
	mvprintw(y + 1, x, "Version: %s", s.version.c_str());
	mvprintw(y + 2, x, "Build:   %s", s.build.c_str());
}

IMonitorModule *SystemInfoModule::clone() const
{
	return new SystemInfoModule();
}

SystemInfoModule & SystemInfoModule::operator=(const SystemInfoModule & src)
{
	this->_sys = src._sys;
	this->_sysInfo = src._sysInfo;
	return *this;
}
