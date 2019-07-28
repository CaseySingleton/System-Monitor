/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FrameClock.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:39:32 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/07/28 01:05:12 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FrameClock.hpp"
#include "time_util.hpp"

FrameClock::FrameClock() : _maxFPS(60), _realFPS(0)
{
	this->_updateInterval = NSEC_IN_SEC / this->_maxFPS;
	clock_gettime(CLOCK_REALTIME, &(this->_nextUpdateAt));
}

FrameClock::FrameClock(const FrameClock & src) :
	_maxFPS(src._maxFPS),
	_updateInterval(src._updateInterval),
	_realFPS(src._realFPS),
	_nextUpdateAt(src._nextUpdateAt),
	_lastUpdateAt(src._lastUpdateAt)
{}
FrameClock::~FrameClock() {}

bool FrameClock::tick()
{
	struct timespec	now;
	clock_gettime(CLOCK_REALTIME, &now);
	long diff = time_subtract(now, this->_nextUpdateAt);
	if (diff > 0)
	{
		this->_realFPS = static_cast<float>(NSEC_IN_SEC) / time_subtract(this->_nextUpdateAt, this->_lastUpdateAt);
		this->_lastUpdateAt = this->_nextUpdateAt;
		if (diff > this->_updateInterval)
			this->_nextUpdateAt = now;
		else
			this->_nextUpdateAt = time_add(this->_nextUpdateAt, this->_updateInterval);
		return true;
	}
	return false;
}

float FrameClock::getRealFPS() const
{
	return this->_realFPS;
}

FrameClock & FrameClock::operator=(const FrameClock & src)
{
	this->_maxFPS = src._maxFPS;
	this->_updateInterval = src._updateInterval;
	this->_realFPS = src._realFPS;
	this->_nextUpdateAt = src._nextUpdateAt;
	this->_lastUpdateAt = src._lastUpdateAt;
	return *this;
}
