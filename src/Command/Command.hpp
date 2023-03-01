// File: Command.hpp
// Berisi deklarasi dari kelas Command

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Game/Game.hpp"

class Command {
    public:
        // Konstruktor command
        Command();
        
        // Member Function
        // Menjalankan command
        virtual void doCommand(Game& game) = 0;

    protected:
        int commandID; // ID command yang bisa diakses user
};

#endif