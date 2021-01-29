#include <commands/create_project_command.hpp>

CreateProjectCommand::CreateProjectCommand(/* args */)
    : CommandBase()
{
}

CreateProjectCommand::~CreateProjectCommand()
{
}

CreateProjectCommand::CreateProjectCommand(std::string name_project)
    : name_project{name_project}, CommandBase()
{
}

int CreateProjectCommand::execute()
{

    std::string line;
    int status;
    line += "mkdir ";
    line += this->name_project;

    status = std::system(line.c_str());

    line.clear();

    line += "mkdir " + this->name_project + "/src " +
            this->name_project + "/build " +
            this->name_project + "/include " +
            this->name_project + "/test " +
            this->name_project + "/obj " +
            this->name_project + "/.next ";

    std::cout << line << '\n';

    status = std::system(line.c_str());

    line.clear();

    line += "cp " + NextData::getInstance()->path + "/assets/Makefile " + this->name_project;

    std::cout << line << '\n';

    status = std::system(line.c_str());

    line.clear();

    line += "cp " + NextData::getInstance()->path + "/assets/main " + this->name_project + "/src";

    std::cout << line << '\n';

    status = std::system(line.c_str());

    line.clear();

    line += "cp " + NextData::getInstance()->path + "/assets/CMakeLists.txt " + this->name_project;

    std::cout << line << '\n';

    status = std::system(line.c_str());

    line.clear();

    line += "mv " + this->name_project + "/src/main " + this->name_project + "/src/main.cpp";

    std::cout << line << '\n';

    status = std::system(line.c_str());

    std::cout << "\nCreate Proyect >> " << this->name_project << '\n';
    return 0;
}