#include <iostream>
#include <conio.h>
#include <locale.h>
#include "..\\151029_1_ClasseComplexEnC++Ver06\\complex.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");

    Complex t[4];

    t[0]= new Complex(1,4);
    t[1]= new Complex(4,1);
    t[2]= new Complex(1);
    t[3]= new Complex(3);

    cout << "Visualitzaciķ de la taula de complexos amb la distāncia en dies a avui." << endl;

    Complex cs = new Complex(2,-7);

    for(int i=0;i<4;i++){
        cout << "Complex: " << t[i] << " Suma Complex + 2-7i: " << Complex.suma(t[i],cs) <<endl;
    }

    for(int i=0;i<4;i++){
       delete []t;
    }

    delete cs;

}
