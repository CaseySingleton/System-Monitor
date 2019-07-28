/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:52:51 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/28 01:20:16 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Network.hpp"

Network::Network(void)
{
	_ref = getNetworkInfo();
}

Network::Network(Network const & src)
{
	(void)src;
	_ref = getNetworkInfo();
}

Network::~Network(void)
{
	return ;
}

// Operators
Network & Network::operator=(Network const & rhs)
{
	(void)rhs;
	return (*this);
}

// Methods
netInfo_t Network::getNetworkUsage(void)
{
	netInfo_t newRef = getNetworkInfo();

	newRef["packetsInPerSecond"] = newRef["packetsIn"] - _ref["packetsIn"];
	newRef["packetsOutPerSecond"] = newRef["packetsOut"] - _ref["packetsOut"];
	newRef["bytesInPerSecond"] = newRef["bytesIn"] - _ref["bytesIn"];
	newRef["bytesOutPerSecond"] = newRef["bytesOut"] - _ref["bytesOut"];
	_ref = newRef;
	return (newRef);
}

netInfo_t Network::getNetworkInfo(void)
{
	netInfo_t netInfo;
	int name[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
	int nameLen = 6;
	char *buffer;
	size_t len;
	unsigned i = 0;

	sysctl(name, nameLen, NULL, &len, NULL, 0);
	buffer = new char[len];
	sysctl(name, nameLen, (void *)buffer, &len, NULL, 0);
	netInfo["packetsIn"] = 0;
	netInfo["packetsOut"] = 0;
	netInfo["bytesIn"] = 0;
	netInfo["bytesOut"] = 0;
	while (i < len)
	{
		if_msghdr *info = reinterpret_cast<if_msghdr *>(buffer + i);
		if (info->ifm_type == RTM_IFINFO)
		{
			netInfo["packetsIn"] += info->ifm_data.ifi_ipackets;
			netInfo["packetsOut"] += info->ifm_data.ifi_opackets;
			netInfo["bytesIn"] += info->ifm_data.ifi_ibytes;
			netInfo["bytesOut"] += info->ifm_data.ifi_obytes;
		}
		i += info->ifm_msglen;
	}
	delete(buffer);
	return (netInfo);
}
