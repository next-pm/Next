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

    std::string list_args;
    list_args.reserve(100);

    if (argc < 2)
        return;

    for (int i = 1; i < argc; i++)
    {
        std::string line = argv[i];
        if (this->isFlag(argv[i]))
        {
            this->createFlag(argv[i]);
            continue;
        }
        else if (line == "create")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new CreateProjectCommand(argv[i + 1]));
            this->stackCommand.append(new ReadHelpCommand());
        }
        else if (line == "build")
        {
            this->stackCommand.append(new BuildCommand());
        }
        else if (line == "run")
        {
            this->stackCommand.append(new RunCommand());
        }
        else if (line == "import" || line == "i")
        {
            this->stackCommand.append(new ImportCommand(argv[i + 1]));
        }
        else if (line == "upgrade" || line == "u")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new UpgradeCommand());
            this->stackCommand.append(new VersionCommand());
        }
        else
        {
            list_args += " " + line;
        }
    }
}