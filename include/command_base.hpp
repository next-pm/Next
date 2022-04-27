#pragma once
/**
 * @file command_base.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <vector>
#include <memory>

/**
 * @brief Es la Clase de la que heredantodos los Comandos de Next
 * 
 */
class CommandBase
{
public:
    /**
     * @brief Construsctor vacio de un Comando
     * 
     */
    CommandBase(/* args */);

    /**
     * @brief Destructor de Comando
     * 
     */
    virtual ~CommandBase() = 0;

    /**
     * @brief Metodo en donde se realiza la tarea del comando
     * 
     * @return int Estatus de devolucion del comando
     */
    virtual int execute() = 0;
};