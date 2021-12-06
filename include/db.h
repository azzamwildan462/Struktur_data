#ifndef DB_H
#define DB_H

#include "ui.h"
#include <bits/stdc++.h>
// #include <vector>

using namespace std;

class DB
{
private:
    typedef struct Kota
    {
        string nama;
        int x;
        int y;
        vector<int> hubungan_kota;
        int tanda_akhir_hubungan_kota;
    } Kota;
    unsigned short int banyak_kota;
    vector<Kota> kota;
    vector<vector<float>> data_jarak_kota;
    // Kota kota[100];

private:
    float pitagoras(float x1, float y1, float x2, float y2);

public:
    UI *interface = UI::getInstance();
    DB();
    string cariKotaTerdekatStr(string kota_yang_ingin_dicari);
    int cariKotaTerdekat(string kota_yang_ingin_dicari);
    void show();
    void append(string nama_kota, int x, int y);
    void nyobakModular();
    int searchByName(string nama_kota);
    void connect1arah(string src, string dst);
    void connect2arah(string src, string dst);
    void simpanDataJarak(int pos);
    void dijkstra();
};

#endif