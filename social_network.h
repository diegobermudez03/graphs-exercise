#ifndef __SOCIAL_NETOWRK_H__
#define __SOCIAL_NETOWRK_H__

#include <vector>
#include <unordered_set>

#include "person.h"

class SocialNetwork{
    private:
        std::vector<Person*> persons;   //nodes
        std::vector<std::unordered_set<int>*> relations; //lines

        std::string recursiveDFS(int i, std::unordered_set<int>& visited, std::string previous_string);
        int getIndexOf(std::string& name);
    public:
        SocialNetwork();
        ~SocialNetwork();
        void addRelation(std::string& person1, std::string person2);
        std::string visitWithDFS();
        int checkGradeDistance(std::string& from, std::string& to);     //returns the grade of distance
};

#endif
