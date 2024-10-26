#include <iostream>
#include <fstream>

#include "social_network.h"

int main(int argc, char **argsv){
    SocialNetwork* social_network = readFile("files/in01.txt"); 
    social_network->print();

}


SocialNetwork* readFile(std::string file_name){
    try{
        SocialNetwork* social_network = new SocialNetwork;
        std::ifstream file(file_name);
        int number = 0;
        file >> number;
        for(int i = 0; i < number; i++){
            std::string person1;
            std::string person2;
            file >> person1;
            file >> person2;
            social_network->addRelation(person1, person2);
        }
        return social_network;
    }catch(std::exception err){
        return nullptr;
    }
}