#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "main_lib.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "pthread.h"

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
    void graph(bool dijkstra = 0);

    // SFMLLLLLL
private:
    void gambarHubungan(int x1, int y1, int x2, int y2);
    float findDirection(float xpos, float ypos, float xtarget, float ytarget);
    void gambarKota();
    bool termasukJalur(int src, int dst);
    // Vertex drawLine(int x1, int y1, int x2, int y2);

private:
    sf::RenderWindow window;
    sf::Event event_handler;
    sf::Font font;
    vector<int> dijkstra_buffer;
    float x_offset = 400;
    float y_offset = 300;
    int x_window = 1024;
    int y_window = 768;
};

#endif