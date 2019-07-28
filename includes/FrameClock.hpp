/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrameClock.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:39:38 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/27 21:39:39 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMECLOCK_H
# define FRAMECLOCK_H

#include <time.h>

class FrameClock
{
	private:
	int _maxFPS;
	long _updateInterval;
	float _realFPS;
	struct timespec _nextUpdateAt;
	struct timespec _lastUpdateAt;

	public:
	FrameClock();
	FrameClock(const FrameClock & src);
	~FrameClock();

	bool tick();
	float getRealFPS() const;

	FrameClock & operator=(const FrameClock & src);
};

#endif
