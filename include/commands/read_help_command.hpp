#pragma once
/**
 * @file read_help_command.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <fstream>
#include <string>

#include <command_base.hpp>

#include <next_data.hpp>

/**
 * @brief Comado para leer el archivo de ayuda "help"
 * 
 */
class ReadHelpCommand : public CommandBase
{
private:
public:
    /**
     * @brief Constructor
     * 
     */
    ReadHelpCommand(/* args */);

    /**
     * @brief Destructor
     * 
     */
    ~ReadHelpCommand();

    /**
     * @brief Ejecucion del comando
     * 
     * @return int 
     */
    int execute();
};
