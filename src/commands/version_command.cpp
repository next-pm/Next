#include <commands/version_command.hpp>

VersionCommand::VersionCommand(/* args */) : CommandBase()
{
}

VersionCommand::~VersionCommand()
{
}

int VersionCommand::execute(/* args */)
{
    
    std::string line;
    std::ifstream myfile("../assets/version");
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