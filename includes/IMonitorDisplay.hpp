/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:44:35 by csinglet          #+#    #+#             */
/*   Updated: 2019/07/27 20:17:05 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
#define IMONITORDISPLAY_H

#include <vector>

class IMonitorModule;

class IMonitorDisplay
{
	public:
	virtual void draw(std::vector<IMonitorModule *> modules) const = 0;
};

#endif
