#include "CardFileException.hpp"

CardFileException::CardFileException(int _param) {
    this->param = _param;
}

void CardFileException::printMessage() {
    if(this->param == 0) {
        cout << "\033[31m" << "Sorry, there is wrong format {2 int} in your txt file" << endl;
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->param == 1) {
        cout << "\033[31m" << "Oops... your cardValue is out of specification :(" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->param == 2) {
        cout << "\033[31m" << "Sorry, there are > 52 Lines in your txt file" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    } else if (this->param == 3) {
        cout << "\033[31m" << "Oops... there are duplicate cards in your txt file :(" << endl; 
        cout << "Please check your txt file!" << "\033[0m" << endl;
    }
}