#include <commands/path_command.hpp>

#include <tools/exec.hpp>

#include <next_data.hpp>

#define NUM_VARS 50

PathCommand::PathCommand(/* args */) : CommandBase()
{
}

PathCommand::~PathCommand()
{
}

int PathCommand::execute(/* args */)
{
    int status;
    #if defined(_WIN32)
    std::string path_command = exec("PATH");
    #elif defined(__linux)
    std::string path_command = exec("echo $PATH");
    #endif
    std::vector<std::string> list_vars;
    list_vars.reserve(NUM_VARS);

    std::string line = "";

    if (path_command.find("Next") > path_command.size())
    {
        std::cout << "No se encontro Next en el Path" << '\n';
        return -1;
    }
#if defined(_WIN32)
    const char separator = ';';
#elif defined(__linux)
    const char separator = ':';
#endif

    for (char c : path_command)
    {
        if (c != separator)
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
#if defined(_WIN32)
            index -= 13;
            var.replace(index, 13, "");
#elif defined(__linux)
            index -= 6;
            var.replace(index, 6, "");
#endif
            //Hasta aca
            NextData::getInstance()->path = var;
            std::cout<<var<<'\n';
        }
        
    }

    return status;
}