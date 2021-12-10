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