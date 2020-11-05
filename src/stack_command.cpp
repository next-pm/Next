#include <stack_command.hpp>

StackCommand::StackCommand(/* args */)
{
    this->stack_tasks.reserve(100);
}

StackCommand::~StackCommand()
{
}

void StackCommand::append(CommandBase * command)
{
    this->stack_tasks.push_back(command);
}

void StackCommand::undo(){

}

void StackCommand::clear(){

    this->stack_tasks.clear();
}

void StackCommand::execute(){
    
    for(auto* task : this->stack_tasks){
        task->execute();
    }
    
}