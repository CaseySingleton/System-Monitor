#ifndef GAMEOFLIFEMODULE_H
#define GAMEOFLIFEMODULE_H

#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "IMonitorModule.hpp"
#include "TerminalDisplay.hpp"

class GameOfLifeModule : public IMonitorModule
{
	private:
	int _width;
	int _height;
	bool **_arr;
	bool **_arr_old;
	bool getSpot(int x, int y);

	public:
	GameOfLifeModule();
	GameOfLifeModule(const GameOfLifeModule & src);
	~GameOfLifeModule();

	void update();
	void draw(const TerminalDisplay *t, int x, int y, int width, int height) const;
	IMonitorModule *clone() const;

	GameOfLifeModule & operator=(const GameOfLifeModule & src);
};

#endif
