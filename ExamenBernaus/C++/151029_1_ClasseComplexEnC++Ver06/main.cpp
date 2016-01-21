#include <iostream>
#include <conio.h>
#include "complex.hpp"

using namespace std;

int main()
{
    Complex c1(2,-5), c2(0,-5), c3(2.1,-4.2);

    cout << "c1:"; c1.visualitzar(); cout << endl;
    cout << "c2:"; c2.visualitzar(); cout << endl;

    cout << "c1+c2:"; (Complex::suma(c1,c2)).visualitzar(); cout<<endl;

    Complex c4 = (Complex::suma(c1,c2)-c3)*c1/c2;
    cout << "c4: "; c4.visualitzar(); cout << endl;

    Complex c5 = Complex::suma(c3,10);
    cout << "c5: "; c5.visualitzar(); cout << endl;

//     Mentre que l'anterior assignació funciona correctament
//     la segúent ni tant sols compila!!!
     Complex c6 = Complex::suma(10,c3);
     cout << "c6: "; c6.visualitzar(); cout << endl;

	cout << "Programa finalitzat!" << endl;

    getch();    // Per execució des de TC
    return 0;
}

