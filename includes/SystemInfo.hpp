/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemInfo.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:45:41 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/26 23:45:42 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEMINFO_HPP
# define SYSTEMINFO_HPP

# include <stdio.h>
# include <string>
# include <string.h>
# include <iostream>

struct sysInfo_s
{
	std::string name;
	std::string version;
	std::string build;
};

class SystemInfo
{
	private:
		sysInfo_s _sysInfo;

	public:
		SystemInfo(void);
		SystemInfo(SystemInfo const &);
		~SystemInfo(void);
		// Operators
		SystemInfo & operator=(SystemInfo const &);
		// Methods
		sysInfo_s getSystemInfo(void);
};

#endif
