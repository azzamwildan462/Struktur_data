#include <stdio.h>
#include <limits.h> //untuk INT_MAX

#define banyak_kota 9

int cariJarakTerkecilDijkstra(int jarak_antar_node[], bool sudah_dilewati[])
{

    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < banyak_kota; v++)
    {
        if (!sudah_dilewati[v] &&
            jarak_antar_node[v] <= min)
        {
            min = jarak_antar_node[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j)
{

    if (parent[j] == -1) // berhenti saat sampai ke src
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

int printSolution(int jarak_antar_node[], int n, int parent[], int src, int dst)
{
    printf("Vertex\t jarak_antar_nodeance\tPath");
    printf("\n%d -> %d \t\t %d\t\t%d ", src, dst, jarak_antar_node[dst], src);
    printPath(parent, dst);
    return 0;
}

void dijkstra(int graph[banyak_kota][banyak_kota], int src, int dst)
{

    int jarak_antar_node[banyak_kota];

    bool sudah_dilewati[banyak_kota];

    int parent[banyak_kota];

    parent[src] = -1;
    for (int i = 0; i < banyak_kota; i++)
    {
        jarak_antar_node[i] = INT_MAX;
        sudah_dilewati[i] = false;
    }
    sudah_dilewati[src] = 1;

    jarak_antar_node[src] = 0;

    for (int count = 0; count < banyak_kota - 1; count++)
    {
        int u = cariJarakTerkecilDijkstra(jarak_antar_node, sudah_dilewati);

        sudah_dilewati[u] = true;

        for (int v = 0; v < banyak_kota; v++)
        {
            printf("%d dan %d -> %d dan %d\n", u, v, jarak_antar_node[u], jarak_antar_node[v]);
            if (!sudah_dilewati[v] && graph[u][v] && jarak_antar_node[u] + graph[u][v] < jarak_antar_node[v])
            {
                // printf("seng masok: %d dan %d ->  %d dan %d -> ", u, v, jarak_antar_node[u], jarak_antar_node[v]);
                parent[v] = u;
                jarak_antar_node[v] = jarak_antar_node[u] + graph[u][v];
                // printf("%d\n", jarak_antar_node[v]);
            }
        }
    }

    printSolution(jarak_antar_node, banyak_kota, parent, src, dst);
}

int main()
{
    int graph[banyak_kota][banyak_kota] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                           {0, 0, 4, 0, 10, 0, 2, 0, 0},
                                           {0, 0, 0, 14, 0, 2, 0, 1, 6},
                                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0, 4);
    printf("\n");
    return 0;
}
// SOP pengerjaan
//  1. Bismillah
//  2. Koding
//  3. Run
//  4. Error? -> kembali nomer 1
//  5. Alhamdulillah..

#include <bits/stdc++.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// void *drawGraph()
// {
//     printf("tes\n");
// }

float pitagoras(float x1, float y1, float x2, float y2)
{

    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

float findDirection(float xpos, float ypos, float xtarget, float ytarget)
{
    float result, temp;
    xtarget -= xpos;
    ytarget -= ypos;

    temp = sqrt((xtarget * xtarget) + (ytarget * ytarget));
    if (xtarget >= 0 && ytarget >= 0 || xtarget >= 0 && ytarget < 0)
    {
        result = asin(ytarget / temp);
    }
    else if (xtarget >= 0 && ytarget >= 0 || xtarget < 0 && ytarget >= 0)
    {
        result = acos(xtarget / temp);
    }
    else if (xtarget < 0 && ytarget < 0)
    {
        xtarget *= -1;
        ytarget *= -1;
        result = asin(ytarget / temp);
        result += (180 / 180) * 3.141592653589793238;
    }
    result *= 180 / 3.141592653589793238;
    // return result + 90;
    return result;
}

class DbKota
{
public:
    int banyak_kota = 0;

private:
    // properties
    // int last_node;
    float data_jarak_kota[100][100];

public:
    // properties
    struct kota_t
    {
        string nama;
        char *nama_serial;
        int x;
        int y;
        string hubungan_kota[100];
        int hubungan_kota_pos[100];
        int tanda_akhir_hubungan_kota;
        // int next_node;
    };

    kota_t kota[100];

    // method

    DbKota()
    {
        // last_node = -1;
        banyak_kota = 0;
    }
    ~DbKota()
    {
        // destruktor
    }

    void push(string nama_kota, int x, int y)
    {
        // last_node++;
        banyak_kota++;
        kota[banyak_kota - 1].nama = nama_kota;
        kota[banyak_kota - 1].x = x;
        kota[banyak_kota - 1].y = y;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
        // kota[last_node].next_node = -1;
        // kota[banyak_kota - 1].nama_serial = new char[nama_kota.size() + 1];
        // strcpy(kota[banyak_kota - 1].nama_serial, kota[banyak_kota - 1].nama.c_str());
    }
    void push(kota_t src)
    {
        banyak_kota++;
        // printf("alamat tekan push: %p\n", &kota[banyak_kota - 1]);
        kota[banyak_kota - 1] = src;
        // memcpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
        // memset(&kota[banyak_kota-1],src,sizeof(kota[banyak_kota]));
        // memccpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
    }

    kota_t pop()
    {
        kota_t buff, null;
        // memcpy(&buff, &kota[banyak_kota - 1], sizeof(buff));
        buff = kota[banyak_kota - 1];
        // memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
        kota[banyak_kota - 1] = null;
        banyak_kota--;
        return buff;
    }

    void pop(kota_t *result)
    {
        kota_t null;
        // printf("fungsi: %p\n", result);
        // printf("asli pop: %s", kota[banyak_kota - 1].nama.c_str());
        // printf("alamat sakdoronge %p\n", &kota[banyak_kota - 1]);
        *result = kota[banyak_kota - 1];
        kota[banyak_kota - 1] = null;
        // memset(&kota[banyak_kota - 1], 0, sizeof(kota[banyak_kota]));
        // printf("alamat sakmarine %p\n", &kota[banyak_kota - 1]);
        // printf("hasil pop fungsi: %s\n", kota[banyak_kota - 1].nama.c_str());
        // printf("waetfcthweftvewjqewfiter_getyj\n");
        banyak_kota--;
        // printf("hasil pop: %s", result->nama.c_str());
    }

    void justPop()
    {
        kota_t null;
        kota[banyak_kota - 1] = null;
        // memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
        banyak_kota--;
    }

    void enqueue(kota_t src)
    {
        // remove(0);
        insert(0, src.nama, src.x, src.y);
    }
    void enqueue(string nama, int x, int y)
    {
        // insert(0, nama, x, y);
        banyak_kota++;
        kota[banyak_kota - 1].nama = nama;
        kota[banyak_kota - 1].x = x;
        kota[banyak_kota - 1].y = y;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
    }
    void dequeue(kota_t *res)
    {
        *res = kota[0];
        remove(0);
    }
    kota_t dequeue()
    {
        kota_t buff;
        buff = kota[0];
        remove(0);
        return buff;
    }
    void justDequeue()
    {
        remove(0);
    }

    void remove(int posisi)
    {
        posisi++;
        for (int i = posisi - 1; i < banyak_kota; i++) // mengiri
        {
            kota[i] = kota[i + 1];
        }

        kota[banyak_kota - 1].nama = false;
        kota[banyak_kota - 1].x = false;
        kota[banyak_kota - 1].y = false;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;

        banyak_kota--;
    }

    void removeByName(string nama_kota)
    {
        remove(searchByName(nama_kota));
    }

    void insert(int posisi, string nama_kota, int x, int y)
    {
        kota_t null; // menyiapkan ruang kosong
        banyak_kota++;
        for (int i = banyak_kota; i >= posisi; i--) // menganan
        {
            kota[i + 1] = kota[i];
        }
        // printf("hubungan: %s", null.hubungan_kota[0].c_str());
        null.tanda_akhir_hubungan_kota = -1; // persiapan tambahan
        kota[posisi] = null;
        kota[posisi].nama = nama_kota;
        kota[posisi].x = x;
        kota[posisi].y = y;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        // kota[last_node].tanda_akhir_hubungan_kota = -1;
        // kota[posisi].next_node = -1;
    }

    void show(int more = 0)
    {
        int panjang_nama = 0;
        int panjang_terdekat = 0;
        if (!more)
        {
            for (int i = 0; i < banyak_kota; i++)
            {
                // printf("iter-%d\n", i);
                if (kota[i].nama.size() < 0x8)
                    cout << kota[i].nama << "\t\t";
                else if (kota[i].nama.size() >= 0x8)
                    cout << kota[i].nama << "\t";
                cout << kota[i].x << "\t";
                cout << kota[i].y << "\t";
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
        else
        {
            // header
            for (int i = 0; i < banyak_kota; i++)
            {
                if (kota[i].nama.size() < 0x8)
                    panjang_nama = 0;
                else if (kota[i].nama.size() >= 0x8)
                    panjang_nama = 1;

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
                        cout << kota[i].hubungan_kota[v] << ", ";
                    }
                    cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
                }
                cout << endl;
            }
        }
        printf("\n");
    }

    int searchByName(string nama_kota)
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
    void searchWithoutReturn(string nama_kota)
    {
        for (int i = 0; i < banyak_kota; i++)
        {
            if (nama_kota == kota[i].nama)
            {
                printf("%s ada pada index ke-%d\n", nama_kota.c_str(), i);
                return;
            }
        }
        printf("Kota tidak ditemukan\n");
    }

    void searchByPos(int posisi)
    {
        cout << "Kota pada posisi ke-" << posisi << " adalah " << kota[posisi].nama << endl;
    }
    void connect1arah(string src, string dst)
    {
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {

            kota[src_pos].tanda_akhir_hubungan_kota++;
            kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
            kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
        }
        else
            printf("Invalid name\n");
    }
    void connect2arah(string src, string dst)
    {
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {
            kota[dst_pos].tanda_akhir_hubungan_kota++;
            kota[dst_pos].hubungan_kota[kota[dst_pos].tanda_akhir_hubungan_kota] = src;
            kota[dst_pos].hubungan_kota_pos[kota[dst_pos].tanda_akhir_hubungan_kota] = src_pos;

            kota[src_pos].tanda_akhir_hubungan_kota++;
            kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
            kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
        }
        else
            printf("Invalid name\n");
    }

    // PERCOBAAN, kendala belum menemukan solusi tepat untuk pindah cabang pencarian
    void cariHubungan(int dst, int temp[100], int *total_hub, int iter)
    {
        // Linear search
        int temp_iter = iter;
        for (int i = 0; i < banyak_kota; i++)
        {
            if (kota[i].tanda_akhir_hubungan_kota > -1)
            {
                for (int j = 0; j <= kota[i].tanda_akhir_hubungan_kota; j++)
                {
                    // printf("hub: %d dengan %d, ", kota[i].hubungan_kota_pos[j], dst);
                    if (kota[i].hubungan_kota_pos[j] == dst)
                    {
                        temp[temp_iter] = i;
                        temp_iter++;
                    }
                }
            }
            // printf("sudah\n");
        }
        // printf("ier: %d\n", temp_iter);
        if (temp_iter == 0)
            printf("Tdk punya hubungan..\n");
        else
            *total_hub = temp_iter;
    }
    void cariRute(string src, string dst)
    {
        int temp[100], total_hub = 0, hasil[100];
        int tanda_hasil = 0;
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {
            int i = 0;
            // while (temp[i] != src_pos)
            // {
            temp[0] = dst_pos;
            int j = 0;
            while (temp[0] != src_pos)
            {
                // printf("j: %d\n", j);
                if (j >= banyak_kota - 1)
                {
                    j = 0;
                    i++;
                }
                cariHubungan(temp[i], temp, &total_hub, i);
                j++;
                if (total_hub > 0)
                {
                    hasil[tanda_hasil] = temp[i];
                    tanda_hasil++;
                }
            }
            //     i++;
            // }
        }
        // printf("temp0: %d\n", temp[0]);
        if (temp[0] == searchByName(src))
        { // printf("hasil: %d", temp[0]);
            // printf("Rute: ");
            cout << "Rute " << src << " ke " << dst << " : " << endl;
            for (int i = tanda_hasil - 1; i >= 0; i--)
            {
                // printf("awukehhkcuakuaew %d ", hasil[i]);
                // printf("%");
                cout << kota[hasil[i]].nama << " -> ";
            }
            cout << dst << endl;
        }
        else
        {
            printf("Tidak ditemukan jalan..");
        }
    }
    int cariKotaTerdekat(string kota_yang_ingin_dicari)
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
    string cariKotaTerdekatStr(string kota_yang_ingin_dicari)
    {
        return kota[cariKotaTerdekat(kota_yang_ingin_dicari)].nama;
    }
    void simpan_data_jarak(int pos)
    {
        for (int i = 0; i < banyak_kota; i++)
        {
            data_jarak_kota[i][pos] = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
        }
    }
    void dijkstra()
    {
        // nggawe data jarak sek
        for (int i = 0; i < banyak_kota; i++)
        {
            simpan_data_jarak(i);
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
};
\ class Iface
{
private:
    DbKota *DB; // simpan alamat DB

public:
    Iface(DbKota *DB)
    {
        this->DB = DB;
    }
    ~Iface()
    {
    }
    void pop(DbKota::kota_t *result)
    {
        int pilihan;
        printf("0. exit\n");
        printf("1. Pop dengan hasilnya disimpan dalam variabel buff pada main\n");
        printf("2. Pop tanpa menyimpan hasilnya\n");
        scanf("%d", &pilihan);

        if (!pilihan)
            return;
        switch (pilihan)
        {
        case 1:
            DB->pop(result);
            break;
        case 2:
            DB->justPop();
            break;

        default:
            break;
        }
    }
    void hub()
    {
        int pilihan;
        string src, dst;
        printf("0. exit\n");
        printf("1. hubungakn 1 arah\n");
        printf("2. hubungkan 2 arah\n");
        scanf("%d", &pilihan);

        if (!pilihan)
            return;
        switch (pilihan)
        {
        case 1:
            printf("Kota asal? ");
            getline(cin, src);
            getline(cin, src);
            printf("Tujuan? ");
            getline(cin, dst);
            // printf("sampek kene?");
            DB->connect1arah(src, dst);
            break;
        case 2:
            printf("Kota asal? ");
            getline(cin, src);
            getline(cin, src);
            printf("Tujuan? ");
            getline(cin, dst);
            DB->connect2arah(src, dst);
            break;

        default:
            break;
        }
    }
    void push()
    {
        string nama;
        int x, y;
        printf("Nama kota?: ");
        // cin >> nama;
        getline(cin, nama);
        getline(cin, nama);
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);
        DB->push(nama, x, y);
    }
    void enqueue()
    {
        string nama;
        int x, y;
        printf("Nama kota?: ");
        // cin >> nama;
        getline(cin, nama);
        getline(cin, nama);
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);
        DB->enqueue(nama, x, y);
    }
    void dequeue()
    {
        DB->dequeue();
    }
    void insert()
    {
        string nama;
        int x, y, pos;
        printf("Posisi index?: ");
        scanf("%d", &pos);
        printf("Nama kota?: ");
        // cin >> nama;
        getline(cin, nama);
        getline(cin, nama);
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);
        DB->insert(pos, nama, x, y);
    }
    void remove()
    {
        int pilihan;
        string nama;
        int index;
        printf("0. exit\n");
        printf("1. hapus berdasarkan index\n");
        printf("2. hapus berdasarkan nama kota\n");
        scanf("%d", &pilihan);

        if (!pilihan)
            return;
        switch (pilihan)
        {
        case 1:
            printf("Masukkan index yang ingin dihapus: ");
            scanf("%d", &index);
            DB->remove(index);
            break;
        case 2:
            printf("Masukkan nama kota yang ingin dihapus: \n");
            getline(cin, nama);
            getline(cin, nama);
            DB->removeByName(nama);
            break;

        default:
            break;
        }
    }
    void cari()
    {
        int pilihan;
        string nama;
        int index;
        printf("0. exit\n");
        printf("1. cari berdasarkan index\n");
        printf("2. cari berdasarkan nama kota\n");
        scanf("%d", &pilihan);

        if (!pilihan)
            return;
        switch (pilihan)
        {
        case 1:
            printf("Masukkan index yang ingin dicari: ");
            scanf("%d", &index);
            DB->searchByPos(index);
            break;
        case 2:
            printf("Masukkan nama kota yang ingin dicari: \n");
            getline(cin, nama);
            getline(cin, nama);
            // cin.getline(nama);
            // DB->searchByName(nama);
            DB->searchWithoutReturn(nama);
            break;

        default:
            break;
        }
    }
    void graph()
    {
        int offset_x = 400;
        int offset_y = 300;
        int pembuat_ngiri = 50;
        int penghitung_banyak_hubungan = 0;
        int temp_j = 0;
        float sudut_hubung = 0;
        float x_arah, y_arah;
        static int j;

        RenderWindow Window(VideoMode(800, 600), "Graph");
        Event event_handler;
        CircleShape kota[DB->banyak_kota];
        Text nama_kota[DB->banyak_kota];
        Font arial;
        arial.loadFromFile("arial.ttf");

        for (int i = 0; i < DB->banyak_kota; i++)
        {
            if (DB->kota[i].tanda_akhir_hubungan_kota > -1)
            {
                // printf("Ada\n");
                // printf("jumlah? %d\n", DB->kota[i].tanda_akhir_hubungan_kota + 1);
                penghitung_banyak_hubungan += DB->kota[i].tanda_akhir_hubungan_kota + 1;
            }
        }

        RectangleShape garis_hubung[penghitung_banyak_hubungan];
        CircleShape arah[penghitung_banyak_hubungan];
        RectangleShape debug;
        debug.setSize(Vector2f(150, 5));
        debug.setPosition(400, 300);

        for (int i = 0; i < DB->banyak_kota; i++)
        {
            nama_kota[i].setFont(arial);
            nama_kota[i].setString(DB->kota[i].nama);
            nama_kota[i].setPosition(sf::Vector2f((float)offset_x + DB->kota[i].x - pembuat_ngiri, (float)offset_y - DB->kota[i].y + 40));
            nama_kota[i].setCharacterSize(20);
            nama_kota[i].setFillColor(sf::Color(198, 16, 235, 255));

            kota[i].setFillColor(sf::Color(3, 227, 252, 0.7));
            kota[i].setRadius(30);
            kota[i].setOrigin(50, 25);
            kota[i].setOutlineColor(sf::Color(3, 227, 152, 200));
            kota[i].setOutlineThickness(2);
            kota[i].setPosition((float)offset_x + DB->kota[i].x, (float)offset_y - DB->kota[i].y);
            // printf("temp j = %d\n", temp_j);
            // for (int j = temp_j; j <= DB->kota[i].tanda_akhir_hubungan_kota; j++)
            // {
            //     // printf("iya\n");
            //     printf("Kota endi? %s\n", DB->kota[i].nama.c_str());
            //     temp_j = j;
            //     // printf("%f %f\n", garis_hubung[i].getPosition());
            //     // garis_hubung[j].setPosition(Vector2f((float)offset_x + DB->kota[i].x, (float)offset_y - DB->kota[i].y));
            // }
            // static int j;

            if (DB->kota[i].tanda_akhir_hubungan_kota > -1)
            {
                // printf("mrene peng piro? %d\n", j);
                temp_j = 0;
                while (j < penghitung_banyak_hubungan)
                {
                    if (temp_j > DB->kota[i].tanda_akhir_hubungan_kota)
                        break;

                    sudut_hubung = findDirection((float)offset_x + DB->kota[i].x, (float)offset_y - DB->kota[i].y, (float)offset_x + DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].x, (float)offset_y - DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].y);

                    garis_hubung[j].setOrigin(0, 2.5);
                    garis_hubung[j].setSize(Vector2f(150 + fabs(0 - fmod(fabs(sudut_hubung), 90)) - 20, 5));
                    garis_hubung[j].setPosition((float)offset_x + DB->kota[i].x - 18, (float)offset_y - DB->kota[i].y + 5);
                    garis_hubung[j].rotate(sudut_hubung);
                    garis_hubung[j].setFillColor(sf::Color(198, 16, 235, 0.5));
                    garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 1));
                    garis_hubung[j].setOutlineThickness(2);

                    x_arah = offset_x + DB->kota[i].x - 18 + ((float)(offset_x + DB->kota[i].x - 18 + offset_x + DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].x - 18) / 2);
                    x_arah /= 2;
                    y_arah = offset_y - DB->kota[i].y + 5 + ((float)(offset_y - DB->kota[i].y + 5 + offset_y - DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].y + 5) / 2);
                    y_arah /= 2;

                    arah[j].setOrigin(15, 7.5);
                    arah[j].setPointCount(3);
                    arah[j].setRadius(15);
                    // arah[j].setPosition((float)(offset_x + DB->kota[i].x + offset_x + DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].x) / 2, (float)(offset_y - DB->kota[i].y + offset_y - DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].y) / 2);
                    arah[j].rotate(sudut_hubung + 90);
                    arah[j].setPosition(x_arah, y_arah);
                    arah[j].setFillColor(sf::Color(198, 16, 235, 1));
                    arah[j].setOutlineColor(sf::Color(198, 16, 235, 1));
                    arah[j].setOutlineThickness(2);

                    // printf("%d %f %f\n", j, (float)offset_x + DB->kota[i].x, (float)offset_y - DB->kota[i].y);
                    // printf("sudut? %f\n", findDirection((float)offset_x + DB->kota[i].x, (float)offset_y - DB->kota[i].y, (float)offset_x + DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].x, (float)offset_y - DB->kota[DB->kota[i].hubungan_kota_pos[temp_j]].y));
                    j++;
                    temp_j++;
                }
            }

            // printf("asli -> %f %f\n", (float)DB->kota[i].x, (float)DB->kota[i].y);
        }

        while (1)
        {
            // printf("hmm0\n");
            while (Window.pollEvent(event_handler))
            {
                // printf("hmm2\n");
                if (event_handler.type == sf::Event::Closed)
                {
                    j = 0;
                    Window.close();
                    return;
                    // printf("hmm\n");
                }
            }

            for (int i = 0; i < penghitung_banyak_hubungan; i++)
            {
                Window.draw(garis_hubung[i]);
                Window.draw(arah[i]);
                // printf("piro? %d\n", i);
            }

            for (int i = 0; i < DB->banyak_kota; i++)
            {
                // Window.draw(garis_hubung[i]);
                Window.draw(kota[i]);
                Window.draw(nama_kota[i]);
            }
            // Window.draw(debug);
            Window.display();
        }
    }
};

int main()
{
    int iface_switch = 0;
    DbKota DB;
    DbKota::kota_t buff;
    Iface interface(&DB);

    DB.push("Pasuruan", 0, 0);
    DB.push("Sidoarjo", 0, 150);
    DB.push("Probolinggo", 150, 0);
    DB.push("Lumajang", 150, -150);
    DB.push("Jember", 300, -150);
    DB.push("Mojokerto", -150, 0);
    DB.push("Jombang", -300, 0);
    DB.push("Malang", 0, -150);
    DB.push("Blitar", -150, -150);

    DB.connect2arah("Pasuruan", "Probolinggo");
    DB.connect2arah("Probolinggo", "Lumajang");
    DB.connect2arah("Pasuruan", "Sidoarjo");
    DB.connect2arah("Lumajang", "Malang");
    DB.connect2arah("Malang", "Pasuruan");
    DB.connect2arah("Mojokerto", "Jombang");
    DB.connect2arah("Jember", "Lumajang");
    DB.connect2arah("Pasuruan", "Mojokerto");
    DB.connect2arah("Mojokerto", "Blitar");
    DB.connect2arah("Blitar", "Malang");

    // DB.connect1arah("Sidoarjo", "Mojokerto");

    // DB.connect1arah("Istanbul", "Istanbul");

    // DB.insert(2, "sby", 12, 23);
    // DB.show(1);
    // DB.searchByName("sby");
    // DB.searchByPos(2);
    // DB.remove(2);
    // DB.removeByName("Cilacap");

    // printf("hasil %d", DB.searchByName("Cilacap"));

    // buff = DB.pop();
    // DB.pop(&buff);
    // DB.enqueue(buff);
    // DB.show(1);
    // printf("main: %p\n", &buff);
    // printf("hasil pop: %s", buff.nama.c_str());
    // DB.dequeue(&buff);
    // DB.push(buff);
    // DB.show(1);
    // printf("buri\n");
    // DB.cariRute("Jember", "Dimmsdale");
    // DB.cariRute("Jember", "Konoha");

    // printf("%f", pitagoras(2, 0, 5, 4));
    // printf("%d\n", DB.cariKotaTerdekat("Jember"));
    // printf("%s\n", DB.cariKotaTerdekatStr("Jember").c_str());
    // DB.cariKotaTerdekat("Jember");

    // DB.show(1);
    // int coba = 8;
    // if (coba == 0x8)
    //     printf("%x\n", coba);
    // printf("%x\n", 69);

    // string dummy;
    // printf("input anything to contine\n");
    // getline(cin, dummy);

    while (1)
    {
        printf("0. exit\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. tambahkan kota di indeks pertama (enqueue)\n");
        printf("4. ambil kota dari indeks pertama (dequeue)\n");
        printf("5. masukkan kota\n");
        printf("6. hapus kota\n");
        printf("7. cari kota\n");
        printf("8. hubungkan kota\n");
        printf("9. tampilkan seluruh kota\n");
        printf("10. graph hubungan kota\n");
        scanf("%d", &iface_switch);
        if (!iface_switch)
            break;
        switch (iface_switch)
        {
        case 1:
            interface.push();
            break;
        case 2:
            interface.pop(&buff);
            break;
        case 3:
            interface.enqueue();
            break;
        case 4:
            interface.dequeue();
            break;
        case 5:
            interface.insert();
            break;
        case 6:
            interface.remove();
            break;
        case 7:
            interface.cari();
            break;
        case 8:
            interface.hub();
            break;
        case 9:
            DB.show(1);
            break;
        case 10:
            interface.graph();
            break;
        case 11:
            // interface.graph();
            DB.dijkstra();
            break;

        default:
            break;
        }
    }

    return 0;
}

ffffff30 0
