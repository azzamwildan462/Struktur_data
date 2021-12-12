// #include "../include/main_lib.h"
#include "../include/executor.h"

void Executor::eksekusi()
{
    switch (interface->status_eksekusi)
    {
    case 1:
        tambahKota();
        break;
    case 2:
        hubungkanKota();
        break;
    case 3:
        graph();
        break;
    case 4:
        cariRute();
        break;
    case 5:
        // printf("satu\n");
        Database->show();
        break;

    default:
        // interface->printChoice();
        break;
    }
    interface->status_eksekusi = 0;
    // cout << "dari eksekusi " << interface->status_eksekusi << endl;
}

void Executor::tambahKota()
{
    string nama_kota;
    float x, y;
    printf("Nama Kota: ");
    getline(cin, nama_kota);
    getline(cin, nama_kota);
    printf("Koordinat x: ");
    scanf("%f", &x);
    printf("Koordinat Y: ");
    scanf("%f", &y);
    // cout << nama_kota << " " << x << " " << y << endl;
    Database->append(nama_kota, x, y);
}

Executor::Executor(DB *Database)
{
    this->Database = Database;
}

void Executor::hubungkanKota()
{
    string kota_asal;
    string kota_tujuan;
    int src, dst;
    unsigned int dua_arah;

    printf("Satu arah atau dua arah?\n");
    printf("1. Satu arah\n");
    printf("2. Dua arah\n");
    scanf("%d", &dua_arah);
    // printf("arah %x\n", dua_arah);

    printf("kota asal: ");
    getline(cin, kota_asal);
    getline(cin, kota_asal);
    // src = Database->searchByName(kota_asal);
    // if (src == -1)
    //     cout << "Kota " << kota_asal << " tidak ditemukan.." << endl;

    printf("kota tujuan: ");
    getline(cin, kota_tujuan);
    // dst = Database->searchByName(kota_tujuan);
    // if (dst == -1)
    //     cout << "Kota " << kota_tujuan << " tidak ditemukan.." << endl;

    if (dua_arah == 0x1)
    {
        // printf("satu\n");
        Database->connect1arah(kota_asal, kota_tujuan);
    }
    else if (dua_arah == 0x2)
    {
        Database->connect2arah(kota_asal, kota_tujuan);
        // printf("dua\n");
    }
}

void Executor::cariRute()
{
    string kota_asal, kota_tujuan;

    printf("kota asal: ");
    getline(cin, kota_asal);
    getline(cin, kota_asal);
    printf("kota tujuan: ");
    getline(cin, kota_tujuan);

    Database->cariRute(kota_asal, kota_tujuan);
}
void Executor::graph()
{
    window.create(VideoMode(800, 600), "Graph hubungan kota");
    sf::CircleShape shape(100.f);
    CircleShape kota[Database->banyak_kota];
    Text nama_kota[Database->banyak_kota];
    Font arial;
    // arial.loadFromFile("/home/welldone/proyek/strukdat/backup/Struktur_data/assets/arial.tff");
    // arial.loadFromFile("../assets/Noto_Sans/NotoSans-Bold.ttf");
    arial.loadFromFile("../assets/quicksand/Quicksand-Bold.otf");
    // font.loadFromFile("../assets/font1.ttf");
    // arial = Font.new("".to_s);
    // if (!arial.loadFromFile("../assets/arial.tff"))
    //     return;

    // font.loadFromStream(sf::InputStream())
    // font.loadFromMemory()

    // awgyjradwkuawdkawkwda

    while (window.isOpen())
    {
        while (window.pollEvent(event_handler))
        {
            switch (event_handler.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            default:
                break;
            }
        }
        window.clear();
        // window.draw(shape);
        gambarHubungan(100, 100, 200, 200);
        window.display();
    }
    return;
}
void Executor::gambarHubungan(int x1, int y1, int x2, int y2)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2)),
        sf::Vertex(sf::Vector2f(200, 200)),
        sf::Vertex(sf::Vector2f(400, 400)),
        sf::Vertex(sf::Vector2f(400, 400)),
        sf::Vertex(sf::Vector2f(600, 600)),
        // sf::Vertex(sf::Color::Yellow),
        // line->color.Yellow;
    };
    line->color = sf::Color::Red;
    window.draw(line, 6, sf::Lines);
}
void Executor::gambarKota()
{
}

// Vertex Executor::drawLine(int x1, int y1, int x2, int y2)
// {
//     sf::Vertex line[] = {
//         sf::Vertex(sf::Vector2f(x1, y1)),
//         sf::Vertex(sf::Vector2f(x2, y2)),
//         // sf::Vertex(sf::Color::Yellow),
//         // line->color.Yellow;
//     };
//     line->color = sf::Color::Red;
//     return line;
//     // window.draw(line, 2, sf::Lines);
// }