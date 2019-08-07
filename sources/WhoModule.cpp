#include "WhoModule.hpp"

WhoModule::WhoModule() {}

WhoModule::WhoModule(const WhoModule & src) : _user(src._user), _host(src._host) {}

WhoModule::~WhoModule() {}

void WhoModule::update()
{
	char buff[42];
	int status = gethostname(buff, sizeof(this->_host));
	if (status == 0)
		this->_host = std::string(buff);
	else
		this->_host = "ERR";
	char *user = getenv("USER");
	if (user != NULL)
		this->_user = std::string(user);
	else
		this->_user = "ERR";
}

void WhoModule::draw(const TerminalDisplay *t, int x, int y, int width, int height) const
{
	mvprintw(y, x, "Hostname: %s", this->_host.c_str());
	mvprintw(y + 1, x, "Username: %s", this->_user.c_str());
}

IMonitorModule *WhoModule::clone() const
{
	return new WhoModule();
}

WhoModule & WhoModule::operator=(const WhoModule & src)
{
	this->_host = src._host;
	this->_user = src._user;
	return *this;
}
