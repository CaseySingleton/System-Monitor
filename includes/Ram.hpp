/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 03:09:07 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 00:48:00 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP

# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <iostream>
# include <string>
# include <map>

typedef std::map<std::string, uint64_t> ramInfo_t;

class Ram
{
	private:

	public:
		Ram(void);
		Ram(Ram const &);
		~Ram(void);
		// Operators
		Ram & operator=(Ram const &);
		// Methods
		ramInfo_t getMemoryUsage(void);
		// Setters
		// Getters
};

#endif
