#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
/*
    Logger class
    Creates 'log.txt' and write message into it
*/

namespace Core
{
class Logger
{
public:
  static int Log(const std::string &msg, const char *module);

private:
};
}

#endif //LOGGER_H