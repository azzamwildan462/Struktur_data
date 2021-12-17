#include <stdio.h>
#include <limits.h> //untuk INT_MAX

// #define 8 8

int cariJarakTerkecilDijkstra(int jarak_antar_node[], bool sudah[])
{

    int min = INT_MAX; // int max iki sebuah angka seg nilai ne guede
    int min_index;

    for (int v = 0; v < 8; v++)
    {
        if (!sudah[v] && jarak_antar_node[v] <= min) // jika node belum dilewati. Sampingnya itu algoritma nyari nilai terkecil
        {
            min = jarak_antar_node[v]; // simpan nilai terkecilnya untuk proses selanjutnya
            min_index = v;             // ambil indeks nya
        }
    }
    return min_index; // kirim indeks hasil proses yang barusan
}

// Function to print shortest
// path from source to dst
// using jalan array
void printPath(int jalan[], int dst)
{

    // Base Case : If dst is source
    if (jalan[dst] == -1) // mandek ketika mencapai asal nya. tadi di dalem void dijkstra kan sudah dibuatnya asalnya itu diberi nilai -1
        return;

    printPath(jalan, jalan[dst]); // rekursi

    printf("%d ", dst); // print node yang termasuk jalur terpendek
}

// A utility function to print
// the constructed jarak_antar_nodeance
// array
// int printSolution(int jarak_antar_node[], int n,
//                   int jalan[], int src, int dst)
// {
//     // int src = 0;
//     // for (int i = 0; i < 8; i++)
//     // {
//     //     printf("%d ", jalan[i]);
//     // }
//     // printf("\n");

//     // printf("jarak_antar_node i %d", jarak_antar_node[8]);
//     printf("Vertex\t jarak_antar_nodeance\tPath");
//     // printf("melbu kene kan?\n");
//     // for (int i = 0; i < 8; i++)
//     // {
//     //     // if (i != src)
//     //     // {
//     //     printf("\n%d -> %d \t\t %d\t\t%d ", src, i, jarak_antar_node[i], src);
//     //     printPath(jalan, i);
//     //     // }
//     // }
//     printf("\n%d -> %d \t\t %d\t\t%d ", src, dst, jarak_antar_node[dst], src);
//     printPath(jalan, dst);
//     return 0;
// }

// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int graph[8][8], int src, int dst)
{
    // src = asal kalo di soal berarti A berarti 0
    // dst = tujuan kalo di soal berarti Z berarti 7

    // The output array. jarak_antar_node[i]
    // will hold the shortest
    // jarak_antar_nodeance from src to i
    int jarak_antar_node[8]; // buat nyimpen jarak per node nya

    // sudah[i] will true if vertex
    // i is included / in shortest
    // path tree or shortest jarak_antar_nodeance
    // from src to i is finalized
    bool sudah[8]; // gawe menandai sudah dilewati atau belum

    // jalan array to store
    // shortest path tree
    int jalan[8]; // buat nyimpen jarak terpendek

    // Initialize all jarak_antar_nodeances as
    // INFINITE and stpSet[] as false
    jalan[src] = -1; // asal kudu -1 untuk menghentikan rekursi
    for (int i = 0; i < 8; i++)
    {
        jarak_antar_node[i] = INT_MAX; // untuk awal, jarak antar node dianggap sangat besar.
        sudah[i] = false;              // untuk awal, semua node dianggap belum pernah dilewati
    }

    // jarak_antar_nodeance of source vertex
    // from itself is always 0
    jarak_antar_node[src] = 0; // kae wajib karena jarak asal ke node asal iku kudu 0 agar tidak error

    // Find shortest path
    // for all vertices
    for (int count = 0; count < 8 - 1; count++)
    {
        // Pick the minimum jarak_antar_nodeance
        // vertex from the set of
        // vertices not yet processed.
        // u is always equal to src
        // in first iteration.
        int u = cariJarakTerkecilDijkstra(jarak_antar_node, sudah); // setiap node dicari jarak terkecilnya ke node mana

        // Mark the picked vertex
        // as processed
        sudah[u] = true; // kalo sudah diproses, maka dianggap sudah dilewati

        // Update jarak_antar_node value of the
        // adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < 8; v++)

            // Update jarak_antar_node[v] only if is
            // not in sudah, there is
            // an edge from u to v, and
            // total weight of path from
            // src to v through u is smaller
            // than current value of
            // jarak_antar_node[v]

            // Jika node belum dilewati dan jaraknya tidak 0 dan jaraknya lebih kecil dari jarak yang sudah dicatat sebelumnya
            if (!sudah[v] && graph[u][v] != 0 && jarak_antar_node[u] + graph[u][v] < jarak_antar_node[v])
            {
                jalan[v] = u;
                jarak_antar_node[v] = jarak_antar_node[u] + graph[u][v]; // catat jaraknya
            }
    }

    // printSolution(jarak_antar_node, 8, jalan, src, dst); //
    printPath(jalan, dst); // print hasil jalan terkecilnya
}

int main()
{
    // 0 = A
    // 1 = B
    // 2 = C dst.....
    int graph[8][8] = {
        {0, 4, 3, 0, 0, 0, 0, 0},
        {4, 0, 2, 5, 0, 0, 0, 0},
        {3, 2, 0, 3, 6, 0, 0, 0},
        {0, 5, 3, 0, 1, 5, 0, 0},
        {0, 0, 6, 1, 0, 0, 5, 0},
        {0, 0, 0, 5, 0, 0, 2, 7},
        {0, 0, 0, 0, 5, 2, 0, 4},
        {0, 0, 0, 0, 0, 7, 4, 0}};
    // graph neng dukur iki tekan soal

    dijkstra(graph, 0, 7);
    printf("\n");
    return 0;
}