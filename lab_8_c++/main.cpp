#include <iostream>
#include <vector>
#include "Customer.h"
#include "LogicalError.h"

class AccauntStateIsActive { //predicate
    public:
    bool operator()(const Customer c) const {
        return c.getState()>0;
    }
};

class RaiseLimit { //functor
public:
    void operator()(Customer *c) const {
        c->setLimit(c->getLimit() * 2);
    }
};


auto isActive{
  [](Customer c)
  {
    return c.getState()>0;
  }
};

void printCustomers(std::vector<Customer> customers) {
    std::cout << "===========" << std::endl;
    for ( auto it = customers.begin(); it != customers.end(); it++ ) {
        std::cout << *it << std::endl;
    }
        std::cout << "===========" << std::endl;
}

void printCustomer(Customer c) {
    std::cout << c << std::endl;
}

void task1() {
    Customer c1("Name1", "SecondName1", "Surname1", Bank::PrivatBank, "1234123412341234", 10000, 100);
    Customer c2("Name2", "SecondName2", "Surname2", Bank::PrivatBank, "1234123412341235", 10000, 700);
    Customer c3("Name3", "SecondName3", "Surname3", Bank::Pumb, "1234123412341236", 10000, 300);
    Customer c4("Name4", "SecondName4", "Surname4", Bank::MonoBank, "1234123412341237", 10000, 50);
    Customer c5("Name5", "SecondName5", "Surname5", Bank::PrivatBank, "1234123412341238", 10000, 500);

    std::vector<Customer> customers;

    customers.push_back(c1);
    customers.push_back(c2);
    customers.push_back(c3);
    customers.push_back(c4);
    customers.push_back(c5);


    printCustomers(customers);

    //don't modify
    //print each customer
    std::cout << "print each customer" << std::endl;
    for_each (customers.begin(), customers.end(), printCustomer);

    //modify
    //copy all from customers to customers2 exept last from customers
    std::cout << "copy all from customers to customers2 exept last from customers" << std::endl;
    std::vector<Customer> customers2;
    std::copy(customers.begin(), --customers.end(), std::back_inserter(customers2)); //insert iterator
    std::ostream_iterator<Customer>it(std::cout, "\n");
    std::cout << "=============" << std::endl;
    copy(customers2.begin(), customers2.end(), it); //reverse iterator
    std::cout << "=============" << std::endl;

    //delete
    //delete from customers2 c1
    std::cout << "delete from customers2 c1" << std::endl;
    customers2.erase(std::remove(customers2.begin(), customers2.end(), c1), customers2.end());
    printCustomers(customers2);

    //transform
    //reverse vector
    std::cout << "reverse vector" << std::endl;
    std::vector<Customer> customers3(customers);
    std::reverse(customers3.begin(), customers3.end());
    printCustomers(customers3);

    //sorting
    //sort customers3 by limit
    std::cout << "sort customers3 by limit" << std::endl;
    std::sort(customers3.begin(), customers3.end());
    printCustomers(customers3);


    //algorithms for ranges
    //print first element in collection that is > c3
    std::cout << "print first element in collection that is > c3" << std::endl;
    std::cout << *std::upper_bound(customers.begin(), customers.end(), c3) << std::endl;
    std::cout << "=============" << std::endl;

    std::cout << "=============" << std::endl;
    std::vector<Customer>::reverse_iterator rit = customers.rbegin(); //reverse iterator
    for (; rit!= customers.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    std::cout << "Predicat example: " << std::boolalpha << AccauntStateIsActive()(*customers.begin()) << std::endl;//predicat

    std::cout << "Functor example: " << c1.getLimit() << " -> "; //functor
    RaiseLimit()(&c1);
    std::cout <<  c1.getLimit() << std::endl;


    for_each (customers.begin(), customers.end(), isActive); // lambda
}

std::ostream& divider( std::ostream& os ) // manipulator
{
    return os << "===========\n";
}

void task2() {
    std::ifstream in (INPUT_FILE);

    std::vector<Customer> customers;
    std::vector<Customer> customersWithFatalError;
    std::vector<Customer> customersWithLogicalError;


    Customer tmp;
    for ( int i = 0; i < 5; i++ ) {
        try {
            in >> tmp;
        } catch (LogicalError e) {
            customersWithLogicalError.push_back(tmp);
            continue;
        } catch (std::exception &exception ) {
            customersWithFatalError.push_back(tmp);
            continue;
        }
        customers.push_back(tmp);
    }

    std::cout << "Customers:" << std::endl;
    printCustomers(customers);

    std::cout << "Customers With Logical Error:" << std::endl;
    printCustomers(customersWithLogicalError);

    std::cout << "Customers With Fatal Error:" << std::endl;
    printCustomers(customersWithFatalError);
}

int main() {
    task2();




    return 0;
}
