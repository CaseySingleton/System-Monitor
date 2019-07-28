/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhoModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:52:40 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 22:52:14 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHOMODULE_H
#define WHOMODULE_H

#include <curses.h>
#include <unistd.h>
#include <iostream>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"

class WhoModule : public IMonitorModule
{
	private:
	std::string _host;
	std::string _user;

	public:
	WhoModule();
	WhoModule(const WhoModule & src);
	~WhoModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;

	WhoModule & operator=(const WhoModule & src);
};

#endif
