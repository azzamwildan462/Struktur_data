#ifndef UI_H
#define UI_H

#include <cstdio>

class UI
{
private:
    void printChoice();
    void execute(int input);
    UI();

public:
    int tes_var;
    ~UI();
    static UI *getInstance(); // Design pattern Singleton

public:
    void getInput();
};

#endif