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
        // pthread_t graph_thread;
        // pthread_create(&graph_thread,NULL,graph,(void*)0);
        break;
    case 4:
        cariRute();
        break;
    case 5:
        // printf("satu\n");
        Database->show();
        break;
        // case 666:
        //     interface->printChoice();
        //     break;

    default:
        interface->printChoice();
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

// Executor::Executor(Database *Database)
// {
//     this->Database = Database;
// }
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
    unsigned short int input;
    string kota_asal, kota_tujuan;

    printf("kota asal: ");
    getline(cin, kota_asal);
    getline(cin, kota_asal);
    printf("kota tujuan: ");
    getline(cin, kota_tujuan);

    if (!Database->cariRute(kota_asal, kota_tujuan))
        return;

    printf("CLI atau GUI?\n");
    printf("1. CLI\n");
    printf("2. GUI\n");
    printf("Pilihan: ");
    scanf("%d", &input);

    if (input == 0x1)
    {
        printf("Rutenya yaitu: \n");
        for (size_t i = 0; i < Database->data_hasil_dijkstra.size() - 1; i++)
        {
            // printf("%d -> ", Database->data_hasil_dijkstra[i]);
            printf("%s -> ", Database->kota[Database->data_hasil_dijkstra[i]].nama.c_str());
        }
        // printf("tekan graph %d\n", Database->data_hasil_dijkstra.size() - 1);
        printf("%s\n", Database->kota[Database->data_hasil_dijkstra[Database->data_hasil_dijkstra.size() - 1]].nama.c_str());
    }
    else if (input == 0x2)
    {
        dijkstra_buffer.resize(Database->data_hasil_dijkstra.size());
        dijkstra_buffer = Database->data_hasil_dijkstra;
        // printf("\n");
        // for (size_t i = 0; i < dijkstra_buffer.size(); i++)
        // {
        //     printf("%d -> ", dijkstra_buffer[i]);
        // }
        // printf("\n");
        graph(true);
    }
}
void Executor::graph(bool dijkstra)
{
    // printf("dijkstra %d\n", dijkstra);
    window.create(VideoMode(x_window, y_window), "Graph hubungan kota");
    sf::CircleShape shape(100.f);
    CircleShape kota[Database->banyak_kota];
    Text nama_kota[Database->banyak_kota];
    int pembuat_ngiri = 27;
    int penghitung_banyak_hubungan = 0;
    int temp_j = 0;
    float sudut_hubung = 0;
    float x_arah, y_arah;
    int j = 0;
    font.loadFromFile("assets/arial.ttf");
    // Font arial;
    // arial.loadFromFile("/home/welldone/proyek/strukdat/backup/Struktur_data/assets/arial.tff");
    // arial.loadFromFile("../assets/Noto_Sans/NotoSans-Bold.ttf");
    // arial.loadFromFile("../assets/quicksand/Quicksand-Bold.otf");
    // arial = Font.new("".to_s);
    // if (!arial.loadFromFile("../assets/arial.tff"))
    //     return;

    // font.loadFromStream(sf::InputStream())
    // font.loadFromMemory()

    // awgyjradwkuawdkawkwda
    for (int i = 0; i < Database->banyak_kota; i++)
    {
        if (Database->kota[i].tanda_akhir_hubungan_kota > -1)
        {
            // printf("Ada\n");
            // printf("jumlah? %d\n", Database->kota[i].tanda_akhir_hubungan_kota + 1);
            penghitung_banyak_hubungan += Database->kota[i].tanda_akhir_hubungan_kota + 1;
        }
    }
    // printf("banyk hubungan %d\n", penghitung_banyak_hubungan);
    RectangleShape garis_hubung[penghitung_banyak_hubungan];
    CircleShape arah[penghitung_banyak_hubungan];
    RectangleShape debug;
    debug.setSize(Vector2f(150, 5));
    debug.setPosition(400, 300);

    for (int i = 0; i < Database->banyak_kota; i++)
    {
        nama_kota[i].setFont(font);
        nama_kota[i].setString(Database->kota[i].nama);
        nama_kota[i].setPosition(sf::Vector2f((float)x_offset + Database->kota[i].x - pembuat_ngiri, (float)y_offset - Database->kota[i].y + 40));
        nama_kota[i].setCharacterSize(20);
        nama_kota[i].setFillColor(sf::Color(18, 169, 235, 255));

        kota[i].setFillColor(sf::Color(32, 178, 252, 24));
        kota[i].setRadius(30);
        kota[i].setOrigin(50, 25);
        kota[i].setOutlineColor(sf::Color(3, 227, 152, 200));
        kota[i].setOutlineThickness(2);
        kota[i].setPosition((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y);

        if (Database->kota[i].tanda_akhir_hubungan_kota > -1)
        {
            // printf("mrene peng piro? %d\n", j);
            temp_j = 0;
            while (j < penghitung_banyak_hubungan)
            {
                if (temp_j > Database->kota[i].tanda_akhir_hubungan_kota)
                    break;

                sudut_hubung = findDirection((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y);

                garis_hubung[j].setOrigin(0, 2.5);
                // garis_hubung[j].setSize(Vector2f(150 + fabs(0 - fmod(fabs(sudut_hubung), 90)) - 20, 5));
                garis_hubung[j].setSize(Vector2f(Database->pitagoras((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y), 5));
                garis_hubung[j].setPosition((float)x_offset + Database->kota[i].x - 18, (float)y_offset - Database->kota[i].y + 5);
                garis_hubung[j].rotate(sudut_hubung);
                garis_hubung[j].setFillColor(sf::Color(198, 16, 235, 64));
                garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                garis_hubung[j].setOutlineThickness(1);

                x_arah = x_offset + Database->kota[i].x - 18 + ((float)(x_offset + Database->kota[i].x - 18 + x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x - 18) / 2);
                x_arah /= 2;
                y_arah = y_offset - Database->kota[i].y + 5 + ((float)(y_offset - Database->kota[i].y + 5 + y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y + 5) / 2);
                y_arah /= 2;

                arah[j].setOrigin(15, 7.5);
                arah[j].setPointCount(3);
                arah[j].setRadius(15);
                // arah[j].setPosition((float)(x_offset + Database->kota[i].x + x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x) / 2, (float)(y_offset - Database->kota[i].y + y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y) / 2);
                arah[j].rotate(sudut_hubung + 90);
                arah[j].setPosition(x_arah, y_arah);
                arah[j].setFillColor(sf::Color(255, 16, 35, 69));
                arah[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                arah[j].setOutlineThickness(2);

                // printf("dijktrsa %d\n", dijkstra);
                if (dijkstra)
                {
                    // printf("melbu kene pirang kali? %d\n", j);
                    if (termasukJalur(i, Database->kota[i].hubungan_kota[temp_j]))
                    {
                        // printf("seng masuk %d %d", i, Database->kota[i].hubungan_kota[temp_j]);
                        garis_hubung[j].setOutlineColor(sf::Color::Green);
                        garis_hubung[j].setOutlineThickness(1);
                        arah[j].setOutlineColor(sf::Color(12, 255, 46, 255));
                        // arah[j].setFillColor(sf::Color(12, 255, 128, 100));
                    }
                    if (termasukJalur(Database->kota[i].hubungan_kota[temp_j], i))
                    {
                        garis_hubung[j].setOutlineColor(sf::Color::Green);
                        garis_hubung[j].setOutlineThickness(1);
                    }
                    // else
                    // {
                    //     // garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                    //     // garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                    //     // garis_hubung[j].setOutlineThickness(1);
                    // }
                }
                // else
                // {
                //     // garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                //     // garis_hubung[j].setOutlineColor(sf::Color(198, 16, 235, 255));
                //     // garis_hubung[j].setOutlineThickness(1);
                // }

                // printf("anune %d %d %d\n", j, i, Database->kota[i].hubungan_kota[temp_j]);
                // printf("koor e: %f %f %f %f\n", (float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y);
                // printf("%d %f %f\n", j, (float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y);
                // printf("sudut? %f\n", findDirection((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y));
                j++;
                temp_j++;
            }
        }
    }
    // printf("\n");

    // printf("\n");
    // printf("cobak: %f \n",garis_hubung[0].getPosition());
    // cout << "duawkdawukwadkudakw" << garis_hubung[0].getPosition() << endl;
    // printf("iki tekan tengah\n");

    // menimpa dengan hasil dari dijkstra
    if (dijkstra)
    {
        for (size_t i = 0; i < dijkstra_buffer.size(); i++)
        {
            // printf("%d -> ", dijkstra_buffer[i]);
            // kota[dijkstra_buffer[i]].setFillColor(sf::Color::Green);
            kota[dijkstra_buffer[i]].setOutlineColor(sf::Color::Green);
            kota[dijkstra_buffer[i]].setOutlineThickness(3);
            // if (i < dijkstra_buffer.size() - 1)
            // {
            //     garis_hubung[i].setFillColor(sf::Color::Green);
            // }
        }
    }

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            return;
            // break;
        }
        window.clear();

        for (int i = 0; i < penghitung_banyak_hubungan; i++)
        {
            window.draw(garis_hubung[i]);
            window.draw(arah[i]);
        }
        // window.draw(debug);
        // window.draw(garis_hubung[0]);
        for (int i = 0; i < Database->banyak_kota; i++)
        {
            window.draw(kota[i]);
            window.draw(nama_kota[i]);
        }
        window.display();
    }
    return;
}
void Executor::gambarHubungan(int x1, int y1, int x2, int y2)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2)),
    };
    line->color = sf::Color::Red;
    window.draw(line, 6, sf::Lines);
}
void Executor::gambarKota()
{
}

bool Executor::termasukJalur(int src, int dst)
{
    for (size_t i = 0; i < dijkstra_buffer.size() - 1; i++)
    {
        // printf("%d dan %d\n", dijkstra_buffer[i], dijkstra_buffer[i + 1]);
        if (dijkstra_buffer[i] == src && dijkstra_buffer[i + 1] == dst)
        {
            return 1;
        }
    }
    return 0;
}

float Executor::findDirection(float xpos, float ypos, float xtarget, float ytarget)
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