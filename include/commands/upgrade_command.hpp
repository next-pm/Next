#pragma once
/**
 * @file upgrade_command.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

#include <command_base.hpp>
#include <next_data.hpp>
#include <tools/exec.hpp>

/**
 * @brief Comando para actualizar Next
 * 
 */
class UpgradeCommand : public CommandBase
{
private:
    /**Comando para realizar la actualizacion de Next*/
    std::string command;

public:
    /**
     * @brief Constructor
     * 
     */
    UpgradeCommand();

    /**
     * @brief Destructor
     * 
     */
    ~UpgradeCommand();

    /**
     * @brief Ejeucion del comando
     * 
     * @return int 
     */
    int execute();
};