#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "complex.hpp"
#include <iostream>



Complex::Complex (const double &pr, const double &pi ):pr(pr), pi(pi) {
    // Si no utilitzem pr(pr), pi(pi), fariem:
//    this->pr = pr;
//    this->pi = pi;
    // però és més ineficient
}

Complex::Complex (const double &pr):pr(pr),pi(0){
}

Complex::Complex ():pr(0),pi(0){
}

void Complex::visualitzar() {
    if (pr==0 && pi==0) {
        cout << "0"; return;
    }
    if (pi==0) {
        cout << pr; return;
    }
    if (pr==0) {
        cout << pi << "i"; return;
    }
    // Té part imaginària i potser part real
    if (pr!=0) {
        cout << pr;
    }
    if (pi>0) {
        cout << "+";
    }
    cout << pi << "i";
}

Complex Complex::operator-(const Complex &c){
    return Complex(pr - c.pr,pi - c.pi);
}

Complex Complex::operator*(const Complex &c){
    return Complex(pr*c.pr-pi*c.pi,pr*c.pi+pi*c.pr);
}

Complex Complex::operator/(const Complex &c){
	if (c.pr==0 && c.pi==0) {
		throw "Intent de dividir per ZERO!";
	}
    double den = c.pr*c.pr + c.pi * c.pi;
    Complex num = this->operator*(Complex(c.pr, -c.pi));
    return Complex(num.pr/den, num.pi/den);
}

Complex Complex::suma(const Complex &c1, const Complex &c2){
    return Complex(c1.pr+c2.pr, c1.pi+c2.pi);
}
