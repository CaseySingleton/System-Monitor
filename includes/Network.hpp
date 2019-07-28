/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:52:58 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 01:23:13 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://unix.superglobalmegacorp.com/BSD4.4/newsrc/net/if.h.html <-- network info

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#define BYTES_IN_KILOBYTE_F 1000.0f
#define BYTES_IN_MEGABYTE_F 1000000.0f
#define BYTES_IN_GIGABYTE_F 1073741824.0f

# include <iostream>
# include <string>
# include <map>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <sys/sysctl.h>
# include <net/if.h>
# include <net/route.h>
# include <unistd.h>

typedef std::map<std::string, uint64_t> netInfo_t;

class Network
{
	private:
		netInfo_t _ref;
		netInfo_t getNetworkInfo(void);

	public:
		Network(void);
		Network(Network const &);
		~Network(void);
		// Operators
		Network & operator=(Network const &);
		// Methods
		netInfo_t getNetworkUsage(void);
		// Setters
		// Getters
};

#endif
