// File: Double.hpp
// Berisi deklarasi dari kelas Double

#ifndef COMMAND_DOUBLE_HPP
#define COMMAND_DOUBLE_HPP

#include "Command.hpp"

class Double : public Command {
    public:
        // Konstruktor command
        Double();
        
        // Member Function
        // Menjalankan command
        void doCommand(Game& game);
};

#endif