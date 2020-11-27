//
// Created by Mac on 26.11.2020.
//

#include "Customer.h"
#include "LogicalError.h"


Customer::Customer(char *name, char *secondName, char *surname, Bank bank, char *cardId, double limit, double state)
        : name(name), secondName(secondName), surname(surname), bank(bank), cardId(cardId), limit(limit),
          state(state) {}

Customer::~Customer() {

}

char *Customer::getName() const {
    return name;
}

char *Customer::getSecondName() const {
    return secondName;
}

char *Customer::getSurname() const {
    return surname;
}

Bank Customer::getBank() const {
    return bank;
}

char *Customer::getCardId() const {
    return cardId;
}

double Customer::getLimit() const {
    return limit;
}

double Customer::getState() const {
    return state;
}

void Customer::printToFile() {
    std::ofstream out(OUTPUT_FILE);

    out << *this;
}

//void Customer::readFromFile() {
//    std::ofstream in(INPUT_FILE);
//
//    in >> *this;
//}

Customer& Customer::operator=(const Customer& other) {
    this->name = other.getName();
    this->secondName = other.getSecondName();
    this->surname = other.getSurname();
    this->bank = other.getBank();
    this->cardId = other.getCardId();
    this->limit = other.getLimit();
    this->state = other.getState();
    return *this;
}

bool Customer::operator==(const Customer &rhs) const {
    return name == rhs.name &&
           secondName == rhs.secondName &&
           surname == rhs.surname &&
           bank == rhs.bank &&
           cardId == rhs.cardId &&
           limit == rhs.limit &&
           state == rhs.state;
}

bool Customer::operator!=(const Customer &rhs) const {
    return !(rhs == *this);
}

bool Customer::operator<(const Customer& other) const {
    return this->state < other.getState();
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
    os << "name: " << customer.name << " second name: " << customer.secondName << " surname: " << customer.surname
       << " bank: ";
    if ( customer.bank == PrivatBank) {
        os << "PrivatBank";
    } else if ( customer.bank == MonoBank ) {
        os << "MonoBank";
    } else if ( customer.bank == Pumb ) {
        os << "Pumb";
    }


    os << " cardId: " << customer.cardId << " limit: " << customer.limit << " state: "
       << customer.state;
    return os;
}

bool isNumber(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

std::istream &operator>>(std::istream &in, Customer &c) {
    c.name = new char[30];
    c.surname = new char[30];
    c.secondName = new char[30];
    c.cardId = new char[17];
    in >> c.name;
    in >> c.secondName;
    in >> c.surname;
    in >> reinterpret_cast<int &>(c.bank);
    if ( in.fail()) {
        throw std::exception();
    }
    in >> c.cardId;
    in >> c.limit;
    in >> c.state;
    if ( c.state < 0 ) {
        throw LogicalError();
    }

    return in;
}

void Customer::setName(char *name) {
    Customer::name = name;
}

void Customer::setSecondName(char *secondName) {
    Customer::secondName = secondName;
}

void Customer::setSurname(char *surname) {
    Customer::surname = surname;
}

void Customer::setBank(Bank bank) {
    Customer::bank = bank;
}

void Customer::setCardId(char *cardId) {
    Customer::cardId = cardId;
}

void Customer::setLimit(double limit) {
    Customer::limit = limit;
}

void Customer::setState(double state) {
    Customer::state = state;
}

Customer::Customer() {
    this->name = NULL;
    this->surname = NULL;
    this->secondName = NULL;
    this->cardId = NULL;
}




