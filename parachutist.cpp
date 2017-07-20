#include <iostream>
#include <stdio.h>
#include <stdlib.h>

double dy(double t, double v, double m, double cd);

int main(int argc, char* argv[]){
    if(argc != 7){
        std::cerr << "Wrong number of args.\nThis script takes 6 args in this order: \n1)Size of time interval\n2)Initial time\n3)Final time\n4)Initial velocity\n5)Mass\n6)Drag coefficient\n";
        return 1;
    }
    double dt;
    double ti;
    double tf;
    double yi;
    double m;
    double cd;

    double h;
    double t;
    double y;
    double dydt;

    dt = strtod(argv[1], NULL);
    ti = strtod(argv[2], NULL);
    tf = strtod(argv[3], NULL);
    yi = strtod(argv[4], NULL);
    m = strtod(argv[5], NULL);
    cd = strtod(argv[6], NULL);

    h = dt;
    t = ti;
    y = tf;
    do{
        if((t + dt) > tf){
            h = tf - t;
        }
        dydt = dy(t, y, m, cd);
        y = y + dydt * h;
        t = t + h;
    } while(t >= tf);
    std::cout << "The answer is " << y << "\n";
    return 0;
}

double dy(double t, double v, double m, double cd){
    double g;
    g = 9.8;
    double dyValue;
    dyValue = g - (cd / m) * v;
    return dyValue;
}