/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ImonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:44:43 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/27 20:17:42 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_H
#define IMONITORMODULE_H

class TerminalDisplay;

class IMonitorModule
{
	public:
	virtual void update() = 0;
	virtual void draw(const TerminalDisplay *display, int x, int y, int width, int height) const = 0;
};

#endif
