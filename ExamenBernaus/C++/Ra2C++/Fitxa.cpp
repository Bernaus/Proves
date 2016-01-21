#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Fitxa.hpp"
#include "..\\151114_0_ClasseDataEnC++\\Data.hpp"

Fitxa::Fitxa(char *referencia,char *titol,Data dataAlta){
    setReferencia(referencia);
    setTitol(titol);
    setDataAlta(dataAlta);
}

Fitxa::Fitxa(char *referencia,char *titol,double cost,Data dataAlta){
    setReferencia(referencia);
    setTitol(titol);
    setCost(cost);
    setDataAlta(dataAlta);
}

void setReferencia(char *nreferencia){
    strcpy (referencia,nreferencia);
}

void setTitol(char *ntitol){
    strcpy (titol,ntitol);
}

void setCost(double ncost){
    cost=ncost;
}

void setDataAlta(Data ndataAlta){
    setData(ndataAlta);
}

int Fitxa::operator==(const Fitxa &f) {
    return !strcmp(referencia,f.referencia);
}

int Fitxa::operator!=(const Fitxa &f) {
    return strcmp(referencia,f.referencia);
}
/*
Data getDays(){
    return ;
}
*/
ostream &operator<< (ostream &os, const Fitxa &f){
    os << "Referència: " << f.referencia << " - Títol: " << f.titol << endl;
    return os;
}

