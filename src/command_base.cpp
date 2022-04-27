#include <command_base.hpp>

#define NUM_ARGS 10

CommandBase::CommandBase(/* args */)
{
}

CommandBase::~CommandBase()
{
}

CommandBase_State::CommandBase_State(){
    this->args.reserve(NUM_ARGS);
}

CommandBase_State::~CommandBase_State(){

}

