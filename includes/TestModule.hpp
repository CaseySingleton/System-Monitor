/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:52:40 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 22:55:43 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <curses.h>
#include <stdlib.h>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"

class TestModule : public IMonitorModule
{
	private:
	char c;

	public:
	TestModule();
	TestModule(const TestModule & src);
	~TestModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;
	IMonitorModule *clone() const;

	TestModule & operator=(const TestModule & src);
};

#endif
