#ifndef UI_H
#define UI_H

#include <bits/stdc++.h>
#include <cstdio>
#include "unistd.h"

using namespace std;
class UI
{

private:
    string kill_command;
    string nama_kota;
    float x, y;
    // const char *kill;

private:
    void execute(int input);
    UI();

public:
    unsigned int status_eksekusi;

public:
    ~UI();
    void printChoice();
    static UI *getInstance(); // Design pattern Singleton

public:
    void getInput();
};

#endif