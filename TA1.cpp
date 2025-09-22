#include <iostream>
using namespace std;

int main() {
    int stok[3][2];

    cout << "Masukkan stok barang (Buku dan Pensil) selama 3 hari:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Hari ke-" << i+1 << ":\n";
        cout << "  Buku  : ";
        cin >> stok[i][0];
        cout << "  Pensil: ";
        cin >> stok[i][1];
    }

    cout << "\nData stok barang:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Hari ke-" << i+1 
             << " -> Buku: " << stok[i][0] 
             << ", Pensil: " << stok[i][1] << endl;
    }

    return 0;
}
