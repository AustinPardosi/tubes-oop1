// File: CardFileException.hpp
// Berisi deklarasi dari kelas CardFileException

#ifndef CARD_FILE_EXCEPTION_HPP
#define CARD_FILE_EXCEPTION_HPP

#include "BaseException.hpp"

class CardFileException : public BaseException {
    private:
        int type;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        CardFileException(int);

        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/

        // show an error when parsing the file (according to its type)
        void printMessage();
};

#endif