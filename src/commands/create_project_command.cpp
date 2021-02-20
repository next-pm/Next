#include <commands/create_project_command.hpp>

CreateProjectCommand::CreateProjectCommand(/* args */)
  : CommandBase()
{}

CreateProjectCommand::~CreateProjectCommand() {}

CreateProjectCommand::CreateProjectCommand(std::string name_project)
  : name_project{ name_project }
  , CommandBase()
{
#if defined(_WIN32)
    this->dirs = { "",       "\\src", "\\build\\cmake", "\\include",
                   "\\test", "\\obj", "\\lib" };
    this->copy_commands.reserve(10);
    this->copy_commands.push_back("\\assets\\main " + this->name_project +
                                  this->dirs[1]);
    this->copy_commands.push_back("\\assets\\CMakeLists.txt " +
                                  this->name_project);
    this->copy_commands.push_back("\\assets\\test " + this->name_project +
                                  this->dirs[4]);
    this->move_commands.reserve(2);
    this->move_commands.push_back("\\src\\main " + this->name_project +
                                  "\\src\\main.cpp");
    this->move_commands.push_back("\\test\\test " + this->name_project +
                                  "\\test\\test.cpp");
#elif defined(__linux)
    this->dirs = { "",         "/src",  "/build", "/build/cmake",
                   "/include", "/test", "/obj",   "/lib" };
    this->copy_commands.reserve(10);
    this->copy_commands.push_back("/assets/main " + this->name_project +
                                  this->dirs[1]);
    this->copy_commands.push_back("/assets/CMakeLists.txt " +
                                  this->name_project);
    this->copy_commands.push_back("/assets/test " + this->name_project +
                                  this->dirs[5]);
    this->move_commands.reserve(2);
    this->move_commands.push_back("/src/main " + this->name_project +
                                  "/src/main.cpp");
    this->move_commands.push_back("/test/test " + this->name_project +
                                  "/test/test.cpp");
#endif
}

int
CreateProjectCommand::execute()
{

    std::string line;
    int status;

    this->createDirs();

    this->copyFiles();

    this->moveFiles();

    std::cout << "\nCreate Proyect >> " << this->name_project << '\n';
    return 0;
}

void
CreateProjectCommand::createDirs()
{
    std::string line;
    for (auto var : this->dirs) {
        line += "mkdir " + this->name_project + var;
        exec_void(line);
        line.clear();
    }
}

void
CreateProjectCommand::copyFiles()
{
    std::string line;
    for (auto var : this->copy_commands) {
        line += "cp " + NextData::getInstance()->path + var;
        exec_void(line);
        line.clear();
    }
}

void
CreateProjectCommand::moveFiles()
{
    std::string line;
    for (auto var : this->move_commands) {
        line += "mv " + this->name_project + var;
        exec_void(line);
        line.clear();
    }
}

MCreateProjectCommand::MCreateProjectCommand(/* args */)
  : CommandBase()
{}

MCreateProjectCommand::~MCreateProjectCommand() {}

MCreateProjectCommand::MCreateProjectCommand(std::string name_project)
  : name_project{ name_project }
  , CommandBase()
{
#if defined(_WIN32)
    this->dirs = { "",       "\\src", "\\build\\cmake", "\\include",
                   "\\test", "\\obj", "\\lib" };
    this->copy_commands.reserve(10);
    this->copy_commands.push_back("\\assets\\main " + this->name_project +
                                  this->dirs[1]);
    this->copy_commands.push_back("\\assets\\CMakeListsMoon.txt " +
                                  this->name_project);
    this->copy_commands.push_back("\\assets\\test " + this->name_project +
                                  this->dirs[4]);
    this->move_commands.reserve(5);
    this->move_commands.push_back("\\src\\main " + this->name_project +
                                  "\\src\\main.cpp");
    this->move_commands.push_back("\\test\\test " + this->name_project +
                                  "\\test\\test.cpp");
    this->move_commands.push_back("\\CMakeListsMoon.txt " + this->name_project +
                                  "\\CMakeLists.txt");
#elif defined(__linux)
    this->dirs = { "",         "/src",  "/build", "/build/cmake",
                   "/include", "/test", "/obj",   "/lib" };
    this->copy_commands.reserve(10);
    this->copy_commands.push_back("/assets/main " + this->name_project +
                                  this->dirs[1]);
    this->copy_commands.push_back("/assets/CMakeListsMoon.txt " +
                                  this->name_project);
    this->copy_commands.push_back("/assets/test " + this->name_project +
                                  this->dirs[5]);
    this->move_commands.reserve(5);
    this->move_commands.push_back("/src/main " + this->name_project +
                                  "/src/main.cpp");
    this->move_commands.push_back("/test/test " + this->name_project +
                                  "/test/test.cpp");
    this->move_commands.push_back("/CMakeListsMoon.txt " + this->name_project +
                                  "/CMakeLists.txt");
#endif
}

int
MCreateProjectCommand::execute()
{

    std::string line;
    int status;

    this->createDirs();

    this->copyFiles();

    this->moveFiles();

    std::cout << "\nCreate Proyect >> " << this->name_project << '\n';
    return 0;
}

void
MCreateProjectCommand::createDirs()
{
    std::string line;
    for (auto var : this->dirs) {
        line += "mkdir " + this->name_project + var;
        exec_void(line);
        line.clear();
    }
}

void
MCreateProjectCommand::copyFiles()
{
    std::string line;
    for (auto var : this->copy_commands) {
        line += "cp " + NextData::getInstance()->path + var;
        exec_void(line);
        line.clear();
    }
}

void
MCreateProjectCommand::moveFiles()
{
    std::string line;
    for (auto var : this->move_commands) {
        line += "mv " + this->name_project + var;
        exec_void(line);
        line.clear();
    }
}