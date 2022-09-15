#include <iostream>
#include <iomanip>
using namespace std;

void eliminacion_gaussiana(double a[3][3], double b[], int n){
    double m, suma, x[3];
    //triangulacion
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            m = a[i][k] / a[k][k];
            for (int j = k; j < n; j++){
                a[i][j] = a[i][j] - m * a[k][j];
            }
            b[i] = b[i] - m * b[k];
        }
    }

    //sustitucion hacia atras
    x[n-1] = b[n-1] / a[n-1][n-1];
    for (int i = n - 2; i >= 0; i--){
        suma = b[i];
        for (int j = i + 1; j < n; j++){
            suma = suma - a[i][j] * x[j];
        }
        x[i] = suma / a[i][i];
    }

    //matriz triangularizada
    cout << "matriz triangularizada" << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setprecision(5) << a[i][j] << "\t\t";
        }
        cout << setprecision(5) << b[i] << endl;
    }

    //solucion
    cout << "\n\n" << "vector solucion" << "\n";
    for (int i = 0; i < n; i++){
        cout << x[i] << endl;
    }
}

void gauss_seidel(){
    //resuelvo para ejercicio 1
    int iteracion=0;
    double x1=0, aux1=0, e1=0, x2=0, aux2=0, e2=0, x3=0, aux3=0, e3=0;
    //genero una g(x) para cada punto
    cout << "x1 \t\t |e1|" << endl;
    do{
        cout << setprecision(5) << x1 << "\t\t" << e1 <<  endl;
        // g(x) para x1
        x1 = (7.85 - ((-0.1 * x2) - (0.2 * x3)))/3;
        x2 = (19.3 - ((0.1 * x1) - (0.3 * x3)))/7;
        x3 = (71.4 - ((0.3 * x1) - (0.2 * x2)))/10;
        e1 = abs(aux1 - x1); // evaluo error
        aux1 = x1; // para errores siguientes
        iteracion++;
    } while(e1 >= 0.00001);
    aux1 = x1; //guardo en aux para inicializar de nuevo las variables

    x1=0; x2=0; x3=0;
    cout << "\n\n x2 \t\t |e2|" << endl;
    do{
        cout << setprecision(5) << x2 << "\t\t" << e2 <<  endl;
        // g(x) para x2
        x2 = (19.3 - ((0.1 * x1) - (0.3 * x3)))/7;
        x1 = (7.85 - ((-0.1 * x2) - (0.2 * x3)))/3;
        x3 = (71.4 - ((0.3 * x1) - (0.2 * x2)))/10;
        e2 = abs(aux2 - x2);
        aux2 = x2;
        iteracion++;
    }while(e2 >= 0.00001);
    aux2 = x2;

    x1=0; x2=0; x3=0;
    cout << "\n\n x3 \t\t |e3|" << endl;
    do{
        cout << setprecision(4) << x3 << "\t\t" << e3 <<  endl;
        // g(x) para x2
        x3 = (71.4 - ((0.3 * x1) - (0.2 * x2)))/10;
        x2 = (19.3 - ((0.1 * x1) - (0.3 * x3)))/7;
        x1 = (7.85 - ((-0.1 * x2) - (0.2 * x3)))/3;
        e3 = abs(aux3 - x3);
        aux3 = x3;
        iteracion++;
    }while(e3 >= 0.00001);
    aux3 = x3;

    cout << "\n\n vector solucion: { " << aux1 << " ; " << aux2 << " ; " << aux3 << " }" << endl;
}

void metodo_LU(double a[3][3], double b[], int n){
    double m, suma, x[3] = {0,0,0}, d[3];
    double l[3][3], u[3][3];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = u[i][j];
        }
    }

    for(int i=0; i<n; i++){
        x[i] = d[i];
    }

    //descomposicion de a en l y u
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            l[j][i] = u[j][i] / u[i][i];
            for (int k = i; k < n; k++){
                u[j][k] = u[j][k] - l[j][i] * u[i][k];
            }
        }
    }

    //sustitucion hacia adelante
    d[0] = b[0];
    for(int i=1; i<n; i++){
        d[i] = b[i];
        for(int j=1; j=i-1; i++){
            d[i] = d[i] - l[i][j] * d[j];
        }
    }

    //sustitucion hacia atras
    x[n] = d[n] / u[n][n];
    for(int i=n-1; i>0; i--){
        x[i] = d[i];
        for(int j=i+1; j<n; j++){
            x[i] = x[i] - u[i][j] * x[j];
        }
        x[i] = x[i] / u[i][i];
    }

    cout << "vector solucion: " << endl;
    for(int i=0; i<n; i++){
        cout << x[i] << " | ";
    }



}

int main() {
    int n = 3;
    cout << "GTP 2" << endl;
    int op = 0, aux = 0;
    do{
        cout << "elija el metodo que desea realizar:" << endl;
        cout << "1) Metodo de Eliminacion Gaussiana" << endl;
        cout << "2) Metodo de Gauss-Seidel" << endl;
        cout << "3) Metodo de la L-U" << endl;
        cin >> op;

        switch(op){
            case 1:
                cout << "elija el ejercicio que desea realizar" << endl;
                cout << "1) 2) 3) 4) 5)" << endl;
                cin >> aux;
                if(aux == 1){
                    //ejercicio 1
                    double a[3][3] = {{3,   -0.1, -0.2},
                                      {0.1, 7,    -0.3},
                                      {0.3, -0.2, 10}};
                    double b[3] = {7.85, 19.30, 71.40};
                    eliminacion_gaussiana(a, b, n);
                }
                if(aux == 2) {
                    double a[3][3] = {{10, -3, 6},
                                      {1,  8,  -2},
                                      {-2, 4,  -9}};
                    double b[3] = {24.5, -9, -50};
                    eliminacion_gaussiana(a, b, n);
                }
                if(aux == 3){
                    double a[3][3] = {{1, 7, -3},
                                      {4,  -4,  9},
                                      {12, -1,  3}};
                    double b[3] = {-51, 61, 8};
                    eliminacion_gaussiana(a, b, n);
                }
                if(aux == 4){
                    double a[3][3] = {{-6, 0, 12},
                                      {6,  8,  0},
                                      {4, -1,  -1}};
                    double b[3] = {60, 44, -2};
                    eliminacion_gaussiana(a, b, n);
                }
                if(aux == 5){
                    double a[3][3] = {{5, 4, 0},
                                      {4,  -3,  7},
                                      {0, 12,  2}};
                    double b[3] = {25, 3, 36};
                    eliminacion_gaussiana(a, b, n);
                }
                break;
            case 2:
                cout << "resultado para ejercicio 1" << endl;
                gauss_seidel();
                break;
            case 3:
                cout << "resultado para ejercicio 1:" << endl;
                double a[3][3] = {{3,   -0.1, -0.2},
                                  {0.1, 7,    -0.3},
                                  {0.3, -0.2, 10}};
                double b[3] = {7.85, 19.30, 71.40};
                metodo_LU(a, b, n);
                break;
        }
    }while(op!=3);
}
