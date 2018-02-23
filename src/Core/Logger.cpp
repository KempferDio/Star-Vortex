#include <Core/Engine/Logger.h>

using namespace Core;

int Logger::Log(const std::string &msg, const char *module)
{
    std::ofstream logFile;

    logFile.open("log.txt", std::ofstream::app);
    if (!logFile.is_open())
    {
        printf("ERROR::LOG_FILE_CAN_NOT_OPEN/CREATE");
        return 1;
    }
    time_t now = time(0);
    char *dt = ctime(&now);
    logFile << "===============================================\n";
    logFile << dt << "Message - " << msg << "\n"
            << "Module - " << module << "\n";
    logFile << "===============================================\n";
    logFile.close();
    return 0;
}