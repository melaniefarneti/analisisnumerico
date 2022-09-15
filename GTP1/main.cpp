#include <iostream>
#include "cmath"
#include "iomanip"
using namespace std;

double funcion(double x, int op){
    if(op == 1){
        return exp(-x)-x;
    }
    if(op == 2){
        return -0.8740*pow(x, 2) + 1.750*x - 2.627;
    }
    if (op == 3){
        return -23.330 + 79.350*x - 88.090*pow(x, 2) + 41.600*pow(x, 3) - 8.6800*pow(x, 4) + 0.658*pow(x, 5);
    }
    if (op == 4){
        return log(x) - 5;
    }
    if (op == 5){
        return (1 - 0.6*x)/x;
    }
    return 0;
}

double error(int op){
    if(op == 1 || op == 2){
        return pow(10, -3);
    }
    if (op == 3 || op == 4 || op == 5){
        return pow(10, -4);
    }
    return 0;
}

//metodo de la biseccion
void metodo_biseccion(double a, double b, int op){

    //paso 1: a = limite inferior y b = limite superior
    double er = 0, xr = b, aux; //ea = error relativo
    int iteracion = 0, imax = 100; //imax = numero de iteraciones maxima
                                   // para evitar bucle infinito (por las dudas)

    cout << "i \t\t a \t\t b \t\t xr \t\t  f(a) \t\t f(xr) \t\t |e|" << endl;
    do{
        aux = xr; //guardo el valor para calcular el error
        //paso 2: me aproximo a la raiz mediante la formula
        //   de la biseccion (punto medio del intervalo)
        xr = (a + b) / 2;
        cout << setprecision(4) << iteracion << "\t\t" << a << "\t\t" << b << " \t\t" << xr << "\t\t" << setprecision(3) << funcion(a, op) << "\t\t" << setprecision(3) << funcion(xr, op) << "\t\t" << setprecision(3) << er << endl;
        if(xr != 0) { //si xr = 0, entonces la raiz es igual a
                      // xr y termina el calculo
            er = abs(xr - aux);
        }
        iteracion += 1;
        if(funcion(a, op) * funcion(xr, op) < 0) {
            //entonces la raiz se encuentra dentro del subintervalo
            // inferior (o izquierdo) por lo tanto lo igualo a b
            b = xr;
        }
        else {
            //la raiz se encuentra dentro del subintervalo superior
            // (o derecho) por lo tanto lo igualo a a
            a = xr;
        }
    } while (er > error(op) || iteracion >= imax);
}

//metodo del punto fijo
//busqueda de g(x)
double gx(double x, int op){
    if(op == 2){
        return sqrt((1.75*x + 2.627)/0.874);
    }
    return 0;
}

void metodo_puntofijo(double a, int op){
    double xr = a, er = 0, aux;
    int iteracion = 0, max = 100;

    cout << "i \t\t xr \t\t f(xr) \t\t |e|" << endl;
    do{
        aux = xr; //guardo el valor en una auxiliar para poder calcular el error
        xr = gx(a, op);  //evaluo en la gx
        cout << iteracion << " \t\t" << setprecision(5) << aux << "\t\t" << setprecision(4) << xr << "\t\t" << setprecision(4) << er << endl;
        if(xr != 0){
            er = abs(xr-a);
            iteracion ++;
            a = xr;
        }
    }while(er > error(op) || iteracion >= max);
}

//metodo de newton-rapson
void metodo_newtonrapson(double a, int op3){
    double xr = a, er = 0,fx, df, aux;
    int iteracion = 0, max = 100;

    cout << "i \t\t xr \t\t f(xr) \t\t f'(xr) \t\t |e|" << endl;
    do{
        aux = xr; //guardo en una auxiliar para poder calcular el error
        fx = funcion(xr, op3); // evaluo en la funcion
        df = -exp(-xr)-1; // calculo la derivada y lo evaluo
        cout << iteracion << " \t\t" << setprecision(4) << xr << "\t\t" << setprecision(3) << fx << "\t\t" << setprecision(4) << df << "\t\t" << setprecision(3) << er << endl;
        xr = aux - (fx / df); // formula reiterada de newton-rapson
        if(xr != 0){
            er = abs(xr - a);
            iteracion ++;
            a = xr;
        }
    }while(er > error(op3) || iteracion >= max);
}

//metodo de la secante
void metodo_secante(double x0, double x1, int op4){
    double xr = x1, er = 0, fx0, fx1, aux;
    int iteracion = 0, max = 100;

    cout << "i \t\t xr \t\t f(xr) \t\t |e|" << endl;
    fx0 = funcion(x0, op4); //evaluo en los extremos del intervalo
    fx1 = funcion(x1, op4);
    cout << iteracion << " \t\t" << setprecision(4) << x0 << "\t\t" << setprecision(3) << fx0 << "\t\t" << setprecision(3) << er << endl;
    cout << iteracion << " \t\t" << setprecision(4) << x1 << "\t\t" << setprecision(3) << fx1 << "\t\t" << setprecision(3) << er << endl;

    do{
        fx0 = funcion(x0, op4); //los valores de x0 y x1 cambian a medida que avanza en las iteraciones
        fx1 = funcion(x1, op4);
        aux = xr; //guardo en una auxiliar para calcular el error
        xr = x1 - (fx1 * (x0 - x1))/(fx0-fx1); // formula reiterada del valor medio (secante)
        if(xr != 0){
            er = abs(xr - aux);
            iteracion ++;
            x0 = x1; //cambio para calcular la proxima iteracion
            x1 = xr;
            cout << iteracion << " \t\t" << setprecision(4) << xr << "\t\t" "\t\t" << setprecision(3) << er << endl;
        }
    }while(er > error(op4) || iteracion >= max);
}

int main() {
    double a, b;
    int aux = 0, op1 = 0, op2=0, op3=0, op4=0;

    do{
        cout << "elija el metodo que desea utilizar: " << endl;
        cout << "1) metodo de la biseccion" << endl;
        cout << "2) metodo del punto fijo" << endl;
        cout << "3) metodo de newton-raphson" << endl;
        cout << "4) metodo de la secante" << endl;
        cout << "opcion:" << endl;

        cin >> aux;
        switch (aux){
            case 1:
                cout << "elija el ejercicio que desea realizar: " << endl;
                cout << "1) e^(-x) - x" << endl;
                cout << "opcion: " << endl;
                cin >> op1;

                cout << "ingrese a: " << endl;
                cin >> a;
                cout << "ingrese b: " << endl;
                cin >> b;

                metodo_biseccion(a, b, op1);
                break;

            case 2:
                cout << "elija el ejercicio que desea realizar: " << endl;
                cout << "2) -0,8740x^2 + 1,750x - 2,627" << endl;
                cout << "opcion: " << endl;
                cin >> op2;

                cout << "ingrese a: " << endl;
                cin >> a;

                metodo_puntofijo(a, op2);
                break;

            case 3:
                cout << "elija el ejercicio que desea realizar: " << endl;
                cout << "1) e^(-x) - x" << endl;
                cout << "opcion: " << endl;
                cin >> op3;

                cout << "ingrese a: " << endl;
                cin >> a;

                metodo_newtonrapson(a, op3);
                break;

            case 4:
                cout << "elija el ejercicio que desea realizar: " << endl;
                cout << "1) e^(-x) - x" << endl;
                cout << "opcion: " << endl;
                cin >> op4;

                cout << "ingrese a: " << endl;
                cin >> a;
                cout << "ingrese b: " << endl;
                cin >> b;

                metodo_secante(a, b, op4);
                break;
            default: cout << "no es opcion valida" << endl;
        }
    }while(aux!=4);
    return 0;
}