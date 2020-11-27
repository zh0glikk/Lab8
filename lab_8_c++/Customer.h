#ifndef LAB_8_CUSTOMER_H
#define LAB_8_CUSTOMER_H

#include <iostream>
#include <fstream>
#include "Bank.cpp"

#define OUTPUT_FILE "output.txt"
#define INPUT_FILE "/Users/mac/CLionProjects/lab_8/input.txt"

class Customer {
private:
    char* name{};
    char* secondName{};
    char* surname{};
    Bank bank;
    char* cardId{};
    double limit;
    double state;

public:

    Customer(char *name, char *secondName, char *surname, Bank bank, char *cardId, double limit, double state);

    Customer();

public:
    char *getName() const;

    char *getSecondName() const;

    char *getSurname() const;

    Bank getBank() const;

    char *getCardId() const;

    double getLimit() const;

    virtual ~Customer();

    double getState() const;

    void printToFile();

    void setName(char *name);

    void setSecondName(char *secondName);

    void setSurname(char *surname);

    void setBank(Bank bank);

    void setCardId(char *cardId);

    void setLimit(double limit);

    void setState(double state);

    Customer& operator=(const Customer& other);

    bool operator<(const Customer& other) const;

    bool operator==(const Customer &rhs) const;

    bool operator!=(const Customer &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
    friend std::istream& operator>>(std::istream &in, Customer& c);

    void readFromFile();
};

#endif //LAB_8_CUSTOMER_H
