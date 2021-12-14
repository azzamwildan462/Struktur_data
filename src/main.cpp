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
    DbKota.append("A", 0, 0);
    DbKota.append("B", 0, 100);
    DbKota.append("C", 100, 0);
    DbKota.append("D", 67, 200);
    DbKota.append("E", 187, 10);
    DbKota.append("F", -100, 0);
    DbKota.append("G", -150, 224);
    DbKota.append("H", 395, -94);
    DbKota.append("I", 120, -178);
    // DbKota.append("A", 0, 0);
    // DbKota.append("B", 0, 150);
    // DbKota.append("C", 150, 0);
    // DbKota.append("D", 150, -150);
    // DbKota.append("E", 300, -150);
    // DbKota.append("F", -150, 0);
    // DbKota.append("G", -300, 0);
    // DbKota.append("H", 0, -150);
    // DbKota.append("I", -150, -150);

    DbKota.connect1arah("A", "C");
    DbKota.connect1arah("C", "D");
    // DbKota.connect1arah("A", "B");
    // DbKota.connect1arah("D", "H");
    DbKota.connect1arah("H", "A");
    // DbKota.connect1arah("F", "G");
    DbKota.connect1arah("E", "D");
    DbKota.connect1arah("H", "F");
    // DbKota.connect1arah("F", "I");
    DbKota.connect1arah("I", "E");

    // DbKota.initDijkstra();
    // DbKota.cariRute("H", "I");

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
