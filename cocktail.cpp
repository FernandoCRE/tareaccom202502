#include <iostream>
using namespace std;

void cocktail_sort(int* p, int* q) {
    if (p > q) return;

    bool cambio = true;

    while (p < q && cambio) {
        cambio = false;

        // izquierda a derecha
        for (int* a = p; a < q; a++) {
            int* b = a + 1;
            if (*a > *b) {
                int c = *a;
                *a = *b;
                *b = c;
                cambio = true;
            }
        }
        q--;

        // derecha a izquierda
        for (int* a = q; a > p; a--) {
            int* b = a - 1;
            if (*a < *b) {
                int c = *a;
                *a = *b;
                *b = c;
                cambio = true;
            }
        }
        p++;
    }
}

int main() {
    int arr[] = { 3, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]); 

    cocktail_sort(arr, arr + n - 1);

    cout << "arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
    cout << endl;

    return 0;
}
