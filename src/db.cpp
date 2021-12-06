#include "../include/db.h"

DB::DB()
{
    // vector<Kota> kota;
    banyak_kota = 0;
}

void DB::append(string nama_kota, int x, int y)
{
    banyak_kota++;
    kota.resize(banyak_kota);
    kota[banyak_kota - 1].nama = nama_kota;
    kota[banyak_kota - 1].x = x;
    kota[banyak_kota - 1].y = y;
    kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
    // printf("nama %s\n", nama_kota.c_str());

    // kota.resize(1);
    // kota[0].nama = nama_kota;
    // kota[0].x = x;
    // kota[0].y = y;
    // kota[0].tanda_akhir_hubungan_kota = -1;

    // Kota temp;
    // temp.nama = nama_kota;
    // temp.x = x;
    // temp.y = y;
    // temp.tanda_akhir_hubungan_kota = -1;
    // kota.push_back(temp);
}
void DB::nyobakModular()
{
    interface->tes_var = 123;
}

void DB::show()
{
    // printf("nama kota %s", kota[0].nama.c_str());
    // return;
    int panjang_nama = 0;
    int panjang_terdekat = 0;
    // header
    for (int i = 0; i < banyak_kota; i++)
    {
        // printf("panjang %d\n", kota[i].nama.size());
        // if (kota[i].nama.size() < 0x8)
        //     panjang_nama = 0;
        if (kota[i].nama.size() >= 0x8)
            panjang_nama = 1;
        // printf("panjang nama %d\n", panjang_nama);
        if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
            panjang_terdekat = 0;
        else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
            panjang_terdekat = 1;
    }

    if (panjang_nama == 0)
        printf("Nama \t");
    else if (panjang_nama == 1)
        printf("Nama \t\t");

    printf("X\t");

    printf("Y\t");

    if (panjang_terdekat = 0)
        printf("Terdekat");
    else if (panjang_terdekat = 1)
        printf("Terdekat\t");

    printf("Hubungan ");

    printf("\n");

    // isi
    for (int i = 0; i < banyak_kota; i++)
    {
        // printf("iter-%d\t", i); // untuk debug index
        if (kota[i].nama.size() < 0x8)
            cout << kota[i].nama << "\t\t";
        else if (kota[i].nama.size() >= 0x8)
            cout << kota[i].nama << "\t";

        cout << kota[i].x << "\t";

        cout << kota[i].y << "\t";

        if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
            cout << cariKotaTerdekatStr(kota[i].nama) << "\t\t";
        else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
            cout << cariKotaTerdekatStr(kota[i].nama) << "\t";
        // cout << cariKotaTerdekatStr(kota[i].nama) << " ";

        if (kota[i].tanda_akhir_hubungan_kota == -1)
            printf("- ");
        else
        {
            for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
            {
                cout << kota[kota[i].hubungan_kota[v]].nama << ", ";
                // cout << kota[i].hubungan_kota[v] << ", ";
            }
            cout << kota[kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota]].nama << " ";
            // cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
        }
        cout << endl;
    }
}

float DB::pitagoras(float x1, float y1, float x2, float y2)
{

    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

string DB::cariKotaTerdekatStr(string kota_yang_ingin_dicari)
{
    return kota[cariKotaTerdekat(kota_yang_ingin_dicari)].nama;
}

int DB::searchByName(string nama_kota)
{
    for (int i = 0; i < banyak_kota; i++)
    {
        if (nama_kota == kota[i].nama)
        {
            return i;
        }
    }
    // kalo sampek sini berarti kota gk ditemukan
    //  printf("kota gk ditemukan\n");
    return -1;
}
int DB::cariKotaTerdekat(string kota_yang_ingin_dicari)
{
    int pos = searchByName(kota_yang_ingin_dicari);
    float min = 9999999999;
    int min_pos = pos;
    for (int i = 0; i < banyak_kota; i++)
    {
        if (i != pos)
        {
            // printf("min: %f ", min);
            // printf("jarak %s: %f\n", kota[i].nama.c_str(), pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y));
            if (min >= pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y))
            {
                min = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
                min_pos = i;
            }
        }
    }
    return min_pos;
}
void DB::connect1arah(string src, string dst)
{
    int src_pos = searchByName(src);
    int dst_pos = searchByName(dst);
    if (src_pos >= 0 && dst_pos >= 0)
    {
        kota[src_pos].tanda_akhir_hubungan_kota++;
        kota[src_pos].hubungan_kota.resize(kota[src_pos].tanda_akhir_hubungan_kota + 1);
        kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
    }
    else
        printf("Invalid name\n");
}
void DB::connect2arah(string src, string dst)
{
    int src_pos = searchByName(src);
    int dst_pos = searchByName(dst);
    if (src_pos >= 0 && dst_pos >= 0)
    {
        kota[dst_pos].tanda_akhir_hubungan_kota++;
        kota[dst_pos].hubungan_kota.resize(kota[dst_pos].tanda_akhir_hubungan_kota + 1);
        kota[dst_pos].hubungan_kota[kota[dst_pos].tanda_akhir_hubungan_kota] = src_pos;

        kota[src_pos].tanda_akhir_hubungan_kota++;
        kota[src_pos].hubungan_kota.resize(kota[src_pos].tanda_akhir_hubungan_kota + 1);
        kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
    }
    else
        printf("Invalid name\n");
}

void DB::simpanDataJarak(int pos)
{
    for (int i = 0; i < banyak_kota; i++)
    {
        // data_jarak_kota.resize()
        data_jarak_kota[i][pos] = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
    }
}

void DB::dijkstra()
{
    // nggawe data jarak sek
    for (int i = 0; i < banyak_kota; i++)
    {
        simpanDataJarak(i);
    }

    // for (int i = 0; i < banyak_kota; i++) //testing
    // {
    //     for (int j = 0; j < banyak_kota; j++)
    //     {
    //         printf("%.02f ", data_jarak_kota[i][j]);
    //     }
    //     printf("\n");
    // }
}