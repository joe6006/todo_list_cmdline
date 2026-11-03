#include <iostream>
#include <string>
#include <vector>
//create a struct to call task, we use this instead of a class
//because its public and a class is private
struct Task{
    //store description
    std::string date;
    std::string description;
    bool completed =false;

};


int main(){
    //create a vector to hold multiple task and its resizable

    std::vector<Task> tasks;

    //Task initiates the struct to create a variable called example
    //use .description to call the string description
    Task example; 
    example.description = "learn cpp\n";
    //push to vector tasks
    tasks.push_back(example);
    std::cout<<tasks[0].description;

    bool running = true;
    while(running){
        std::cout<<"To-Do List menu\n";
        std::cout<<"To view tasks type 'view'"<<std::endl;
        std::cout<<"To quit, type 'quit'"<<std::endl;

        std::string choice;
        std::getline(std::cin, choice);
        
        if(choice == "view"){
            //use size_t because it hold more byte wise and does not include anyting negative
            //best used when indexing arrays or vectors
            
            for(std::size_t i = 0; i < tasks.size(); ++i){
                std::cout<< i+1 <<"." << tasks[i].description<<std::endl;
                
            }       
        
        }else if(choice == "quit"){
            running = false;
        }

    }

    return 0;
}