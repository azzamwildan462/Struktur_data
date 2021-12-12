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

void UI::printChoice() // Mem-print menu yang bisa digunakan
{
    printf("Menu: \n");
    printf("0. Exit\n");
    printf("1. Tambah Kota\n");
    printf("2 Hubungkan Kota\n");
    printf("3 Print graph\n");
    printf("4 Cari rute terpendek\n");
    printf("5 Tampilkan daftar kota\n");
}

void UI::execute(int input)
{
    switch (input)
    {
    case 0:
        kill_command = "kill " + to_string(getpid()); // Membuat string dan mendapatkan PID program
        system(kill_command.c_str());                 // Menggunakan command linux untuk kill program berdasarkan PID nya
        break;
    case 1:
        status_eksekusi = 1;
        break;
    case 2:
        status_eksekusi = 2;
        break;
    case 3:
        status_eksekusi = 3;
        break;
    case 4:
        status_eksekusi = 4;
        break;
    case 5:
        status_eksekusi = 5;
        break;

    default:
        printChoice();
        break;
    }
}

void UI::getInput()
{
    static int input = -1;

    printf("Pilihan: ");
    scanf("%d", &input); // Meminta inputan dari user
    execute(input);
}