//
// Created by imolcean on 13.03.17.
//

#include <fstream>
#include <iostream>
#include "Snake.h"
#include "SMap.h"

Snake* snake;
SMap* map;

bool init(std::string mapName)
{
    // Open the map file and create a map object with it, then close the file
    std::ifstream mapFile("maps/" + mapName + ".smap");
    if(!mapFile.is_open())
    {
        std::cerr << "Map file could not be open" << std::endl;
        return false;
    }

    map = new SMap(mapFile);

    mapFile.close();

    // Create a Snake
    snake = new Snake(*map->getStart());

    // TODO Create GUI

    return true;
}

void fin()
{
    delete snake;
    delete map;
}

void processInput()
{
    // TODO Read the key states and change the direction of the Snake
    // like this

    snake->setDirection(SDirection::NONE);
}

void update()
{
    // TODO Move the snake
    // TODO Check validity
    // TODO Update the items (counters, spawn new ones, etc.)
}

void render()
{
    // TODO Render the map
    // TODO Render the snake
}

int main(int argc, char** argv)
{
    // TODO Read the name of the map
    std::string mapName;
    if(!init(mapName))
    {
        return -1;
    }

    bool done = false;

    while(!done)
    {
        // TODO
//        double start = getCurrentTime();
//
//        processInput();
//        update();
//        render();
//
//        sleep(start + FRAME_LENGTH - getCurrentTime());
    }

    fin();
    return 0;
}
