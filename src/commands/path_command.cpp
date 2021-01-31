#include <commands/path_command.hpp>

#include <tools/exec.hpp>

#include <next_data.hpp>

#define NUM_VARS 50

PathCommand::PathCommand(/* args */) : CommandBase()
{
#if defined(_WIN32)
    this->path_command = exec("PATH");
    this->separator = ';';
    this->displacement = 13;
#elif defined(__linux)
    this->path_command = exec("echo $PATH");
    this->separator = ';';
    this->displacement = 6;
#endif
}

PathCommand::~PathCommand()
{
}

int PathCommand::execute(/* args */)
{
    int status;
    std::vector<std::string> list_vars;
    list_vars.reserve(NUM_VARS);

    std::string line = "";

    if (this->path_command.find("Next") > this->path_command.size())
    {
        std::cout << "No se encontro Next en el Path" << '\n';
        return -1;
    }
    for (char c : this->path_command)
    {
        if (c != this->separator)
        {
            line += c;
        }
        else
        {
            list_vars.push_back(line);
            line.clear();
        }
    }

    list_vars.push_back(line);
    line.clear();

    for (auto var : list_vars)
    {
        if(var.find("Next") < var.size()){
            //Esto esta absolutamente mal, es para quitar '/bin' del PATH 
            std::size_t index = var.size();
            index -= this->displacement;
            var.replace(index, this->displacement, "");
            //Hasta aca
            NextData::getInstance()->path = var;
            std::cout<<var<<'\n';
        }
        
    }

    return status;
}