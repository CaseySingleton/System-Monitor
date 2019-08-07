/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:52:47 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 23:33:19 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TerminalDisplay.hpp"

TerminalDisplay::TerminalDisplay()
{
	// ncurses init
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	clear();
	this->_width = getmaxx(stdscr);
	this->_height = getmaxy(stdscr);
}

TerminalDisplay::TerminalDisplay(const TerminalDisplay & src) :
	_width(src._width) {}

TerminalDisplay::~TerminalDisplay() {}

static void draw_box(int left, int top, int width, int height)
{
	int right = left + width - 1;
	int bottom = top + height - 1;
	mvaddch(top, left, ',');
	mvaddch(top, right, ',');
	mvaddch(bottom, left, '\'');
	mvaddch(bottom, right, '\'');
	for (int i = left + 1; i < right; i++)
	{
		mvaddch(top, i, '-');
		mvaddch(bottom, i, '-');
	}
	for (int j = top + 1; j < bottom; j++)
	{
		mvaddch(j, left, '|');
		mvaddch(j, right, '|');
	}
}

void TerminalDisplay::draw(std::vector<IMonitorModule *> modules) const
{
	int x = 0;
	int y = 0;
	std::vector<IMonitorModule *>::iterator it = modules.begin();
	std::vector<IMonitorModule *>::iterator ite = modules.end();
	while (it != ite)
	{
		draw_box(x, y, 50, 15);
		(*it)->draw(this, x + 2, y + 1, 36, 13);
		x += 51;
		if (x + 50 > this->_width)
		{
			x = 0;
			y += 15;
		}
		it++;
	}
	int key = getch();
	if (key != ERR && key < 50)
	{
		endwin();
		exit(0);
	}
}

TerminalDisplay & TerminalDisplay::operator=(const TerminalDisplay & src)
{
	this->_width = src._width;
	this->_height = src._height;
	return *this;
}
