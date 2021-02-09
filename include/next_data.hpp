#pragma once
/**
 * @file next_data.hpp
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

/**
 * @brief Clase que almacena los datos necesarios para el uso de Next por ejemplo 7
 *        La ubicacion en el sistema donde esta instalado Next
 * 
 */
class NextData
{
private:
    /* Here will be the instance stored. */
    static NextData *instance;

    /* Private constructor to prevent instancing. */
    NextData();

public:
    /* Static access method. */
    static NextData *getInstance();
    std::string path = "";
};