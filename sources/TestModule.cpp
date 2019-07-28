#include "TestModule.hpp"

TestModule::TestModule()
{
	this->c = 'A' + rand() % 26;
}

TestModule::TestModule(const TestModule & src)
{
	this->c = src.c;
}

TestModule::~TestModule() {}

void TestModule::update() {}

void TestModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	for(int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			mvaddch(y + j, x + i, this->c);
}

TestModule & TestModule::operator=(const TestModule & src)
{
	this->c = src.c;
	return *this;
}
