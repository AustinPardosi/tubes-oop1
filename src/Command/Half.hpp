// File: Half.hpp
// Berisi deklarasi dari kelas Half

#ifndef COMMAND_HALF_HPP
#define COMMAND_HALF_HPP

#include "Command.hpp"

class Half : public Command {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor 
        Half();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/
        
        // tell the game object to do half command
        void doCommand(Game& game);
};

#endif