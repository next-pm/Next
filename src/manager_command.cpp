#include <manager_command.hpp>

ManagerCommand::ManagerCommand(/* args */)
{
}

ManagerCommand::~ManagerCommand()
{
    this->stackCommand.clear();
}

void ManagerCommand::execute()
{

    this->stackCommand.execute();
}

void ManagerCommand::initialize(int argc, char const *argv[])
{

    if (argc < 2)
        return;

    for (int i = 1; i < argc; i++)
    {
        if (this->isFlag(argv[i]))
        {
            this->createFlag(argv[i]);
            continue;
        }

        if (this->isCommand(argv[i]))
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new CreateProjectCommand(argv[i+1]));
            this->stackCommand.append(new ReadHelpCommand());
        }
    }
}