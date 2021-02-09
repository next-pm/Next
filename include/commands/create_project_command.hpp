#pragma once
/**
 * @file create_project_command.hpp
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
 * @brief Comando para la creacion de un nuevo Proyecto de Next
 * 
 */
class CreateProjectCommand : public CommandBase
{
private:
    /**Nombre del proyecto*/
    std::string name_project = "";

    /**DIrectorios que se deben crear*/
    std::vector<std::string> dirs;

    /**Archivos qu se deben copiar*/
    std::vector<std::string> copy_commands;

    /**Archivos que se deben mover*/
    std::vector<std::string> move_commands;

public:
    /**
     * @brief Constructor vacio
     * 
     */
    CreateProjectCommand(/* args */);

    /**
     * @brief Constructor
     * 
     * @param name_project 
     */
    CreateProjectCommand(std::string name_project);

    /**
     * @brief Destructor
     * 
     */
    ~CreateProjectCommand();

    /**
     * @brief Ejecucion del comando
     * 
     * @return int 
     */
    int execute();

    /**
     * @brief Crea los directorios
     * 
     */
    void createDirs();

    /**
     * @brief Copia los archivos
     * 
     */
    void copyFiles();

    /**
     * @brief Mueve los archivos
     * 
     */
    void moveFiles();
};