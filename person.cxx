#include "person.h"

Person::Person(std::string name){
    this->name = name;
}

Person::~Person(){}

std::string Person::getName(){
    return this->name;
}