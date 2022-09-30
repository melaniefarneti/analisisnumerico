#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void minimoscuadrados(float x[], float y[], float xy[], float x2[], int n){
    float sx=0, sy=0, sx2=0, sxy=0;
    for (int i = 0; i < n; i++){
        x2[i] = x[i] * x[i];
        xy[i] = x[i] * y[i];
        sx+=x[i];
        sy+=y[i];
        sx2+=x2[i];
        sxy+=xy[i];
    }

    cout << "datos: " << endl;
    cout << "/********************************************/" << endl;
    cout << "x \t\t y \t\t x^2 \t\t xy " << endl;

    for (int i = 0; i < n; i++){
        cout << setprecision(4) << x[i] << "\t\t" << y[i] << "\t\t" << x2[i] << " \t\t" << xy[i] << endl;
    }
    cout << "/********************************************/" << endl;
    cout << setprecision(4) << sx << "\t\t" << sy << "\t\t" << sx2 << " \t\t" << sxy << endl;


    float a1, a0;
    a1 = (n*sxy - sx*sy)/(n*sx2 - (sx*sx));
    a0 = (sy/n - a1*(sx/n));

    cout << "la recta que mejor se apoxima es: " << a1 << "x + " << a0 << endl;
}

void exponencial(float x[], float y[], float xy[], float x2[], int n){
    float lny[n], sx=0, sy=0, sx2=0, sxy=0;
    for (int i = 0; i < n; i++){
        x2[i] = x[i] * x[i];
        lny[i] = log(y[i]);
        xy[i] = x[i] * log(y[i]);
        sx+=x[i];
        sy+=lny[i];
        sx2+=x2[i];
        sxy+=xy[i];
    }

    cout << "datos: " << endl;
    cout << "/********************************************/" << endl;
    cout << "x \t\t y \t\t Ln(y) \t\t x^2 \t\t xy' " << endl;

    for (int i = 0; i < n; i++){
        cout << setprecision(4) << x[i] << "\t\t" << y[i] << "\t\t" << lny[i] << "\t\t" << x2[i] << " \t\t" << xy[i] << endl;
    }
    cout << "/********************************************/" << endl;
    cout << setprecision(4) << sx << "\t\t\t\t" << sy << "\t\t" << sx2 << " \t\t" << sxy << endl;


    float a1, a0, b, a;
    a1 = (n*sxy - sx*sy)/(n*sx2 - (sx*sx));
    a0 = (sy/n - a1*(sx/n));

    b = a1;
    a =  exp(a0);

    cout << "la funcion Ae^Bx que mejor se apoxima es: " << a << "e^" << b << "x" << endl;

}

void potencial(float x[], float y[], float xy[], float x2[], int n){
    float logx[n], logy[n], sx=0, sy=0, sx2=0, sxy=0;
    for (int i = 0; i < n; i++){
        logx[i] = log10(x[i]);
        logy[i] = log10(y[i]);
        x2[i] = logx[i] * logx[i];
        xy[i] = logx[i] * logy[i];
        sx+=logx[i];
        sy+=logy[i];
        sx2+=x2[i];
        sxy+=xy[i];
    }

    cout << "datos: " << endl;
    cout << "/********************************************/" << endl;
    cout << "x \t\t log(x) \t\t y \t\t log(y) \t\t x^2' \t\t x'y' " << endl;

    for (int i = 0; i < n; i++){
        cout << setprecision(4) << x[i] << "\t\t" << logx[i] << "\t\t" << y[i] << "\t\t" << logy[i] << "\t\t" << x2[i] << " \t\t" << xy[i] << endl;
    }
    cout << "/********************************************/" << endl;
    cout << setprecision(4) << "\t\t" << sx << "\t\t\t\t" << sy << "\t\t" << sx2 << " \t\t" << sxy << endl;


    float a1, a0, b, a;
    a1 = (n*sxy - sx*sy)/(n*sx2 - (sx*sx));
    a0 = (sy/n - a1*(sx/n));

    b = a1;
    a = pow(10, a0);
    cout << "la funcion Ax^B que mejor se apoxima es: " << a << "x^" << b << endl;
}

void crecimiento(float x[], float y[], float xy[], float x2[], int n){
    float xaux[n], yaux[n], sx=0, sy=0, sx2=0, sxy=0;
    for (int i = 0; i < n; i++){
        xaux[i] = 1/x[i];
        yaux[i] = 1/y[i];
        x2[i] = xaux[i] * xaux[i];
        xy[i] = xaux[i] * yaux[i];
        sx+=xaux[i];
        sy+=yaux[i];
        sx2+=x2[i];
        sxy+=xy[i];
    }

    cout << "datos: " << endl;
    cout << "/********************************************/" << endl;
    cout << "x \t\t 1/x \t\t y \t\t 1/y \t\t x^2' \t\t x'y' " << endl;

    for (int i = 0; i < n; i++){
        cout << setprecision(4) << x[i] << "\t\t" << xaux[i] << "\t\t" << y[i] << "\t\t" << yaux[i]  << "\t\t" << x2[i] << " \t\t" << xy[i] << endl;
    }
    cout << "/********************************************/" << endl;
    cout << setprecision(4) << "\t\t" << sx << "\t\t\t\t" << sy << "\t\t" << sx2 << " \t\t" << sxy << endl;


    float a1, a0, b, a;
    a1 = (n*sxy - sx*sy)/(n*sx2 - (sx*sx));
    a0 = (sy/n - a1*(sx/n));

    a = 1/a0;
    b = a1*a;

    cout << "la funcion A(x/B+x) que mejor se apoxima es: " << a << "(x/" << b << "+x)" << endl;
}

int main() {
    cout << "GTP3" << endl;
    int op = 0, aux = 0;
    do {
        cout << "elija el metodo que desea realizar:" << endl;
        cout << "- metodos lineales" << endl;
        cout << "1) Regresion lineal por minimos cuadrados" << endl;
        cout << "- metodos no lineales" << endl;
        cout << "2) Modelo exponencial: y=Ae^Bx" << endl;
        cout << "3) Metodo potencial: y=Ax^B" << endl;
        cout << "4) Modelo de crecimiento" << endl;

        cin >> op;
    }while (op > 5);


    switch(op){
        case 1:
            cout << "elija el ejercicio que desea realizar" << endl;
            cout << "1) 2) 4) 5)" << endl;
            cin >> aux;

            if(aux == 1){
                int n=7;
                float x[7] = {1, 2, 3, 4, 5, 6, 7};
                float y[7] = {0.5, 2.5, 2, 4, 3.5, 6, 5.5};
                float xy[7], x2[7];

                minimoscuadrados(x, y, xy, x2, n);
            }
            if(aux == 2){
                int n=10;
                float x[10] = {1, 3, 5, 7, 10, 12, 13, 16, 18, 20};
                float y[10] = {3, 2, 6, 6, 8, 7, 10, 9, 12, 10};
                float xy[10], x2[10];

                minimoscuadrados(x, y, xy, x2, n);
            }
            if(aux == 4){
                int n=7;
                float x[7] = {1, 2, 2.5, 4, 6, 8, 8.5};
                float y[7] = {0.4, 0.7, 0.8, 1, 1.2, 1.3, 1.4};
                float xy[7], x2[7];

                minimoscuadrados(x, y, xy, x2, n);
            }
            if(aux == 5){
                int n=7;
                float x[7] = {0.05, 0.4, 0.8, 1.2, 1.6, 2, 2.4};
                float y[7] = {550, 750, 1000, 1400, 2000, 2700, 3750};
                float xy[7], x2[7];

                minimoscuadrados(x, y, xy, x2, n);
            }
            break;
        case 2:
            cout << "elija el ejercicio que desea realizar" << endl;
            cout << "3)" << endl;
            cin >> aux;
            if(aux == 3){
                int n=5;
                float x[5] = {1, 2, 3, 4, 5};
                float y[5] = {0.5, 1.7, 3.4, 5.7, 8.4};
                float xy[5], x2[5];

                exponencial(x, y, xy, x2, n);
            }
            break;
        case 3:
            cout << "elija el ejercicio que desea realizar" << endl;
            cout << "3)" << endl;
            cin >> aux;
            if(aux == 3){
                int n=5;
                float x[5] = {1, 2, 3, 4, 5};
                float y[5] = {0.5, 1.7, 3.4, 5.7, 8.4};
                float xy[5], x2[5];

                potencial(x, y, xy, x2, n);
            }
            break;
        case 4:
            cout << "elija el ejercicio que desea realizar" << endl;
            cout << "4)" << endl;
            cin >> aux;
            if(aux == 4){
                int n=7;
                float x[7] = {1, 2, 2.5, 4, 6, 8, 8.5};
                float y[7] = {0.4, 0.7, 0.8, 1, 1.2, 1.3, 1.4};
                float xy[7], x2[7];

                crecimiento(x, y, xy, x2, n);
            }
            break;
    }
    return 0;
}
