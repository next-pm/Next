#pragma once
/**
 * @file exec.hpp
 * @author Oswaldo Rafael Zamora Ramirez rafa.zamora.rals@gmail.com
 * @brief 
 * @version 2.0.0
 * @date 2021-02-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <fstream>
#include <iostream>

#if defined(_WIN32)

/**
 * @brief Funcion para ejecitar un comando directo de la cmd
 * 
 * @param command Comando a ejecutar
 * @return std::string Resultado de la ejecucion
 */
std::string exec(std::string command);

/**
 * @brief Funcion para ejecitar un comando directo de la cmd
 * 
 * @param command Comando a ejecutar
 */
void exec_void(std::string command);

#elif defined(__linux)

/**
 * @brief Funcion para ejecitar un comando directo de la terminal
 * 
 * @param command Comando a ejecutar
 * @return std::string Resultado de la ejecucion
 */
std::string exec(std::string command);

/**
 * @brief Funcion para ejecitar un comando directo de la terminal
 * 
 * @param command Comando a ejecutar
 */
void exec_void(std::string command);

#endif