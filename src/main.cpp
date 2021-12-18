#include "../include/main_lib.h"

int main()
{
    printf("Info: Application started with PID = %d\n", getpid());
    DB DbKota;
    Executor eksekutor(&DbKota);

    DbKota.append("A", 0, 0);
    DbKota.append("B", -80, 100);
    DbKota.append("C", -210, -178);
    DbKota.append("D", 67, 200);
    DbKota.append("E", 187, 10);
    DbKota.append("F", -12, -325);
    DbKota.append("G", -217, 224);
    DbKota.append("H", 395, -94);
    DbKota.append("I", 120, -178);

    DbKota.connect1arah("A", "C");
    DbKota.connect1arah("C", "D");
    DbKota.connect1arah("H", "A");
    DbKota.connect1arah("E", "D");
    DbKota.connect1arah("H", "F");
    DbKota.connect1arah("I", "E");
    DbKota.connect1arah("F", "B");
    DbKota.connect2arah("G", "B");

    printf("Info: Database seeder success\n");
    interface->printChoice();
    while (1)
    {
        interface->getInput();
        eksekutor.eksekusi();
    }

    return 0;
}
