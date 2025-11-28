#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    string position;
    int point;
    int assist;
    int rebound;
};

struct Statistic {
    float avgPoint;
    float avgAssist;
    float avgRebound;
};

Player players[20];
int totalPlayers = 0;


int getBestPlayer(int index, int bestIndex) {
    if (index == totalPlayers) 
        return bestIndex;

    int currentTotal = players[index].point + players[index].assist + players[index].rebound;
    int bestTotal = players[bestIndex].point + players[bestIndex].assist + players[bestIndex].rebound;

    if (currentTotal > bestTotal) {
        bestIndex = index;
    }

    return getBestPlayer(index + 1, bestIndex);
}

Statistic hitungRata() {
    Statistic s;

    if (totalPlayers == 0) { 
        s.avgPoint = s.avgAssist = s.avgRebound = 0;
        return s;
    }

    int sumP = 0, sumA = 0, sumR = 0;

    for (int i = 0; i < totalPlayers; i++) {
        sumP += players[i].point;
        sumA += players[i].assist;
        sumR += players[i].rebound;
    }

    s.avgPoint = (float)sumP / totalPlayers;
    s.avgAssist = (float)sumA / totalPlayers;
    s.avgRebound = (float)sumR / totalPlayers;

    return s;
}

int main() {
    int pilih;

    do {
        cout << "Statistik Tim Basket UPN"<<endl;
        cout << "1. Tambah Pemain" << endl;
        cout << "2. Lihat Data Pemain" << endl;
        cout << "3. Hitung Statistik Rata-rata Tim" << endl;
        cout << "4. Best Player" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih : "; cin >> pilih;
        cin.ignore();

        switch (pilih) {

        case 1: {
            if (totalPlayers >= 20) {
                cout << "Tidak valid!, pemain sudah 20!" << endl;
                break;
            }

            cout << "\nMenambahkan data pemain" << endl;
            cout << "Nama Player : "; getline(cin, players[totalPlayers].name);
            cout << "Posisi      : "; getline(cin, players[totalPlayers].position);
            cout << "Points      : "; cin >> players[totalPlayers].point;
            cout << "Assists     : "; cin >> players[totalPlayers].assist;
            cout << "Rebounds    : "; cin >> players[totalPlayers].rebound;
            cin.ignore();

            totalPlayers++;
            cout << endl;
            cout << "Berhasil menambahkan pemain!" << endl;
            break;
        }

        case 2: {
            if (totalPlayers == 0) {
				cout << endl;
                cout << "Belum ada data pemain." << endl;
                break;
            }

            cout << endl << "Daftar pemain:" << endl;
            for (int i = 0; i < totalPlayers; i++) {
                cout << "Nama     : " << players[i].name << endl;
                cout << "Posisi   : " << players[i].position << endl;
                cout << "Points   : " << players[i].point << endl;
                cout << "Assists  : " << players[i].assist << endl;
                cout << "Rebounds : " << players[i].rebound << endl;
                cout << endl;
            }
            break;
        }

        case 3: {
            if (totalPlayers == 0) {
                cout << "Belum ada data pemain." << endl;
                break;
            }

            Statistic s = hitungRata();

            cout << "\n== Statistik Tim ==" << endl;
            cout << "Rata-rata Point   : " << s.avgPoint << endl;
            cout << "Rata-rata Assist  : " << s.avgAssist << endl;
            cout << "Rata-rata Rebound : " << s.avgRebound << endl;
            break;
        }

        case 4: {
            if (totalPlayers == 0) {
                cout << "\nBelum ada data pemain" << endl;
                break;
            }

            int best = getBestPlayer(0, 0);

            cout << endl << "Best Player" << endl;
            cout << "Nama        : " << players[best].name << endl;
            cout << "Posisi      : " << players[best].position << endl;
            cout << "Points      : " << players[best].point << endl;
            cout << "Assists     : " << players[best].assist << endl;
            cout << "Rebounds    : " << players[best].rebound << endl;
            break;
        }

        case 5:
            cout << "Keluar program.."<<endl;
            break;

        default:
            cout << "Pilihan tidak valid!"<<endl;
            cout << "Wleeeeeee"<<endl;
        }

    } while (pilih != 5);

    return 0;
}

