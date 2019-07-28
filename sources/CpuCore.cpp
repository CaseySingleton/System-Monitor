/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuCore.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:58:14 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/26 21:58:15 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuCore.hpp"

CpuCore::CpuCore(void) : _coreNumber(0)
{
	std::cout << "Hi! I'm CPU core # " << _coreNumber << std::endl;
	return ;
}

CpuCore::CpuCore(natural_t coreNumber) : _coreNumber(coreNumber)
{
	std::cout << "Hi! I'm CPU core # " << _coreNumber << std::endl;
	return ;
}

CpuCore::CpuCore(CpuCore const & src)
{
	*this = src;
}

CpuCore::~CpuCore(void)
{
	return ;
}

// Operators
CpuCore & CpuCore::operator=(CpuCore const & rhs)
{
	if (this != &rhs)
	{
		_coreNumber = rhs.getCoreNumber();
	}
	return (*this);
}

// Methods
coreUsage CpuCore::getCoreUsage(void)
{
	processor_cpu_load_info_t cpuLoad;
	mach_msg_type_number_t processorMsgCount;
	natural_t processorCount;
	coreUsage usage;

	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, (processor_info_array_t *)&cpuLoad, &processorMsgCount);
	usage["system"] = cpuLoad[_coreNumber].cpu_ticks[CPU_STATE_SYSTEM];
	usage["user"] = cpuLoad[_coreNumber].cpu_ticks[CPU_STATE_USER] + cpuLoad[_coreNumber].cpu_ticks[CPU_STATE_NICE];
	usage["idle"] = cpuLoad[_coreNumber].cpu_ticks[CPU_STATE_IDLE];
	usage["used"] = usage["system"] + usage["user"];
	usage["total"] = usage["used"] + usage["idle"];
	return (usage);
}

// Setters
void CpuCore::setCoreNumber(unsigned coreNumber)
{
	_coreNumber = coreNumber;
	std::cout << "Now I'm CPU core # " << _coreNumber << std::endl;
}

// Getters
unsigned CpuCore::getCoreNumber(void) const
{
	return (_coreNumber);
}
