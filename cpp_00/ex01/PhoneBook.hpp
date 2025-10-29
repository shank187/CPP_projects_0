#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
    Contact contacts[8];
    int size;
public:
    void addContact();
    void searchContact();
    void displayInfos(int index);
    Phonebook();
    ~Phonebook();
};
 
#endif
