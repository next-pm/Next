#pragma once
/**
 * @file manager_command.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>

/**Estructura donde se almacenan los comandos a realizar*/
#include <stack_command.hpp>

/**Comandos que se pueden realizar*/
#include <commands/read_help_command.hpp>
#include <commands/version_command.hpp>
#include <commands/path_command.hpp>
#include <commands/create_project_command.hpp>
#include <commands/build_command.hpp>
#include <commands/run_command.hpp>
#include <commands/import_command.hpp>
#include <commands/upgrade_command.hpp>

/**
 * @brief Manager que controla la creacion y ejecucion de los comandos
 * 
 */
class ManagerCommand
{
private:
    /**
     * @brief Estructura de datos que almacena a los comandos
     * 
     */
    StackCommand stackCommand;

public:
    /**
     * @brief Constructor vacio del Manager
     * 
     */
    ManagerCommand(/* args */);

    /**
     * @brief Destructor de ManagerCommand
     * 
     */
    ~ManagerCommand();

    /**
     * @brief Metodo en el que se ejecuta los comandos
     * 
     */
    void execute();

    /**
     * @brief Metodo de inicializacion del Manager, aqui se crean los comandos
     * 
     * @param argc Numero de argumantos de la linea de comandos
     * @param argv Argumentos de la linea de comandos
     */
    void initialize(int argc, char const *argv[]);

    /**
     * @brief Metodo que evalua si un argumento es una bandera
     * 
     * @param arg Argumento a evaluar
     * @return true 
     * @return false 
     */
    constexpr bool isFlag(char const *arg)
    {
        return arg[0] == '-';
    }

    /**
     * @brief Metodo responsable de la creacion de los comandos correspondientes a las 
     *        Banderas
     * 
     * @param arg 
     */
    void createFlag(char const *arg)
    {
        if (std::string(arg) == "--help" || std::string(arg) == "-h")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new ReadHelpCommand());
        }
        if (std::string(arg) == "--version" || std::string(arg) == "-v")
        {
            this->stackCommand.append(new PathCommand());
            this->stackCommand.append(new VersionCommand());
        }

        if (std::string(arg) == "--path" || std::string(arg) == "-p")
        {
            this->stackCommand.append(new PathCommand());
        }
    }
};
