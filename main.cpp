#include <iostream>
#include <string>
#include <vector>
//create a struct to call task, we use this instead of a class
//because its public and a class is private
struct Task{
    //store description
    
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

//edit the information in tasks.description
void Edit( std::vector <Task>& tasks){
   
        std::cout<< "Select which task to edit. use #'s EX: 1, 2, 3..."<<std::endl;
        std::string input;
        std::getline(std::cin, input);

        //using a try and catch to verify the input string is the correct size and type
        //this also catches any errors on input if there are
        //any extra characters
        //we use & to create to refer to only the item that it is checking instead of creating a copy 
        //if you use it without a "&" it creates what you call a memory slice which it creates
        //its own copy instead of refer to  the object at hand
        //this also means that when using "&" we can save space and make it slightly faster. 

        //PSA:: intialize the int or whatever type outside the TRY or else it won't be global
            int num;

        try{
            num =std::stoi(input);
            std::cout<<num<<std::endl;
        }
        catch(const std::invalid_argument& e){
            std::cerr << "Invalid input: Not a number. \n";
            return;

        }
        catch(const std::out_of_range& e){
            std::cerr << "overflow: number is too large for an int. \n";
            return;
        };


        num--;

        
        std::cout<<"current tasks description:"<<std::endl;
        std::cout<<tasks[num].description<<std::endl;
        std::cout<<"New description: "<<std::endl;
        std::getline(std::cin, tasks[num].description);
        std::cout<<"Success"<<std::endl;
         

};  

void Delete(std::vector <Task>& tasks){
    //same concept as edit but we use .erase to delete the users
    //wanted description
         std::cout<< "Select which task to delete. use #'s EX: 1, 2, 3..."<<std::endl;
        std::string input;
        std::getline(std::cin, input);

     
            int num;

        try{
            num =std::stoi(input);
            std::cout<<num<<std::endl;
        }
        catch(const std::invalid_argument& e){
            std::cerr << "Invalid input: Not a number. \n";
            return;

        }
        catch(const std::out_of_range& e){
            std::cerr << "overflow: number is too large for an int. \n";
            return;
        };      
        num--;

        tasks.erase(tasks.begin() + num);


};



int main(){
    //create a vector to hold multiple task and its resizable

    std::vector<Task> tasks;

    //Task initiates the struct to create a variable called example
    //use .description to call the string description

    bool running = true;
    while(running){
        std::cout<<"\n";
        for(std::size_t i = 0; i < tasks.size(); ++i){
            
                std::cout<< i+1 <<"." << tasks[i].description<<std::endl;
                
            }; 
        std::cout<<"\n";
        std::cout<<"To-Do List menu\n";
       
        std::cout<<"To add a task, type 'add'"<<std::endl;
        std::cout<<"To edit a task, type 'edit'"<<std::endl;
        std::cout<<"To delete a task, type 'delete'"<<std::endl;
        std::cout<<"To quit, type 'quit'"<<std::endl;

        std::string choice;
        std::getline(std::cin, choice);

        if(choice == "add"){                
                 Add(tasks);
            }else if(choice == "edit"){
                Edit(tasks);
            }else if(choice == "quit"){
            running = false;
        }else if( choice == "delete"){
            Delete(tasks);
        }

        
                
    }
    
    
    return 0;
}