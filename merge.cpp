#include <iostream>
using namespace std;

void mostrar(int* p, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

void mezclar(int* p, int* q) {
    
    while (p < q) {
        if (*p > *q) {
            int* a = p;
            int* b = q;
            
            while (a != q) {
                if (*a > *b) {
                    swap(*a, *b);
                }
                a++;
                b++;
            }
        }
        p++;
    }
}

int main() {
    int v[] = { 2, 4, 6, 8, 1, 3, 5, 7 };
    int n = sizeof(v) / sizeof(v[0]);

    cout << "array original: ";
    mostrar(v, n);

    mezclar(v, v + 4);

    cout << "array ordenado: ";
    mostrar(v, n);

    return 0;
}
