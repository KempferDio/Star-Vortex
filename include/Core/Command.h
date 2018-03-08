#ifndef COMMAND_H
#define COMMAND_H

namespace Core {
    class Command {
        virtual ~Command() {}
        virtual void Execute() = 0;
    };
}


#endif