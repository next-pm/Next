#pragma once
/**
 * @file path_command.hpp
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
#include <vector>

#include <command_base.hpp>

#include <next_data.hpp>

/**
 * @brief Comado que localiza la ruta en la que esta instalado Next
 * 
 */
class PathCommand : public CommandBase
{
private:
    /**
     * @brief COmado para obtener el PATH
     * 
     */
    std::string path_command;

    /**
     * @brief Separador de las varibles del PATH
     * 
     */
    char separator;

    /**
     * @brief Desplazamiento para elimiar la carpera build del PATH
     * 
     */
    std::size_t displacement;

public:
    /**
     * @brief Constructor
     * 
     */
    PathCommand(/* args */);

    /**
     * @brief Destructor
     * 
     */
    ~PathCommand();

    /**
     * @brief Ejecucion del Comando
     * 
     * @return int 
     */
    int execute();
};
