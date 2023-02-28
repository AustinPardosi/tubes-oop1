// Command.hpp
#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
    public:
        // Konstruktor command
        Command();
        
        // Getter dan setter
        bool isPlayerActive() const;
        
        // Member Function
        // Menjalankan command
        virtual void doCommand() = 0;

    protected:
        bool activeplayer; // berisi flag untuk mengecek apakah pemain ini sedang dala giliran
};

#endif