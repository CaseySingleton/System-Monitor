#include "GameOfLifeModule.hpp"

static bool g_randStarted = false;

static void startRand()
{
	if (g_randStarted == false)
	{
		srand(time(0));
		g_randStarted = true;
	}
}

GameOfLifeModule::GameOfLifeModule() : _width(36), _height(13)
{
	startRand();
	this->_arr = new bool *[this->_height];
	this->_arr_old = new bool *[this->_height];
	for (int y = 0; y < this->_height; y++)
	{
		this->_arr[y] = new bool[this->_width];
		this->_arr_old[y] = new bool[this->_width];
		for (int x = 0; x < this->_width; x++)
			this->_arr[y][x] = rand() % 5 == 0;
	}
}

GameOfLifeModule::GameOfLifeModule(const GameOfLifeModule & src) : _width(36), _height(13)
{
	this->_arr = new bool *[this->_height];
	this->_arr_old = new bool *[this->_height];
	for (int y = 0; y < this->_height; y++)
	{
		this->_arr[y] = new bool[this->_width];
		this->_arr_old[y] = new bool[this->_width];
		for (int x = 0; x < this->_width; x++)
			this->_arr[y][x] = rand() % 5 == 0;
	}
}

GameOfLifeModule::~GameOfLifeModule() {}

bool GameOfLifeModule::getSpot(int x, int y)
{
	while (x < 0)
		x += this->_width;
	while (y < 0)
		y += this->_height;
	return this->_arr_old[y % this->_height][x % this->_width];
}

void GameOfLifeModule::update()
{
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
			this->_arr_old[y][x] = this->_arr[y][x];
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
		{
			int neighbors = 0;
			if (this->getSpot(x - 1, y - 1)) neighbors++;
			if (this->getSpot(x - 1, y)) neighbors++;
			if (this->getSpot(x - 1, y + 1)) neighbors++;
			if (this->getSpot(x, y - 1)) neighbors++;
			if (this->getSpot(x, y + 1)) neighbors++;
			if (this->getSpot(x + 1, y - 1)) neighbors++;
			if (this->getSpot(x + 1, y)) neighbors++;
			if (this->getSpot(x + 1, y + 1)) neighbors++;
			if (neighbors == 3)
				this->_arr[y][x] = true;
			else if (neighbors == 2 && this->getSpot(x, y))
				this->_arr[y][x] = true;
			else
				this->_arr[y][x] = false;
		}
}

void GameOfLifeModule::draw(const TerminalDisplay *t, int left, int top, int width, int height) const
{
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
			if (this->_arr[y][x])
				mvaddch(top + y, left + x, 'o');
}

IMonitorModule *GameOfLifeModule::clone() const
{
	return new GameOfLifeModule();
}

GameOfLifeModule & GameOfLifeModule::operator=(const GameOfLifeModule & src)
{
	return *this;
}
