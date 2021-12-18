#include "../include/main_lib.h"

// void eksekusi()
// {
// }

int main()
{
    // printf("%d.%d.%d\n", SFML_VERSION_MAJOR, SFML_VERSION_MINOR, SFML_VERSION_PATCH);
    // return;
    // printDBG("nyobak\n");
    // struct route
    // {
    //     string name;
    //     float distance;
    // };
    // struct Route
    // {
    //     string name;

    //     vector<struct route> arrival;
    // };
    // struct Route departure[1000];
    // int m2 = -1;
    // departure[0].arrival[0].name.assign("nama");
    // return 0;

    printf("Info: Application started with PID = %d\n", getpid());
    DB DbKota;
    Executor eksekutor(&DbKota);

    // // // ALlin
    // DbKota.append("A", -300, 75);
    // DbKota.append("B", -150, 150);
    // DbKota.append("C", -150, 0);
    // DbKota.append("D", 0, 150);
    // DbKota.append("E", 0, 0);
    // DbKota.append("F", 150, 150);
    // DbKota.append("G", 150, 0);
    // DbKota.append("Z", 300, 75);

    // DbKota.connect2arah("A", "B");
    // DbKota.connect2arah("A", "C");
    // DbKota.connect2arah("D", "C");
    // DbKota.connect2arah("B", "C");
    // DbKota.connect2arah("B", "D");
    // DbKota.connect2arah("D", "E");
    // DbKota.connect2arah("G", "E");
    // DbKota.connect2arah("C", "E");
    // DbKota.connect2arah("G", "F");
    // DbKota.connect2arah("G", "Z");
    // DbKota.connect2arah("F", "Z");
    // DbKota.connect2arah("F", "D");

    DbKota.append("A", 0, 0);
    DbKota.append("B", -80, 100);
    DbKota.append("C", -210, -178);
    DbKota.append("D", 67, 200);
    DbKota.append("E", 187, 10);
    DbKota.append("F", -12, -325);
    DbKota.append("G", -217, 224);
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
    DbKota.connect1arah("H", "A");
    DbKota.connect1arah("E", "D");
    DbKota.connect1arah("H", "F");
    DbKota.connect1arah("I", "E");
    DbKota.connect1arah("F", "B");
    DbKota.connect2arah("G", "B");
    // printf()
    // DbKota.initDijkstra();
    // DbKota.cariRute("H", "I");

    // DbKota.show();
    // // interface->getInput();
    // interface->tes_var = 666;
    // printf("%d\n", interface->tes_var);
    // // DbKota.nyobakModular();
    // printf("%d\n", interface->tes_var);

    printf("Info: Database seeder success\n");
    interface->printChoice();
    while (1)
    {
        interface->getInput();
        eksekutor.eksekusi();
    }

    return 0;
}
