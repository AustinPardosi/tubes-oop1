// File: Command.hpp
// Berisi deklarasi dari kelas Command

#ifndef COMMAND_HPP
#define COMMAND_HPP

class Game;

class Command {
    protected:
        int commandID; // ID command yang bisa diakses user
        
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        Command();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/
        
        // abstract method, this class is too abstract to do this
        virtual void doCommand(Game& game) = 0;
};

#endif