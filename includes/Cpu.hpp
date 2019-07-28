/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:35:36 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/26 21:35:37 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP

# include <thread>
# include <iostream>
# include "CpuCore.hpp"

typedef std::map<std::string, coreUsage> cpuInfo_t;

class Cpu
{
	private:
		unsigned _numberOfCores;
		CpuCore *_cpuCores;
		cpuInfo_t _ref;
		cpuInfo_t getCpuInfo(void);

	public:
		Cpu(void);
		Cpu(Cpu const &);
		~Cpu(void);
		// Operators
		Cpu & operator=(Cpu const &);
		// Methods
		cpuInfo_t getCpuUsage(void);
		// Setters
		// Getters
		unsigned getNumberOfCores(void) const;
};

#endif
