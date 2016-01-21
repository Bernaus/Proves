#include "..\\Ra2C++\\Fitxa.hpp"
#include "FitxaLlibre.hpp"

FitxaLlibre(char *referencia,char *titol,Data dataAlta,char *autor){
    Fitxa(referencia,titol,dataAlta);
    setAutor(autor);
}

FitxaLlibre(char *referencia,char *titol,double cost,Data dataAlta,char *autor){
    Fitxa(referencia,titol,cost,dataAlta);
    setAutor(autor);
}

FitxaLlibre(char *referencia,char *titol,Data dataAlta,char *autor,Data anyCreacio){
    Fitxa(referencia,titol,dataAlta);
    setAutor(autor);
    setAnyCreacio(anyCreacio);
}

FitxaLlibre(char *referencia,char *titol,double cost,Data dataAlta,char *autor,Data anyCreacio){
    Fitxa(referencia,titol,cost,dataAlta);
    setAutor(autor);
    setAnyCreacio(anyCreacio);
}

char * getAutor(){
    return autor;
}

void setAutor(char *nautor){
    strcpy(autor,nautor);
}

int getAnyCreacio(){
    return anyCreacio;
}

void setAnyCreacio(int nanyCreacio){
    anyCreacio = nanyCreacio;
}

ostream &operator<< (ostream &os, FitxaLlibre &f){
    os << *(Fitxa *)&f;

    os << " - Autor: " << f.autor << " - Any: " << f.anyCreacio;
    return os;
}
