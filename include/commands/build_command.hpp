#pragma once
/**
 * @file build_command.hpp
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
 * @brief Comado para compilar y enlazar un proyecto de Next
 * 
 */
class BuildCommand : public CommandBase
{
private:
    /**
     * @brief Comando que se debe realizar, en la version actual se usa CMake
     * 
     */
    std::string command;

public:
    /**
     * @brief Constructor
     * 
     */
    BuildCommand(/* args */);

    /**
     * @brief Destructor
     * 
     */
    ~BuildCommand();

    /**
     * @brief Metodo de la ejecucion del comando
     * 
     * @return int Estatus de ejecución
     */
    int execute();
};