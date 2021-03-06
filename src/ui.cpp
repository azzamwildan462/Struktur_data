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
    printf("2. Hubungkan Kota\n");
    printf("3. Print graph\n");
    printf("4. Cari rute terpendek\n");
    printf("5. Tampilkan daftar kota\n");
    printf("6. Bersihkan layar\n");
}

void UI::execute(int input)
{
    if (input == 0xffff0030)
    {
        kill_command = "kill " + to_string(getpid()); // Membuat string dan mendapatkan PID program
        system(kill_command.c_str());                 // Menggunakan command linux untuk kill program berdasarkan PID nya
    }
    else if (input == 0xffff0031) // ketika input user adalah 1 maka status_eksekusi = 1
        status_eksekusi = 1;
    else if (input == 0xffff0032)
        status_eksekusi = 2;
    else if (input == 0xffff0033)
        status_eksekusi = 3;
    else if (input == 0xffff0034)
        status_eksekusi = 4;
    else if (input == 0xffff0035)
        status_eksekusi = 5;
    else if (input == 0xffff0036)
        system("clear");
    else
        status_eksekusi = 666;
}

void UI::getInput()
{
    int input = -1; // Reset input dari user

    printf("Pilihan: ");
    scanf("%s", &input); // Meminta inputan dari user
    execute(input);
}