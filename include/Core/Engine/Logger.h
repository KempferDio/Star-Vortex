#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
/*
    Base logger
*/

namespace Core
{
class Logger
{
  public:
    static int Log(const char *msg);

  private:
};
}

#endif //LOGGER_H