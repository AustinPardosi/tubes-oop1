// File: Parse.cpp
// Berisi implementasi dari kelas Parse

#include "Parse.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Parse::Parse() {
    this->totalLine = 0;
    this->safe = false;
}

/*--------------------------------------------------------------------*/
/*---------------------GETTER AND SETTER SEGMENT----------------------*/

vector<pair<int,int>> Parse::getCards() const {
    return this->cards;
}

int Parse::getTotalLine() const {
    return this->totalLine;
}

bool Parse::getSafe() const {
    return this->safe;
}

/*--------------------------------------------------------------------*/
/*--------------------------PARSING SEGMENT---------------------------*/

void Parse::parsing(string inputfile) {
    // Declare temporary variables
    string line;
    vector<pair<int, int>> validateCards;
    int cardNumber, cardColor;
    ifstream inputFile(inputfile);

    while (!this->safe) {
        try {
            // Read card from txt file
            while (getline(inputFile, line)) {
                this->totalLine++;

                // Validate every line must have 2 values
                istringstream iss(line);
                if (!(iss >> cardNumber >> cardColor) || (iss >> cardColor)) {
                    // this->safe = false;
                    throw new CardFileException(0);
                }

                // Validate value of cardNumber and cardColor
                // 1 <= cardNumber <= 13 dan 0 <= cardColor <= 3
                if (cardNumber < 1 || cardNumber > 13 || cardColor < 0 || cardColor > 3) {
                    // this->safe = false;
                    throw new CardFileException(1);
                }

                validateCards.push_back(make_pair(cardNumber, cardColor));
            }

            // Validate totalLine must be 52
            if (this->totalLine != 52) {
                // this->safe = false;
                throw new CardFileException(2);
            }

            
            for(int i = 0; i < validateCards.size(); i++) {
                for(int j = i + 1; j < validateCards.size(); j++) {
                    if(validateCards[i] == validateCards[j]) {
                        throw new CardFileException(3);
                    }
                }
            }

            // Insert into cards
            for(const auto& i : validateCards) {
                this->cards.emplace_back(i);
            }

            this->safe = true;
            inputFile.close();
        } catch (BaseException* e) {
            e->printMessage();
        }
    }
}