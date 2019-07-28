/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 20:52:47 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 20:52:48 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALDISPLAY_H
#define TERMINALDISPLAY_H

#include <vector>
#include <curses.h>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class TerminalDisplay : public IMonitorDisplay
{
	private:
	int _width;
	int _height;

	public:
	TerminalDisplay();
	TerminalDisplay(const TerminalDisplay & src);
	~TerminalDisplay();

	void draw(std::vector<IMonitorModule *> modules) const;

	TerminalDisplay & operator=(const TerminalDisplay & src);
};

#endif
