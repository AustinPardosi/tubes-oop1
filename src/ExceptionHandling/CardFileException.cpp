// File: CardFileException.cpp
// Berisi implementasi dari kelas CardFileException

#include "CardFileException.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

CardFileException::CardFileException(int type) {
    this->type = type;
}

/*--------------------------------------------------------------------*/
/*-------------------------SHOW ERROR SEGMENT-------------------------*/

void CardFileException::printMessage() {
    if(this->type == 0) {
        cout << "\033[31m" << "Sorry, there is wrong format (2 int) in your txt file" << endl;
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->type == 1) {
        cout << "\033[31m" << "Oops... your cardValue is out of specification :(" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->type == 2) {
        cout << "\033[31m" << "Sorry, there are > 52 Lines or < 52 Lines in your txt file" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->type == 3) {
        cout << "\033[31m" << "Oops... there are duplicate cards in your txt file :(" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    }
}