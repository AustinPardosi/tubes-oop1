// File: Command.hpp
// Berisi deklarasi dari kelas Command

#ifndef COMMAND_HPP
#define COMMAND_HPP

class Game;

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