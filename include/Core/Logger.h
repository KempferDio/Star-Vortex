#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>


#define CLOCKS_PER_MS (CLOCKS_PER_SEC/1000.0f)

/*
    Logger class
    Creates 'log.txt' and write message into it
*/

namespace Core
{
class Logger
{
public:
  static void initLogFile();
  static int Log(const std::string &msg, const char *module);
  static bool isLogFileCreated;
  static clock_t startTime;
private:
  
};
}

#endif //LOGGER_H