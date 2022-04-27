#pragma once

#include <iostream>
#include <string>

class NextData
{
    private:
        /* Here will be the instance stored. */
        static NextData* instance;

        /* Private constructor to prevent instancing. */
        NextData();

    public:
        /* Static access method. */
        static NextData* getInstance();
        std::string path = "";
};