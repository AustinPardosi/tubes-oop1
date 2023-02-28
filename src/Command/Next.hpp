// File: Next.hpp
// Berisi deklarasi dari kelas Next

#ifndef COMMAND_NEXT_HPP
#define COMMAND_NEXT_HPP

#include "Command.hpp"

class Next : public Command {
    public:
        // Konstruktor command
        Next();
        
        // Member Function
        // Menjalankan command
        void doCommand(const Game& game);
};

#endif