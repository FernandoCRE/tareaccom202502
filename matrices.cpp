#include <iostream>
using namespace std;

void multi(int (*p)[3][3]) {
    int *P = &p[0][0][0]; // A[0]
    int *Q = &p[1][0][0]; // A[1]
    int *R = &p[2][0][0]; // A[2] 

    for (int i = 0; i < 3; ++i) {                // 
        int *filaA = P + i*3;
        int *R_ini = R + i*3;                    // R-ini (inicio de esa fila en C)

        for (int j = 0; j < 3; ++j) {            // columnas de B
            int suma = 0;
            int *a = filaA;                      // avanza por la fila de A
            int *b = Q + j;                      // arranca en B[0][j]
            for (int k = 0; k < 3; ++k) {
                suma += (*a) * (*b);
                ++a;                             // siguiente de la fila
                b += 3;                          // siguiente de la columna (salto de 3)
            }
            R_ini[j] = suma;                     // 
        }
    }
}

int main() {
    int a[3][3][3] = {
        { {1,2,3}, {4,5,6}, {7,8,9} },     // A[0]
        { {9,8,7}, {6,5,4}, {3,2,1} },     // A[1]
        { {0,0,0}, {0,0,0}, {0,0,0} }      // A[2] 
    };

    multi(a);

    cout << "matriz resultado C:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) cout << a[2][i][j] << ' ';
        cout << '\n';
    }
}
