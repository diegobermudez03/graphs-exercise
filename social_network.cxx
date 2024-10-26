#include "social_network.h"

SocialNetwork::SocialNetwork(){
}

SocialNetwork::~SocialNetwork(){
    std::vector<Person*>::iterator it = this->persons.begin();
    for(; it != this->persons.end(); ++it){
        delete *it;
    }
    std::vector<std::unordered_set<int>*>::iterator it2  = this->relations.begin();
    for(; it2 != this->relations.end(); ++it2){
        delete *it2;
    }
}

void SocialNetwork::addRelation(std::string& person1, std::string person2){
    int index_person1 = -1;
    int index_person2 = -1;

    //get indexes of persons if already exist
    std::vector<Person*>::iterator it = this->persons.begin();
    for(int i = 0; it != this->persons.end(); ++it, i++){
        if((*it)->getName() == person1) index_person1 = i;
        else if((*it)->getName() == person2) index_person2 = i;
        if(index_person1 != -1 && index_person2 != -1) break;
    }
    //if any of them two dont exist, then create them
    if(index_person1 == -1){
        this->persons.push_back(new Person(person1));
        index_person1 = this->persons.size()-1;
    }
    if(index_person2 == -1){
        this->persons.push_back(new Person(person2));
        index_person2= this->persons.size()-1;
    }

    //at this point we have the indexes for sure, so we can create the relation
    this->relations[index_person1]->insert(index_person2);
}

void SocialNetwork::print(){

}