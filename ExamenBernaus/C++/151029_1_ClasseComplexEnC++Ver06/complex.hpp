#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

using namespace std;

class Complex {

    private:
        double pr, pi;
    public:
        Complex (const double &pr, const double &pi );
        Complex (const double &pr);
        Complex ();

        void visualitzar();

        Complex operator-(const Complex &c);
        Complex operator*(const Complex &c);
        Complex operator/(const Complex &c);

        double getPr() {return pr;}
        double getPi() {return pi;}

//C++ no admet sobrecàrrega d'operadors i fer-los static
//        static Complex operator+(const Complex &c1, const Complex &c2);
        static Complex suma(const Complex &c1, const Complex &c2);
};

// El mateix caldria fer-ho per -, * i /


#endif
