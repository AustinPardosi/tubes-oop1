// Next.hpp
#ifndef COMMAND_NEXT_HPP
#define COMMAND_NEXT_HPP

#include "Command.hpp"

class Next : public Command {
    public:
        // Konstruktor command
        Next();
        
        // Member Function
        // Menjalankan command
        void doCommand();
};

#endif