#include "../include/main_lib.h"

// void eksekusi()
// {
// }

int main()
{
    // printf("%d.%d.%d\n", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH);
    // return;
    DB DbKota;
    Executor eksekutor(&DbKota);
    DbKota.append("Pasuruan", 0, 0);
    DbKota.append("Sidoarjo", 0, 100);
    DbKota.append("Probolinggo", 1, 0);
    DbKota.append("Lumajang", 2, 4);
    DbKota.append("Jember", 5, 10);
    DbKota.append("Mojokerto", -100, 0);
    DbKota.append("Jombang", -150, 0);
    DbKota.append("Malang", 0, -9);
    DbKota.append("Blitar", 12, 8);
    // DbKota.append("Pasuruan", 0, 0);
    // DbKota.append("Sidoarjo", 0, 150);
    // DbKota.append("Probolinggo", 150, 0);
    // DbKota.append("Lumajang", 150, -150);
    // DbKota.append("Jember", 300, -150);
    // DbKota.append("Mojokerto", -150, 0);
    // DbKota.append("Jombang", -300, 0);
    // DbKota.append("Malang", 0, -150);
    // DbKota.append("Blitar", -150, -150);

    DbKota.connect1arah("Pasuruan", "Probolinggo");
    DbKota.connect1arah("Probolinggo", "Lumajang");
    // DbKota.connect1arah("Pasuruan", "Sidoarjo");
    // DbKota.connect1arah("Lumajang", "Malang");
    DbKota.connect1arah("Malang", "Pasuruan");
    // DbKota.connect1arah("Mojokerto", "Jombang");
    DbKota.connect1arah("Jember", "Lumajang");
    DbKota.connect1arah("Malang", "Mojokerto");
    // DbKota.connect1arah("Mojokerto", "Blitar");
    DbKota.connect1arah("Blitar", "Jember");

    // DbKota.initDijkstra();
    // DbKota.cariRute("Malang", "Blitar");

    // DbKota.show();
    // // interface->getInput();
    // interface->tes_var = 666;
    // printf("%d\n", interface->tes_var);
    // // DbKota.nyobakModular();
    // printf("%d\n", interface->tes_var);

    while (1)
    {
        interface->getInput();
        eksekutor.eksekusi();
    }

    return 0;
}
