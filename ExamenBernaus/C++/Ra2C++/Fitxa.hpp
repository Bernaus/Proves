#ifndef __FITXA_HPP__
#define __FITXA_HPP__
#include "..\\151114_0_ClasseDataEnC++\\Data.hpp"
using namespace std;

class Fitxa {

    friend ostream &operator<< (ostream &os, const Fitxa &f);

    private:
        char * referencia;
        char * titol;
        double cost;
        Data dataAlta;

        void setReferencia(char *referencia);

    public:

        Fitxa(char *referencia,char *titol,Data dataAlta);
        Fitxa(char *referencia,char *titol,double cost,Data dataAlta);


        void setTitol(char *titol);
        void setCost(double cost);
        void setDataAlta(Data dataAlta);

        int operator==(const Fitxa &);
        int operator!=(const Fitxa &);

        virtual ~Fitxa();
}

#endif
