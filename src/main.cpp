#include "../include/main_lib.h"

int main()
{
    DB DbKota;
    DbKota.append("Pasuruan", 0, 0);
    DbKota.append("Sidoarjo", 0, 150);
    DbKota.append("Probolinggo", 150, 0);
    DbKota.append("Lumajang", 150, -150);
    DbKota.append("Jember", 300, -150);
    DbKota.append("Mojokerto", -150, 0);
    DbKota.append("Jombang", -300, 0);
    DbKota.append("Malang", 0, -150);
    DbKota.append("Blitar", -150, -150);

    DbKota.connect2arah("Pasuruan", "Probolinggo");
    DbKota.connect2arah("Probolinggo", "Lumajang");
    DbKota.connect2arah("Pasuruan", "Sidoarjo");
    DbKota.connect2arah("Lumajang", "Malang");
    DbKota.connect2arah("Malang", "Pasuruan");
    DbKota.connect2arah("Mojokerto", "Jombang");
    DbKota.connect2arah("Jember", "Lumajang");
    DbKota.connect2arah("Pasuruan", "Mojokerto");
    DbKota.connect2arah("Mojokerto", "Blitar");
    DbKota.connect2arah("Blitar", "Malang");

    DbKota.show();
    // // interface->getInput();
    // interface->tes_var = 666;
    // printf("%d\n", interface->tes_var);
    // // DbKota.nyobakModular();
    // printf("%d\n", interface->tes_var);

    return 0;
}
