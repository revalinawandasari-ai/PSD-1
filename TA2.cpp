#include <iostream>
using namespace std;

void susunBuku(int rak[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < jumlah; j++) {
            if (rak[j] < rak[min_index]) {
                min_index = j;
            }
        }
        int temp = rak[i];
        rak[i] = rak[min_index];
        rak[min_index] = temp;
    }
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah buku di rak: ";
    cin >> jumlah;

    int rak[100];
    cout << "Masukkan tebal tiap buku (dalam halaman): ";
    for (int i = 0; i < jumlah; i++) {
        cin >> rak[i];
    }
    susunBuku(rak, jumlah);

    cout << "Urutan buku di rak setelah disusun: ";
    for (int i = 0; i < jumlah; i++) {
        cout << rak[i] << " ";
    }
    cout << "halaman" << endl;

    return 0;
}