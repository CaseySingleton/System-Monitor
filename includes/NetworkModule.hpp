/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 01:07:41 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 01:23:43 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_H
#define NETWORKMODULE_H

#include <curses.h>
#include <inttypes.h>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"
#include "Network.hpp"

class NetworkModule : public IMonitorModule
{
	private:
	Network _net;
	netInfo_t _netInfo;

	public:
	NetworkModule();
	NetworkModule(const NetworkModule & src);
	~NetworkModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;

	NetworkModule & operator=(const NetworkModule & src);
};

#endif
