#include "Parse.hpp"

Parse::Parse() {
    this->totalLine = 0;
    this->safe = true;
}

vector<pair<int,int>> Parse::getCards() const {
    return this->cards;
}

int Parse::getTotalLine() const {
    return this->totalLine;
}

bool Parse::getSafe() const {
    return this->safe;
}
void Parse::parsing(string inputfile) {
    // Declare temporary variables
    string line;
    vector<pair<int, int>> validateCards;
    int cardNumber, cardColor;
    ifstream inputFile(inputfile);

    try {
        // Read card from txt file
        while (getline(inputFile, line)) {
            this->totalLine++;

            // Validate every line must have 2 values
            istringstream iss(line);
            if (!(iss >> cardNumber >> cardColor) || (iss >> cardColor)) {
                throw new CardFileException(0);
                this->safe = false;
            }

            // Validate value of cardNumber and cardColor
            // 1 <= cardNumber <= 13 dan 0 <= cardColor <= 3
            if (cardNumber < 1 || cardNumber > 13 || cardColor < 0 || cardColor > 3) {
                throw new CardFileException(1);
                this->safe = false;
            }

            validateCards.push_back(make_pair(cardNumber, cardColor));
        }

        // Validate totalLine must be 52
        if (this->totalLine != 52) {
            throw new CardFileException(2);
            this->safe = false;
        }
        
        // Validate every card unique
        if (this->safe) {
            for(int i = 0; i < validateCards.size(); i++) {
                for(int j = i + 1; j < validateCards.size(); j++) {
                    if(validateCards[i] == validateCards[j]) {
                        throw new CardFileException(3);
                        this->safe = false;
                    }
                }
            }
        }
    } catch (BaseException* e) {
        e->printMessage();
    }
    
    // Insert into cards
    if (this->safe) {
        for(const auto& i : validateCards) {
            this->cards.emplace_back(i);
        }
    }

    inputFile.close();
}