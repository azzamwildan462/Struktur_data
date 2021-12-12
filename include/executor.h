#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "main_lib.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

// UI *interface = UI::getInstance();

using namespace sf;

class Executor
{

private:
    DB *Database;

public:
    Executor(DB *Database);
    void eksekusi();
    void tambahKota();
    void hubungkanKota();
    void cariRute();
    void graph();

    // SFMLLLLLL!!!!
private:
    void gambarHubungan(int x1, int y1, int x2, int y2);
    void gambarKota();
    // Vertex drawLine(int x1, int y1, int x2, int y2);

private:
    sf::RenderWindow window;
    sf::Event event_handler;
    // sf::Font font;
    float x_offset = 400;
    float y_offset = 300;
};

#endif