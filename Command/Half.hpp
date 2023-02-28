// Half.hpp
#ifndef COMMAND_HALF_HPP
#define COMMAND_HALF_HPP

#include "Command.hpp"

class Half : public Command {
    public:
        // Konstruktor command
        Half();
        
        // Member Function
        // Menjalankan command
        void doCommand();
};

#endif