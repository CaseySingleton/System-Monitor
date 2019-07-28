/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:32:36 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 23:49:40 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GraphicsDisplay.hpp"

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Hello world!");
	gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);
	get_widget_show_all(window);
}

GraphicsDisplay::GraphicsDisplay()
{
	this->_width = 1280;
	this->_height = 720;
	// gtk+ init
	this->_gtkApp = gtk_application_new("org.us.42.nwhitlow.gkrellm", G_APPLICATION_FLAGS_NONE);
	g_signal_connet(this->_gtkApp, "activate", G_CALLBACK(activate), NULL);
	const char **argv = {"./ft_gkrellm"};
	int status = g_application_run(G_APPLICATION(this->_gtkApp), 1, argv);
	g_object_unref(app);

	return status;
}

GraphicsDisplay::GraphicsDisplay(const GraphicsDisplay & src) :
	_width(src._width) {}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::draw(std::vector<IMonitorModule *> modules) const
{
	/*
	int x = 0;
	int y = 0;
	std::vector<IMonitorModule *>::iterator it = modules.begin();
	std::vector<IMonitorModule *>::iterator ite = modules.end();
	while (it != ite)
	{
		draw_box(x, y, 40, 15);
		(*it)->draw(this, x + 2, y + 1, 36, 13);
		x += 41;
		if (x + 40 > this->_width)
		{
			x = 0;
			y += 15;
		}
		it++;
	}
	*/
	// TODO catch exit
}

GraphicsDisplay & GraphicsDisplay::operator=(const GraphicsDisplay & src)
{
	this->_width = src._width;
	this->_height = src._height;
	return *this;
}
