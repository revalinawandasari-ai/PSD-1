#include <iostream>
using namespace std;

const int MAX = 5;
string queueBank[MAX];
int frontIdx = -1, rearIdx = -1;

bool isEmpty() { return frontIdx == -1; }
bool isFull()  { return (rearIdx + 1) % MAX == frontIdx; }

void enqueue(string name) {
    if (isFull()) {
        cout << "Antrian penuh!\n";
        return;
    }
    if (isEmpty()) frontIdx = rearIdx = 0;
    else rearIdx = (rearIdx + 1) % MAX;

    queueBank[rearIdx] = name;
    cout << name << " masuk antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << queueBank[frontIdx] << " selesai dilayani.\n";
    if (frontIdx == rearIdx)
        frontIdx = rearIdx = -1;
    else
        frontIdx = (frontIdx + 1) % MAX;
}

void showQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Daftar antrian: ";
    int i = frontIdx;
    while (true) {
        cout << queueBank[i] << " ";
        if (i == rearIdx) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    enqueue("Andi");
    enqueue("Budi");
    enqueue("Citra");
    showQueue();
    dequeue();
    showQueue();

    return 0;
}