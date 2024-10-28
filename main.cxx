#include <iostream>
#include <fstream>
#include <unordered_map>
#include "social_network.h"

SocialNetwork* readFile(std::string file_name);
void testFile(std::string file_name, SocialNetwork* socialNetwork);

int main(int argc, char **argsv){
    std::string file_name = "files/in02.txt";
    std::string test_name = "files/test02_02.txt";
    if(argc == 3){
        file_name = argsv[1];
        test_name = argsv[2];
    }
    SocialNetwork* social_network = readFile(file_name); 
    std::cout << social_network->visitWithDFS();
    testFile(test_name, social_network);
    delete social_network;
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
        file.close();
        return social_network;
    }catch(std::exception err){
        return nullptr;
    }
}

void testFile(std::string file_name, SocialNetwork* socialNetwork){
    std::ifstream test_file(file_name);
    std::ofstream output_file("resultado_test.txt");
    int number = 0;
    test_file >> number;
    output_file << number << "\n";
    std::unordered_map<std::string, int> already_done;
    for(int i = 0; i < number; i++){
        std::string person1;
        std::string person2;
        test_file >> person1;
        test_file >> person2;
        int pasos;
        if(already_done.find(person1 + person2) != already_done.end()){
            pasos = already_done.find(person1 + person2)->second;
        }else{
            pasos = socialNetwork->checkGradeDistance(person1, person2);
            already_done[person1 + person2] = pasos;
        }
        
        if(pasos > 0){
            output_file << person1 << " " << person2 << "   Cumple a " << pasos << " pasos\n";
        }
        else{
            output_file << person1 << " " << person2 << "     No Cumple\n";
        }
    }
    test_file.close();
    output_file.close();
}