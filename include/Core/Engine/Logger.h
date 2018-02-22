#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
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
  static int Log(const char *msg, const char *module);

private:
};
}

#endif //LOGGER_H