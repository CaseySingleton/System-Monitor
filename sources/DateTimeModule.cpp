#include "DateTimeModule.hpp"

const char *g_outputFormat[2] =
{
	"Day:  %x (%a)",
	"Time: %I:%M:%S %p"
};

DateTimeModule::DateTimeModule() {}

DateTimeModule::DateTimeModule(const DateTimeModule & src) {}

DateTimeModule::~DateTimeModule() {}

void DateTimeModule::update() {}

void DateTimeModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	std::time_t timenow;
	struct tm * timeinfo;
	char timebuff[42];

	timenow = std::time(0);
	timeinfo = std::localtime(&timenow);
	for (int i = 0; i < 2; i++)
	{
		const char *formatString = g_outputFormat[i];
		strftime(timebuff, sizeof(timebuff), formatString, timeinfo);
		mvaddstr(y + i, x, timebuff);
	}
}

DateTimeModule & DateTimeModule::operator=(const DateTimeModule & src)
{
	return *this;
}
