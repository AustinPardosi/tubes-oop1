#ifndef CARD_FILE_EXCEPTION_HPP
#define CARD_FILE_EXCEPTION_HPP

#include "BaseException.hpp"

class CardFileException : public BaseException {
    public:
        CardFileException(int);
        void printMessage();
    private:
        int param;
};

#endif