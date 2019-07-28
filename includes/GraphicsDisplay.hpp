/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:32:17 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 23:36:10 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include <vector>
#include <gtk/gtk.h>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class GraphicsDisplay : public IMonitorDisplay
{
	private:
	int _width;
	int _height;
	GtkApplication *_gtkApp;

	public:
	GraphicsDisplay();
	GraphicsDisplay(const GraphicsDisplay & src);
	~GraphicsDisplay();

	void draw(std::vector<IMonitorModule *> modules) const;

	GraphicsDisplay & operator=(const GraphicsDisplay & src);
};

#endif
