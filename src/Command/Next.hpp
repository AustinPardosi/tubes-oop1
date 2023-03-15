// File: Next.hpp
// Berisi deklarasi dari kelas Next

#ifndef COMMAND_NEXT_HPP
#define COMMAND_NEXT_HPP

#include "Command.hpp"

class Next : public Command {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor 
        Next();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do next command
        void doCommand(Game& game);
};

#endif