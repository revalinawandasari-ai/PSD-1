#include <iostream>
#include <string>
using namespace std;

int main() {
    string tamu[] = {"Andi", "Budi", "Citra Kirana", "Dewi", "Eko", "Fajar"};
    const int n = sizeof(tamu)/sizeof(tamu[0]);

    string target;
    cout << "Masukkan nama tamu yang ingin dicari: ";
    getline(cin, target);

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (tamu[i] == target) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        cout << "Nama ditemukan di posisi ke-" << pos+1 << endl;
    else
        cout << "Nama tidak ada dalam daftar." << endl;

    return 0;
}