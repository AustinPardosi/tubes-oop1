// File: Parse.cpp
// Berisi implementasi dari kelas Parse

#include "Parse.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Parse::Parse() {
    this->totalLine = 0;
}

/*--------------------------------------------------------------------*/
/*---------------------GETTER AND SETTER SEGMENT----------------------*/

vector<pair<int,int>> Parse::getCards() const {
    return this->cards;
}

int Parse::getTotalLine() const {
    return this->totalLine;
}

/*--------------------------------------------------------------------*/
/*--------------------------PARSING SEGMENT---------------------------*/

void Parse::parsing(string inputfile) {
    // Declare temporary variables
    string line;
    vector<pair<int, int>> validateCards;
    int cardNumber, cardColor;
    ifstream inputFile(inputfile);

        // Read card from txt file
    while (getline(inputFile, line)) {
        this->totalLine++;

        // Validate every line must have 2 values
        istringstream iss(line);
        if (!(iss >> cardNumber >> cardColor) || (iss >> cardColor)) {
            inputFile.close();
            throw new CardFileException(0);
        }

        // Validate value of cardNumber and cardColor
        // 1 <= cardNumber <= 13 dan 0 <= cardColor <= 3
        if (cardNumber < 1 || cardNumber > 13 || cardColor < 0 || cardColor > 3) {
            inputFile.close();
            throw new CardFileException(1);
        }

        validateCards.push_back(make_pair(cardNumber, cardColor));
    }

    // Validate totalLine must be 52
    if (this->totalLine != 52) {
        inputFile.close();
        throw new CardFileException(2);
    }

    
    for(int i = 0; i < validateCards.size()-1; i++) {
        for(int j = i + 1; j < validateCards.size(); j++) {
            if(validateCards[i] == validateCards[j]) {
                inputFile.close();
                throw new CardFileException(3);
            }
        }
    }

    inputFile.close();
    for(const auto& i : validateCards) {
        this->cards.emplace_back(i);
    }
}