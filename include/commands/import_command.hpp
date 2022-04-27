#pragma once
/**
 * @file import_command.hpp
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
 * @brief Comado para clonar e importar otro proyecto de Next como una biblioteca
 * 
 */
class ImportCommand : public CommandBase
{
private:
    /**Comado a realizar para clonar el repositorio de Git*/
    std::string command;

public:
    /**
     * @brief Constructor
     * 
     * @param url_repo link del repositorio a clonar
     */
    ImportCommand(std::string url_repo);

    /**
     * @brief Destructor
     * 
     */
    ~ImportCommand();

    /**
     * @brief Ejecucion del comando
     * 
     * @return int 
     */
    int execute();
};