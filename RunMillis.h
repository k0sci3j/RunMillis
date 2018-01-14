/*
 * RunMillis.h
 *
 *  Copyright BinOwl 2017
 *
 *  Created on: 09.07.2017
 *      Author: BinOwl
 */

#ifndef RUNMILLIS_H_
#define RUNMILLIS_H_

#include <Arduino.h>

class RunMillis
{
public:
	/**
	 * RunMillis constructor.
	 *
	 * @param interval
	 * @param callback
	 * @param update_after default true
	 */
	RunMillis(uint32_t interval, void (*callback)(void), const bool update_after=true):
		_previousMillis(0),
		_interval(interval),
		_currentMillis(0),
		_callback(callback),
		_update_after(update_after) {
	}
	/**
	 * setCallback function - Change callback after object is ready
	 *
	 * @param callback
	 */
	void setCallback(void (*callback)(void)) {
		_callback = callback;
	}
	/**
	 * run function - Try to run callback. If time period elapsed run callback function.
	 *
	 * @return bool - True if callback was executed
	 */
	bool run() {
		_currentMillis = millis();
		if (_currentMillis - _previousMillis >= _interval) {
			if(!_update_after)
				_updateTimer();
			_callback();
		    if(_update_after)
		    	_updateTimer();
		    return true;
		}
		return false;
	}
	/**
	 * setInterval - Change interval after object is ready
	 *
	 * @param interval
	 */
	void setInterval(uint32_t interval) {
		_interval = interval;
	}

private:
	uint32_t _previousMillis;
	uint32_t _interval;
	uint32_t _currentMillis;
	void (*_callback)();
	bool _update_after;
	void _updateTimer() {
		_previousMillis = _currentMillis;
	}
};




#endif /* RUNMILLIS_H_ */
