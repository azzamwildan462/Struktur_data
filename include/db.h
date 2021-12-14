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
    vector<vector<float>> data_jarak_kota;
    // Kota kota[100];

private:
    void resizeVector2d(vector<vector<float>> vector, unsigned int size);
    void printPath(vector<int> path_temp, int dst);
    void dijkstra(int graph[100][100], int src, int dst);
    int cariJarakTerkecilDijkstra(vector<int> jarak_antar_node, vector<bool> sudah_dilewati, unsigned int src);
    bool cekHubungan(int src_pos, int dst_pos);

private:
    vector<int> jarak_antar_node;
    vector<bool> sudah_dilewati;
    vector<int> path_temp;
    unsigned int iter_get;

public:
    unsigned short int banyak_kota;
    vector<Kota> kota;
    vector<int> data_hasil_dijkstra;

public:
    DB();
    UI *interface = UI::getInstance();
    string cariKotaTerdekatStr(string kota_yang_ingin_dicari);
    float pitagoras(float x1, float y1, float x2, float y2);
    int cariKotaTerdekat(string kota_yang_ingin_dicari);
    void show();
    void append(string nama_kota, int x, int y);
    void nyobakModular();
    int searchByName(string nama_kota);
    void connect1arah(string src, string dst);
    void connect2arah(string src, string dst);
    void simpanDataJarak(int pos);
    void initDijkstra();
    bool cariRute(string asal, string tujuan);
};

#endif