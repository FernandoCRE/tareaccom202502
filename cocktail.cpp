#include <iostream>
using namespace std;

void cocktail_sort(int* p, int* q) {
    if (p > q) return; 

    while (p < q) {
        // izquierda - derecha
        for (int* a = p; a < q; a++) {
            int* b = a + 1;
            if (*a > *b) {
                int c = *a;
                *a = *b;
                *b = c;
            }
        }
        q--; 

        // derecha - izquierda
        for (int* a = q; a > p; a--) {
            int* b = a - 1;
            if (*a < *b) {
                int c = *a;
                *a = *b;
                *b = c;
            }
        }
        p++; 
    }
}

int main() {
    int arr[] = { 3,23,20,25,24,11,21,12,26,30,25,3 };
    int n = 12;

    cocktail_sort(arr, arr + n - 1);

    cout << "arreglo ordenado: ";
    for (int* x = arr; x <= arr + n - 1; x++) {
        cout << *x << " ";
    }
    cout << endl;

    return 0;
}
