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
//use refrence to refer to the vector in the main function instead of creating a copy
void Add( std::vector <Task>& tasks){
        Task newTasks;
        std::cout<< "enter new task"<<std::endl;
        std::getline(std::cin,newTasks.description);
        tasks.push_back(newTasks);
};  
void Edit( std::vector <Task>& tasks){
   
        std::cout<< "Select which task to edit. use #'s EX: 1, 2, 3..."<<std::endl;
        std::string input;
        std::getline(std::cin, input);
        


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

        for(std::size_t i = 0; i < tasks.size(); ++i){
                std::cout<< i+1 <<"." << tasks[i].description<<std::endl;
                
            }; 
        
        std::cout<<"To-Do List menu\n";
       
        std::cout<<"To add a task, type 'add'"<<std::endl;
        std::cout<<"To edit a task, type 'edit'"<<std::endl;
        std::cout<<"To quit, type 'quit'"<<std::endl;

        std::string choice;
        std::getline(std::cin, choice);

        if(tasks.empty()){
            //use size_t because it hold more byte wise and does not include anyting negative
            //best used when indexing arrays or vectors

            std::cout << "It seems you have no task, would like you to add some? If so, type add"<<std::endl;

        
        }else if(choice == "add"){
                std::cout<<"it works"<<std::endl;
                 Add(tasks);
            }else if(choice == "edit"){
                std::cout<<"edit works"<<std::endl;
            }else if(choice == "quit"){
            running = false;
        }

        
                
    }
    
    
    return 0;
}