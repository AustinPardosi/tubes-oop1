// File: Player.cpp
// Berisi implementasi dari kelas Player

#include "Player.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Player::Player() : name(""), commandId(0), abilityId(0), currentPoin(0), alreadyPlayed(false), abilityUsed(false), abilityless(false) {}

Player::Player(vector<Card> listCards, string name, int commandId, int abilityId, int currentPoin, bool alreadyPlayed, bool abilityUsed, bool abilityless) {
    this->listOfCard = listCards;
    this->name = name;
    this->commandId = commandId;
    this->abilityId = abilityId;
    this->currentPoin = currentPoin;
    this->alreadyPlayed = alreadyPlayed;
    this->abilityUsed = abilityUsed;
    this->abilityless = abilityless;
}

Player::Player(const Player& other) : name(other.name), commandId(other.commandId), abilityId(other.abilityId), currentPoin(other.currentPoin), alreadyPlayed(other.alreadyPlayed), abilityUsed(other.abilityUsed), abilityless(other.abilityless) {
    this->listOfCard = other.listOfCard;
}

Player::~Player() {}

Player& Player::operator=(const Player& other) {
    this->name = other.name;
    this->commandId = other.commandId;
    this->abilityId = other.abilityId;
    this->currentPoin = other.currentPoin;
    this->alreadyPlayed = other.alreadyPlayed;
    this->abilityUsed = other.abilityUsed;
    this->abilityless = other.abilityless;
    this->listOfCard = other.listOfCard;
    return *this;
}

/*--------------------------------------------------------------------*/
/*---------------------GETTER AND SETTER SEGMENT----------------------*/

void Player::askForName(int i) {
    string name;
    cout << "Please enter player " << i << " name:" << endl;
    cout << ">> ";
    cin >> name;
    this->name = name;
}

string Player::getName() const {
    return this->name;
}

void Player::setAbilityID(int abilityId) {
    this->abilityId = abilityId;
}

bool Player::getAlreadyPlayed() const {
    return this->alreadyPlayed;
}

void Player::setAlreadyPlayed(bool alreadyPlayed) {
    this->alreadyPlayed = alreadyPlayed;
}

bool Player::getAbilityUsed() const {
    return this->abilityUsed;
}

void Player::setAbilityUsed(bool abilityUsed) {
    this->abilityUsed = abilityUsed;
}

bool Player::getAbilityless() const {
    return this->abilityless;
}

void Player::setAbilityless(bool abilityless) {
    this->abilityless = abilityless;
}

int Player::getCurrentPoin() const {
    return this->currentPoin;
}

int Player::getCommandID() const {
    return this->commandId;
}

/*--------------------------------------------------------------------*/
/*------------------------ADDING CARDS SEGMENT------------------------*/
        
void Player::addCards(const InventoryHolder& other) {
    *this = *this + other.getCard(0);
    *this = *this + other.getCard(1);
}

Player Player::operator+(const Card& other) {
    Player temp(*this);
    temp.listOfCard.push_back(other);
    return Player(temp);
}

/*--------------------------------------------------------------------*/
/*-----------------------REMOVING CARDS SEGMENT-----------------------*/

void Player::removeCards(int cardsRemoved) {
    *this = *this - cardsRemoved;
}

Player Player::operator-(int cardsRemoved) {
    Player temp(*this);
    temp.listOfCard.erase(temp.listOfCard.begin()+cardsRemoved);
    return Player(temp);
}

/*--------------------------------------------------------------------*/
/*-----------------------ASKING ACTION SEGMENT------------------------*/

void Player::fillMapsOfCommand(map<string, int>& listCommands) {
    listCommands.insert(pair<string, int> ("double", 1));
    listCommands.insert(pair<string, int> ("half", 2));
    listCommands.insert(pair<string, int> ("next", 3));
    listCommands.insert(pair<string, int> ("abilityless", 4));
    listCommands.insert(pair<string, int> ("quadruple", 5));
    listCommands.insert(pair<string, int> ("quarter", 6));
    listCommands.insert(pair<string, int> ("re-roll", 7));
    listCommands.insert(pair<string, int> ("reverse", 8));
    listCommands.insert(pair<string, int> ("swapcard", 9));
    listCommands.insert(pair<string, int> ("switch", 10));
}

void Player::askForAction() {
    map<string, int> listCommands;
    fillMapsOfCommand(listCommands);
    
    string command;
    cout << ">> ";
    cin >> command;
    transform(command.begin(), command.end(), command.begin(), ::tolower);

    if (listCommands.find(command) == listCommands.end()) {
        throw new InvalidInputException;
    }

    if (listCommands[command] >= 4) {
        if (listCommands[command] != this->abilityId) {
            throw new EmptyAbilityCardException;
        }
        if (this->abilityUsed) {
            throw new AbilityCommandException(true, command);
        }
        if (this->abilityless) {
            throw new AbilityCommandException(false, command);
        }
    }

    this->commandId = listCommands[command];
}

/*--------------------------------------------------------------------*/
/*--------------------------COMBO SEGMENT-----------------------------*/

void Player::calculateCombo(vector<Card> tableCard) {
    // Mencari kombinasi maksimum yang dimiliki, mengubah atribut maxCombo
    currCombo.push_back(new HighCard(this->listOfCard,tableCard));
    currCombo.push_back(new Pair(this->listOfCard,tableCard));
    currCombo.push_back(new TwoPair(this->listOfCard,tableCard));
    currCombo.push_back(new ThreeKind(this->listOfCard,tableCard));
    currCombo.push_back(new Straight(this->listOfCard,tableCard));
    currCombo.push_back(new Flush(this->listOfCard,tableCard));
    currCombo.push_back(new FullHouse(this->listOfCard,tableCard));
    currCombo.push_back(new FourKind(this->listOfCard,tableCard));
    currCombo.push_back(new StraightFlush(this->listOfCard,tableCard));

    for_each(currCombo.begin(),currCombo.end(), [] (Combination* c) {
        c->check();
    });

    this->maxCombo = currCombo[getMax<Combination*>(currCombo)];
}

/*--------------------------------------------------------------------*/
/*----------------------SWAP AND SWITCH SEGMENT-----------------------*/

void Player::swapCardWithOther(Player& other, int handPos, int otherPos) {
    Card card1 = getCard(handPos);
    Card card2 = other.getCard(otherPos);

    removeCards(handPos);
    other.removeCards(otherPos);

    this->listOfCard.insert(this->listOfCard.begin()+handPos, card2);
    other.listOfCard.insert(other.listOfCard.begin()+otherPos, card1);
}

void Player::switchCardWithOther(Player& other) {
    addCards(other);
    other.addCards(*this);
    removeCards(0);
    removeCards(0);
    other.removeCards(0);
    other.removeCards(0);
}
/*--------------------------------------------------------------------*/
/*---------------------POINT MANAGEMENT SEGMENT-----------------------*/

Player Player::operator+(int poinHadiah) {
    return Player(this->listOfCard, this->name, this->commandId, this->abilityId, this->currentPoin + poinHadiah, this->alreadyPlayed, this->abilityUsed, this->abilityless);
}

/*--------------------------------------------------------------------*/
/*---------------------ADDITIONAL METHOD SEGMENT----------------------*/

bool Player::operator>(const Player& other) {
    return *(this->maxCombo) > *(other.maxCombo);
}

bool Player::operator<(const Player& other) {
    return *(this->maxCombo) < *(other.maxCombo);
}

bool Player::operator==(const Player& other) {
    return *(this->maxCombo) == *(other.maxCombo);
}

void Player::printInfo(int round) {
    cout << endl << "This is " << this->name << "'s turn!" << endl;
    cout << "Your cards: " << endl;
    showCards();

    if (round == 1) {
        cout << "You currently do not have any ability card" << endl;
    }
    else {
        map<string, int> listOfCommands;
        fillMapsOfCommand(listOfCommands);
        auto itr = find_if(listOfCommands.begin(), listOfCommands.end(), [this] (pair<string, int> elemen) {
                   return elemen.second == this->abilityId;
                   }); 
        cout << "Your ability card is " << itr->first << endl;
    }
    cout << "Insert your command" << endl;
}