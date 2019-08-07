/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemInfoModule.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:10:34 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:55:08 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEMINFOMODULE_H
#define SYSTEMINFOMODULE_H

#include <curses.h>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"
#include "SystemInfo.hpp"

class SystemInfoModule : public IMonitorModule
{
	private:
	SystemInfo _sys;
	sysInfo_s _sysInfo;

	public:
	SystemInfoModule();
	SystemInfoModule(const SystemInfoModule & src);
	~SystemInfoModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;
	IMonitorModule *clone() const;

	SystemInfoModule & operator=(const SystemInfoModule & src);
};

#endif
