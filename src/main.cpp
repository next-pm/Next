#include <iostream>

#include <command_base.hpp>
#include <commands/read_help_command.hpp>

#include <manager_command.hpp>

#include <next_data.hpp>

int main(int argc, char const *argv[])
{
    ManagerCommand man;
    man.initialize(argc, argv);
    man.execute();
    std::cout<<NextData::getInstance()->path<<'\n';
    return 0;
}