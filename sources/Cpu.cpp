/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:35:30 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 22:56:55 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cpu.hpp"

Cpu::Cpu(void) : _numberOfCores(std::thread::hardware_concurrency()), _cpuCores(new CpuCore[_numberOfCores])
{
//	std::cout << "Number of cores on this machine: " << _numberOfCores << std::endl;
	for (unsigned i = 0; i < _numberOfCores; i++)
	{
		_cpuCores[i].setCoreNumber(i);
	}
	_ref = getCpuInfo();
}

Cpu::Cpu(Cpu const & src)
{
	*this = src;
}

Cpu::~Cpu(void)
{
	delete [] _cpuCores;
	return ;
}

// Operators
Cpu & Cpu::operator=(Cpu const & rhs)
{
	if (this != &rhs)
	{
		_numberOfCores = rhs.getNumberOfCores();
	}
	return (*this);
}
// Methods
cpuInfo_t Cpu::getCpuUsage(void)
{
	cpuInfo_t ret;
	cpuInfo_t newRef = getCpuInfo();
	for (unsigned i = 0; i < _numberOfCores; i++)
	{
		std::string name = "core" + std::to_string(i);
		ret[name]["system"] = newRef[name]["system"] - _ref[name]["system"];
		ret[name]["user"] = newRef[name]["user"] - _ref[name]["user"];
		ret[name]["idle"] = newRef[name]["idle"] - _ref[name]["idle"];
		ret[name]["used"] = newRef[name]["used"] - _ref[name]["used"];
		ret[name]["total"] = newRef[name]["total"] - _ref[name]["total"];
	}
	ret["all"]["system"] = newRef["all"]["system"] - _ref["all"]["system"];
	ret["all"]["user"] = newRef["all"]["user"] - _ref["all"]["user"];
	ret["all"]["idle"] = newRef["all"]["idle"] - _ref["all"]["idle"];
	ret["all"]["used"] = newRef["all"]["used"] - _ref["all"]["used"];
	ret["all"]["total"] = newRef["all"]["total"] - _ref["all"]["total"];
	_ref = newRef;
	return (ret);
}

cpuInfo_t Cpu::getCpuInfo(void)
{
	cpuInfo_t cpu;
	processor_cpu_load_info_t cpuLoad;
	mach_msg_type_number_t processorMsgCount;
	natural_t processorCount;
	coreUsage usage;

	cpu["all"]["system"] = 0.0f;
	cpu["all"]["user"] = 0.0f;
	cpu["all"]["idle"] = 0.0f;
	cpu["all"]["used"] = 0.0f;
	cpu["all"]["total"] = 0.0f;
	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, (processor_info_array_t *)&cpuLoad, &processorMsgCount);
	for (unsigned i = 0; i < _numberOfCores; i++)
	{
		std::string coreName = "core" + std::to_string(i);
		cpu[coreName] = _cpuCores[i].getCoreUsage();
		cpu["all"]["system"] += cpu[coreName]["system"];
		cpu["all"]["user"] += cpu[coreName]["user"];
		cpu["all"]["idle"] += cpu[coreName]["idle"];
		cpu["all"]["used"] += cpu[coreName]["used"];
		cpu["all"]["total"] += cpu[coreName]["total"];
	}
	return (cpu);
}

// Setters

// Getters
unsigned Cpu::getNumberOfCores(void) const
{
	return (_numberOfCores);
}
