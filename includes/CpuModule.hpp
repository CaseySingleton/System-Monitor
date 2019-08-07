/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:52:03 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:55:22 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_H
#define CPUMODULE_H

#include <curses.h>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"
#include "Cpu.hpp"

class CpuModule : public IMonitorModule
{
	private:
	Cpu _cpu;
	cpuInfo_t _cpuInfo;

	public:
	CpuModule();
	CpuModule(const CpuModule & src);
	~CpuModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;
	IMonitorModule *clone() const;

	CpuModule & operator=(const CpuModule & src);
};

#endif
