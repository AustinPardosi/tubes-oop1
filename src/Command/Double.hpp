// File: Double.hpp
// Berisi deklarasi dari kelas Double

#ifndef COMMAND_DOUBLE_HPP
#define COMMAND_DOUBLE_HPP

#include "Command.hpp"

class Double : public Command {
    public:
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // ctor
        Double();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do double command
        void doCommand(Game& game);
};

#endif