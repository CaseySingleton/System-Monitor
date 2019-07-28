/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 01:08:06 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 01:24:37 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule() {}

NetworkModule::NetworkModule(const NetworkModule & src) : _net(src._net), _netInfo(src._netInfo) {}

NetworkModule::~NetworkModule() {}

void NetworkModule::update()
{
	this->_netInfo = this->_net.getNetworkUsage();
}

void NetworkModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	netInfo_t n = this->_netInfo;
	mvprintw(y, x, "###### NETWORK ######");
	mvprintw(y + 1, x, "packets in:      %" PRIu64, n["packetsIn"]);
	mvprintw(y + 2, x, "packets out:     %" PRIu64, n["packetsOut"]);
	mvprintw(y + 3, x, "bytes in:        %" PRIu64, n["bytesIn"] / BYTES_IN_GIGABYTE_F);
	mvprintw(y + 4, x, "bytes out:       %" PRIu64, n["bytesOut"] / BYTES_IN_GIGABYTE_F);
	mvprintw(y + 5, x, "packets in/sec:  %" PRIu64, n["packetsInPerSecond"]);
	mvprintw(y + 6, x, "packets out/sec: %" PRIu64, n["packetsOutPerSecond"]);
	mvprintw(y + 7, x, "bytes in/sec:    %" PRIu64, n["bytesInPerSecond"] / BYTES_IN_KILOBYTE_F);
	mvprintw(y + 8, x, "bytes out/sec:   %" PRIu64, n["bytesOutPerSecond"] / BYTES_IN_KILOBYTE_F);
}

NetworkModule & NetworkModule::operator=(const NetworkModule & src)
{
	this->_net = src._net;
	this->_netInfo = src._netInfo;
	return *this;
}
