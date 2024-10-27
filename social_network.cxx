#include "social_network.h"

#include <unordered_set>
#include <queue>
#include "tuple_2.h"

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
        this->relations.push_back(new std::unordered_set<int>);
        index_person1 = this->persons.size()-1;
    }
    if(index_person2 == -1){
        this->persons.push_back(new Person(person2));
        this->relations.push_back(new std::unordered_set<int>);
        index_person2= this->persons.size()-1;
    }

    //at this point we have the indexes for sure, so we can create the relation
    this->relations[index_person1]->insert(index_person2);
    this->relations[index_person2]->insert(index_person1);
}

std::string SocialNetwork::visitWithDFS(){
    if(this->persons.empty()) return "";

    std::unordered_set<int> visited;
    return recursiveDFS(0, visited, "");
}

std::string SocialNetwork::recursiveDFS(int i, std::unordered_set<int>& visited, std::string previous_string){
    //printing us stating that they are visiting us
    std::string returning = previous_string + "\n" + this->persons[i]->getName();
    visited.insert(i);
    
    //visit our sons and recurisve call
    std::unordered_set<int>::iterator it = this->relations[i]->begin();
    for(; it != this->relations[i]->end(); ++it){
        //this condition means, if this son is not visited already
        if(visited.find(*it) == visited.end()){
            returning = recursiveDFS(*it, visited, returning);
        }
    }

    return returning;
}

int SocialNetwork::checkGradeDistance(std::string& from, std::string& to){
    int from_index = this->getIndexOf(from);
    int to_index = this->getIndexOf(to);

    if(from_index == -1 || to_index == -1) return -1;   //which means, one of the persons ot both of them dont exist

    std::queue<Tuple2<int,int>> bfs_queue;      //where the tuples are <level of distance, index of the person>
    bfs_queue.push(Tuple2<int, int>(0,from_index)); //we add the first item with distance of 0, the from person itself

    while(!bfs_queue.empty()){
        Tuple2<int, int> current_person = bfs_queue.front();
        bfs_queue.pop();
        int neighbors_distance = current_person.getValue1() + 1;    //the distance of this neighbors is the distance of the previous + 1
        if(neighbors_distance == 7) break; //if we reached distance 7, then we break, it doesn't fullfills the check
        
        std::unordered_set<int>* neighbors = this->relations[current_person.getValue2()];
        std::unordered_set<int>::iterator it = neighbors->begin();
        for(; it != neighbors->end(); ++it){
            if(*it == to_index){
                return neighbors_distance;
            }else{
                bfs_queue.push(Tuple2<int, int>(neighbors_distance, *it));
            }
        }
    }
    //if it reaches here, means that there are no connections less than 6 between those persons
    return -1;
}

int SocialNetwork::getIndexOf(std::string& name){
    std::vector<Person*>::iterator it = this->persons.begin();
    for(int i = 0; it != this->persons.end(); ++it, i++){
        if((*it)->getName() == name) return i;
    }
    return -1;
}
