/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 03:08:56 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 00:48:17 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ram.hpp"

// host_statistics64

Ram::Ram(void)
{
	return ;
}

Ram::Ram(Ram const & src)
{
	*this = src;
}

Ram::~Ram(void)
{
	return ;
}

// Operators
Ram & Ram::operator=(Ram const & rhs)
{
	(void)rhs;
	return (*this);
}

// Methods
ramInfo_t Ram::getMemoryUsage(void)
{
	ramInfo_t ri;
	vm_size_t pageSize;
	vm_statistics64_data_t vmStats;
	mach_port_t machPort = mach_host_self();
	mach_msg_type_number_t count = sizeof(vmStats) / sizeof(natural_t);
	host_page_size(machPort, &pageSize);

	host_statistics64(machPort, HOST_VM_INFO, (host_info64_t)&vmStats, &count);

	ri["free"] = (int64_t)vmStats.free_count * (int64_t)pageSize;
	ri["used"] = ((int64_t)vmStats.active_count + (int64_t)vmStats.inactive_count + (int64_t)vmStats.wire_count) * (int64_t)pageSize;
	ri["total"] = ri["free"] + ri["used"];
	return (ri);
}

// Setters

// Getters


