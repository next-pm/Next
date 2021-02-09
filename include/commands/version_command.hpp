#pragma once
/**
 * @file version_command.hpp
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
 * @brief COmado para mostrar la version de Next
 * 
 */
class VersionCommand : public CommandBase
{
private:
    /* data */
public:
    /**
     * @brief Constructor
     * 
     */
    VersionCommand(/* args */);

    /**
     * @brief Destuctor
     * 
     */
    ~VersionCommand();

    /**
     * @brief Ejecucion del comando
     * 
     * @return int 
     */
    int execute();
};
