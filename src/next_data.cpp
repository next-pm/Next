#include <next_data.hpp>

/* Null, because instance will be initialized on demand. */
NextData* NextData::instance = NULL;

NextData* NextData::getInstance()
{
    if (instance == 0)
    {
        instance = new NextData();
    }

    return instance;
}

NextData::NextData()
{}