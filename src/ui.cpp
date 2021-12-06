#include "../include/ui.h"

UI *UI::getInstance()
{
    static UI instance;
    return &instance;
}
UI::UI()
{
    // init
}
UI::~UI()
{
    // destroy
}

void UI::printChoice()
{
    printf("Apa?\n");
    printf("1. iki pilihan 1\n");
    printf("2 iki pilihan 2\n");
    printf("3 iki pilihan 3\n");
    printf("4 iki pilihan 4\n");
}

void UI::execute(int input)
{
    switch (input)
    {
    case 0:
        printf("iki hasile 0\n");
        break;
    case 1:
        printf("iki hasile 1\n");
        break;
    case 2:
        printf("iki hasile 2\n");
        break;
    case 3:
        printf("iki hasile 3\n");
        break;
    case 4:
        printf("iki hasile 4\n");
        break;

    default:
        break;
    }
}

void UI::getInput()
{
    static int input = -1;

    printChoice();
    scanf("%d", &input);
    execute(input);
}