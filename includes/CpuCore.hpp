/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuCore.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:58:03 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/26 21:58:03 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUCORE_HPP
# define CPUCORE_HPP

# include <iostream>
# include <map>
# include <sys/sysctl.h>
# include <sys/types.h>
# include <mach/mach.h>
# include <mach/processor_info.h>
# include <mach/mach_host.h>

typedef std::map<std::string, uint64_t> coreUsage;

class CpuCore
{
	private:
		natural_t _coreNumber;

	public:
		CpuCore(void);
		CpuCore(natural_t);
		CpuCore(CpuCore const &);
		~CpuCore(void);
		// Operators
		CpuCore & operator=(CpuCore const &);
		// Methods
		coreUsage getCoreUsage(void);
		// Setters
		void setCoreNumber(unsigned);
		// Gettters
		unsigned getCoreNumber(void) const;

};

#endif
