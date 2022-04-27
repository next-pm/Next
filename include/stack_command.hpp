#pragma once
/**
 * @file stack_command.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>

#include <command_base.hpp>

/**
 * @brief Clase que almacena los Comandos a realizar
 * 
 */
class StackCommand
{
public:
    /**
     * @brief Vector de los comandos
     * 
     */
    std::vector<CommandBase *> stack_tasks;

    /**
     * @brief Constructor vacio
     * 
     */
    StackCommand(/* args */);

    /**
     * @brief Destructor 
     * 
     */
    ~StackCommand();

    /**
     * @brief Metod para añadir un nuevo Comando
     * 
     */
    void append(CommandBase *);

    /**
     * @brief Metodo para eliminar un comando
     * 
     */
    void undo();

    /**
     * @brief Metodo para borrar todos los comandos
     * 
     */
    void clear();

    /**
     * @brief Metodo para ejecutar los comandos almacenados
     * 
     */
    void execute();
};
