#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person{
    private:
        std::string name;
    public:
        Person(std::string name);
        ~Person();
        std::string getName();
};

#endif
