#include "../include/db.h"

DB::DB()
{
    // vector<Kota> kota;
    banyak_kota = 0; // inisialisasi awal banyak kota adalah 0
}

void DB::append(string nama_kota, int x, int y)
{
    if (searchByName(nama_kota) >= 0)
    {
        printf("Error: Nama kota sudah ada yang pakai\n");
        return;
    }
    if (abs(y) + 384 >= 768)
    {
        printf("Error: koordinat_y keluar batas window");
        return;
    }
    if (abs(x) + 512 >= 1024)
    {
        printf("Error: koordinat_x keluar batas window");
        return;
    }
    banyak_kota++;                          // menambahkan banyak kota
    kota.resize(banyak_kota);               // me-resize vector kota
    kota[banyak_kota - 1].nama = nama_kota; // proses inisialisai kota
    kota[banyak_kota - 1].x = x;
    kota[banyak_kota - 1].y = y;
    kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
}
void DB::nyobakModular()
{
    // interface->tes_var = 123;
}

void DB::show()
{
    int panjang_nama = 0;
    int panjang_terdekat = 0;
    // header
    for (int i = 0; i < banyak_kota; i++) // pre-proses untuk merapikan tabel jika ada nama kota yang panjang
    {
        if (kota[i].nama.size() >= 0x8)
            panjang_nama = 1;
        if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
            panjang_terdekat = 0;
        else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
            panjang_terdekat = 1;
    }

    // Print header tabel
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
    // End print header tabel

    // Print isi tabel (Database kota kota)
    for (int i = 0; i < banyak_kota; i++)
    {
        // printf("iter-%d\t", i); // untuk debug index
        if (kota[i].nama.size() < 0x8)
        {
            if (panjang_nama == 1)
                cout << kota[i].nama << "\t\t";
            else if (panjang_nama == 0)
                cout << kota[i].nama << "\t";
        }
        else if (kota[i].nama.size() >= 0x8)
            cout << kota[i].nama << "\t";

        cout << kota[i].x << "\t";

        cout << kota[i].y << "\t";

        if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
            cout << cariKotaTerdekatStr(kota[i].nama) << "\t\t";
        else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
            cout << cariKotaTerdekatStr(kota[i].nama) << "\t";

        if (kota[i].tanda_akhir_hubungan_kota == -1)
            printf("- ");
        else
        {
            for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
            {
                cout << kota[i].hubungan_kota[v] << ", ";
            }
            cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
        }
        cout << endl;
    }
}

void DB::resizeVector2d(vector<vector<float>> vector, unsigned int size)
{
    printf("size %d", size);
    vector.resize(size);
    for (int i = 0; i < size; ++i)
        vector[i].resize(size);
}

float DB::pitagoras(float x1, float y1, float x2, float y2)
{
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))); // Menggunakan rumus pitagoras untuk cari jarak
}

string DB::cariKotaTerdekatStr(string kota_yang_ingin_dicari)
{
    return kota[cariKotaTerdekat(kota_yang_ingin_dicari)].nama; // Cari kota terdekat berdasarkan parameter string
}

int DB::searchByName(string nama_kota)
{
    for (int i = 0; i < banyak_kota; i++) // linear search
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
    float min = INT_MAX;
    int min_pos = pos;
    for (int i = 0; i < banyak_kota; i++)
    {
        if (i != pos)
        {
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

    // Safety
    if (src_pos < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", src.c_str());
        if (dst_pos >= 0)
            return;
    }
    if (dst_pos < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", dst.c_str());
        return;
    }
    if (cekHubungan(src_pos, dst_pos))
    {
        printf("Info: Kota %s dengan %s sudah terhubung\n", src.c_str(), dst.c_str());
        return;
    }
    // Sampai sini dipastikan aman
    kota[src_pos].tanda_akhir_hubungan_kota++;
    kota[src_pos].hubungan_kota.resize(kota[src_pos].tanda_akhir_hubungan_kota + 1);
    kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
}
void DB::connect2arah(string src, string dst)
{
    int src_pos = searchByName(src);
    int dst_pos = searchByName(dst);
    if (src_pos < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", src.c_str());
        if (dst_pos >= 0)
            return;
    }
    if (dst_pos < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", dst.c_str());
        return;
    }
    if (cekHubungan(src_pos, dst_pos))
    {
        printf("Info: Kota %s dengan %s sudah terhubung\n", src.c_str(), dst.c_str());
        // return;
    }
    else
    {
        kota[src_pos].tanda_akhir_hubungan_kota++;
        kota[src_pos].hubungan_kota.resize(kota[src_pos].tanda_akhir_hubungan_kota + 1);
        kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
    }
    if (cekHubungan(dst_pos, src_pos))
    {
        printf("Info: Kota %s dengan %s sudah terhubung\n", src.c_str(), dst.c_str());
        // return;
    }
    else
    {

        kota[dst_pos].tanda_akhir_hubungan_kota++;
        kota[dst_pos].hubungan_kota.resize(kota[dst_pos].tanda_akhir_hubungan_kota + 1);
        kota[dst_pos].hubungan_kota[kota[dst_pos].tanda_akhir_hubungan_kota] = src_pos;
    }

    // Jika sampai sini maka bisa dipastikan aman

    return;
}

void DB::simpanDataJarak(int pos)
{
    for (int i = 0; i < banyak_kota; i++)
    {
        if (cekHubungan(i, pos)) // Yang diproses adalah kota kota yang terhubung
        {
            // printf("onok\n");
            data_jarak_kota[i][pos] = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
        }
        else // Jika tidak terhubung maka diisi dengan 0
        {
            // printf("gak onok\n");
            data_jarak_kota[i][pos] = 0;
        }
    }
}

void DB::initDijkstra()
{
    // nggawe data jarak sek
    data_jarak_kota.resize(banyak_kota, vector<float>(banyak_kota)); // Resize vektor
    for (int i = 0; i < banyak_kota; i++)                            // Proses untuk menyimpan data jarak antar kota
    {
        simpanDataJarak(i);
    }
    sudah_dilewati.resize(banyak_kota);
    path_temp.resize(banyak_kota);
    jarak_antar_node.resize(banyak_kota);
    // sudah_dilewati.

    for (int i = 0; i < banyak_kota; i++)
    {
        // path_temp[src] = -1;
        jarak_antar_node[i] = INT_MAX;
        sudah_dilewati[i] = 0;
    }

    if (!data_hasil_dijkstra.empty()) // Mengosongkan hasil agar tidak tabrakan dengan hasil sebelumnya
        printf("Debug: Gagal mengosongkan hasil dijkstra\n");
}
bool DB::cariRute(string asal, string tujuan)
{
    int src = searchByName(asal);
    int dst = searchByName(tujuan);
    if (src < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", asal.c_str());
        if (dst >= 0)
            return 0;
    }
    if (dst < 0)
    {
        printf("Error: Kota %s tidak ditemukan dalam Database\n", tujuan.c_str());
        return 0;
    }
    // Kedua kota aman
    int src_temp_temp = src; // safety lanjutan
    initDijkstra();
    jarak_antar_node[src] = 0;
    path_temp[src] = -1;

    for (int i = 0; i < banyak_kota - 1; i++) // Proses pembuatan path
    {
        int src_temp = cariJarakTerkecilDijkstra(jarak_antar_node, sudah_dilewati, src_temp_temp);
        if (src_temp == -1) // Safety jika tidak ada jalan apapun
        {
            printf("Debug: Tidak ditemukan jalan\n");
            return 0;
        }
        src_temp_temp = src_temp;
        sudah_dilewati[src_temp] = 1;                              // Jika kota sudah diproses maka dianggap sudah dilewati
        for (int dst_temp = 0; dst_temp < banyak_kota; dst_temp++) // main-process pembuatan path jalur dijkstra
        {
            if (sudah_dilewati[dst_temp] == 0 && data_jarak_kota[src_temp][dst_temp] > 0 && jarak_antar_node[src_temp] + data_jarak_kota[src_temp][dst_temp] < jarak_antar_node[dst_temp])
            {
                path_temp[dst_temp] = src_temp;
                jarak_antar_node[dst_temp] = jarak_antar_node[src_temp] + data_jarak_kota[src_temp][dst_temp];
            }
        }
        if (src_temp == dst) // Safety
        {
            break;
        }
    }

    if (jarak_antar_node[dst] >= INT_MAX) // Jika masih bernilai sesuai inisialisasi maka dianggap tidak sampai tujuan
    {
        printf("Dari %s tidak ada jalan menuju %s\n", kota[src].nama.c_str(), kota[dst].nama.c_str());
        return 0;
    }
    else
    {
        printf("jarak: %d\n", jarak_antar_node[dst]);
        iter_get = 0;
        getPath(path_temp, dst);
    }
    // data_hasil_dijkstra.
    for (int i = 0, j = data_hasil_dijkstra.size() - 1; i < j; i++, j--) // membalikkan isi array
    {

        // Menggunakan operasi XOR untuk swap value
        data_hasil_dijkstra[j] ^= data_hasil_dijkstra[i];
        data_hasil_dijkstra[i] = data_hasil_dijkstra[j] ^ data_hasil_dijkstra[i];
        data_hasil_dijkstra[j] ^= data_hasil_dijkstra[i];
    }
    return 1;
}

int DB::cariJarakTerkecilDijkstra(vector<int> jarak_antar_node, vector<bool> sudah_dilewati, unsigned int src)
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < banyak_kota; v++)
    {
        if (sudah_dilewati[v] == 0 && jarak_antar_node[v] <= min) // jika kota tujuan belum diproses
        {
            min = jarak_antar_node[v];
            min_index = v;
        }
    }
    return min_index;
}

void DB::getPath(vector<int> path_temp, int dst)
{
    // static unsigned int iter = 0;
    // printf("iter = %d\n", iter);
    // printf("iter_get = %d\n", iter_get);
    data_hasil_dijkstra.resize(iter_get + 1);
    data_hasil_dijkstra[iter_get] = dst;
    // printf("path temp %d, dst %d\n", path_temp[dst], dst);
    if (iter_get > banyak_kota) // Jika terjadi rekursi lebih dari banyak kota
    {
        printf("Debug: Tidak menemukan jalan\n");
        return;
    }
    if (path_temp[dst] == -1) // berhenti saat sampai ke src
        return;
    // iter++;
    iter_get++;
    getPath(path_temp, path_temp[dst]); // Rekursi
    // printf("%d ", dst);
}

bool DB::cekHubungan(int src_pos, int dst_pos)
{
    for (int i = 0; i <= kota[src_pos].tanda_akhir_hubungan_kota; i++) // linear search
    {
        if (kota[src_pos].hubungan_kota[i] == dst_pos)
        {
            return 1;
        }
    }

    return 0;
}