#include <Core/Engine/Logger.h>

using namespace Core;

int Logger::Log(const char *msg)
{
    std::ofstream logFile;
    logFile.open("log.txt");
    if (!logFile.is_open())
    {
        printf("ERROR::LOG_FILE_CAN_NOT_OPEN/CREATE");
        return 1;
    }
    logFile << msg;
    logFile.close();

    return 0;
}