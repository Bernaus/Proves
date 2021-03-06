#ifndef __FITXALLIBRE__HPP__
#define __FITXALLIBRE__HPP__

#include "..\\Ra2C++\\Fitxa.hpp"

class FitxaLlibre: public Fitxa {
    friend ostream &operator<< (ostream &os, FitxaLlibre &f);
private:
    char * autor;
    int anyCreacio;
public:
        FitxaLlibre(char *referencia,char *titol,Data dataAlta,char *autor);
        FitxaLlibre(char *referencia,char *titol,double cost,Data dataAlta,char *autor);
        FitxaLlibre(char *referencia,char *titol,Data dataAlta,char *autor,Data anyCreacio);
        FitxaLlibre(char *referencia,char *titol,double cost,Data dataAlta,char *autor,Data anyCreacio);

        virtual char * getAutor();
        virtual void setAutor(char *nautor);
        virtual int getAnyCreacio();
        virtual void setAnyCreacio(int nanyCreacio);

}
#endif
