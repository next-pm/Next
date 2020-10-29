#include <commands/read_help_command.hpp>

ReadHelpCommand::ReadHelpCommand(/* args */) : CommandBase()
{
}

ReadHelpCommand::~ReadHelpCommand()
{
}

int ReadHelpCommand::execute(/* args */)
{
    
    std::string line;
    std::ifstream myfile("../assets/help");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else
    {
        std::cout << "Unable to open file";
        return -1;
    }

    return 0;
}