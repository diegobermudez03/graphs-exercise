#ifndef __SOCIAL_NETOWRK_H__
#define __SOCIAL_NETOWRK_H__

#include <vector>
#include <unordered_set>

#include "person.h"

class SocialNetwork{
    private:
        std::vector<Person*> persons;   //nodes
        std::vector<std::unordered_set<int>*> relations; //lines
    public:
        SocialNetwork();
        ~SocialNetwork();
        void addRelation(std::string& person1, std::string person2);
        void print();
};

#endif
