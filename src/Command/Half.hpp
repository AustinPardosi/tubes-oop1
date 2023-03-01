// File: Half.hpp
// Berisi deklarasi dari kelas Half

#ifndef COMMAND_HALF_HPP
#define COMMAND_HALF_HPP

#include "Command.hpp"

class Game;

class Half : public Command {
    public:
        // Konstruktor command
        Half();
        
        // Member Function
        // Menjalankan command
        void doCommand(Game& game);
};

#endif