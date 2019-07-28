/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemInfo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:45:34 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/27 23:35:20 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SystemInfo.hpp"

SystemInfo::SystemInfo(void)
{
	char *line = NULL;
	size_t len;
	FILE * n = popen("sw_vers -productName", "r");
	FILE * v = popen("sw_vers -productVersion", "r");
	FILE * b = popen("sw_vers -buildVersion", "r");
	if (n)
	{
		if (getline(&line, &len, n) != -1)
			_sysInfo.name = strndup(line, strlen(line) - 1);
		else
			_sysInfo.name = "N/A";
	}
	if (n)
	{
		if (getline(&line, &len, v) != -1)
			_sysInfo.version = strndup(line, strlen(line) - 1);
		else
			_sysInfo.version = "N/A";
	}
	if (n)
	{
		if (getline(&line, &len, b) != -1)
			_sysInfo.build = strndup(line, strlen(line) - 1);
		else
			_sysInfo.build = "N/A";
	}
	std::cout << _sysInfo.name << std::endl << _sysInfo.version << std::endl << _sysInfo.build << std::endl;
	return ;
}

SystemInfo::SystemInfo(SystemInfo const & src)
{
	_sysInfo = src._sysInfo;
}

SystemInfo::~SystemInfo(void)
{
	return ;
}

// Operators
SystemInfo & SystemInfo::operator=(SystemInfo const & rhs)
{
	_sysInfo = rhs._sysInfo;
	return (*this);
}

// Methods
sysInfo_s SystemInfo::getSystemInfo(void)
{
	return (_sysInfo);
}
