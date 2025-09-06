#include <iostream>
using namespace std;

void multi(int (*m)[3][3]) {
    int* A = (int*)m[0]; 
    int* B = (int*)m[1]; 
    int* C = (int*)m[2]; 

    // filas de A
    for (int fila = 0; fila < 3; fila++) {
        int* filaA = A + fila * 3;   // puntero al inicio de la fila en A

        // columnas de B
        for (int col = 0; col < 3; col++) {
            int suma = 0;
            int* elemA = filaA;     
            int* elemB = B + col;   

            // filaA x columnaB
            for (int k = 0; k < 3; k++) {
                suma += (*elemA) * (*elemB);
                elemA++;        
                elemB += 3;     
            }

            *C = suma; // guardo en C
            C++;       // avanzo al siguiente elemento de C
        }
    }
}


int main() {
    int a[3][3][3] = {
        { {1,2,3}, {4,5,6}, {7,8,9} },   
        { {9,8,7}, {6,5,4}, {3,2,1} },   
        { {0,0,0}, {0,0,0}, {0,0,0} }    
    };

    multi(a);

    cout << "matriz resultado C:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[2][i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
}