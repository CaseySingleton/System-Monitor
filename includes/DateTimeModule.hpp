/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:49:53 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 22:24:32 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATETIMEMODULE_H
#define DATETIMEMODULE_H

#include <curses.h>
#include <ctime>
#include <array>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"

class DateTimeModule : public IMonitorModule
{
	public:
	DateTimeModule();
	DateTimeModule(const DateTimeModule & src);
	~DateTimeModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;

	DateTimeModule & operator=(const DateTimeModule & src);
};

#endif
