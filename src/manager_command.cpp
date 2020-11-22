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
        else
        {
            list_args += " " + line;
        }

        /*
        if (this->isCommand(argv[i]))
        {
            std::string line = argv[i];
            if (line == "create")
            {
                this->stackCommand.append(new PathCommand());
                this->stackCommand.append(new CreateProjectCommand(argv[i + 1]));
                this->stackCommand.append(new ReadHelpCommand());
            }
            if (line == "run")
            {
                this->stackCommand.append(new PathCommand());
                this->stackCommand.append(new RunCommand());
            }
            if (line == "build")
            {
                this->stackCommand.append(new PathCommand());
                this->stackCommand.append(new BuildCommand());
            }
        }
*/
    }
    this->stackCommand.append(new PathCommand());
    this->stackCommand.append(new MakeCommand(list_args));
}