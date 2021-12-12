#ifndef DB_H
#define DB_H

#include "ui.h"
#include <bits/stdc++.h>
#include <cstdio>
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
    vector<Kota> kota;
    vector<vector<float>> data_jarak_kota;
    // Kota kota[100];

private:
    float pitagoras(float x1, float y1, float x2, float y2);
    void resizeVector2d(vector<vector<float>> vector, unsigned int size);
    void printPath(vector<int> path_temp, int dst);
    void dijkstra(int graph[100][100], int src, int dst);
    int cariJarakTerkecilDijkstra(vector<int> jarak_antar_node, vector<bool> sudah_dilewati, unsigned int src);
    bool cekHubungan(int src_pos, int dst_pos);

private:
    vector<int> jarak_antar_node;
    vector<bool> sudah_dilewati;
    vector<int> path_temp;
    // int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
    //                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //                    {0, 0, 4, 0, 10, 0, 2, 0, 0},
    //                    {0, 0, 0, 14, 0, 2, 0, 1, 6},
    //                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};

public:
    unsigned short int banyak_kota;
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
    void initDijkstra();
    void cariRute(string asal, string tujuan);
};

#endif