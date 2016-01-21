#include "Data.hpp"
#include <limits.h>
#include <iostream>
#include <ctime>

using namespace std;

ostream &operator<<(ostream &os, Data &d) {
	os << (int)d.dia << "/" << (int)d.mes << "/" << d.any;
	return os;
}


Data::Data(const int &dia, const int &mes, const int &any) {
    setData(dia, mes, any);
}

Data::Data() {
    time_t t = time(0); // Agafa el moment temporal (data+hora) actual
    struct tm * now = localtime(& t);
    dia = now->tm_mday;
    mes = now->tm_mon + 1;
    any = now->tm_year + 1900;
}

short Data::getAny() {
    return any;
}

void Data::setAny(const int &any) {
    if (!dataOK(dia, mes, any)) {
        throw "La nova data no seria vàlida";
    }
    this->any = (short) any;
}

unsigned char Data::getMes() {
    return mes;
}

void Data::setMes(const int &mes) {
    if (!dataOK(dia, mes, any)) {
        throw "La nova data no seria vàlida";
    }
    this->mes = (unsigned char) mes;
}

unsigned char Data::getDia() {
    return dia;
}

void Data::setDia(const int &dia) {
    if (!dataOK(dia, mes, any)) {
        throw "La nova data no seria vàlida";
    }
    this->dia = (unsigned char) dia;
}

void Data::setData(const int &dia, const int &mes, const int &any) {
    if (dataOK(dia, mes, any)) {
        this->dia = (unsigned char) dia;
        this->mes = (unsigned char) mes;
        this->any = (short) any;
    } else throw "La nova data no seria vàlida";
}

int Data::dataOK(const int &dia, const int &mes, const int &any) {
    if (dia <= 0 || mes <= 0 || mes > 12 || any <= 0 || dia > UCHAR_MAX || mes > UCHAR_MAX || any > SHRT_MAX)
        return 0;
    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia > 31) return 0;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia > 30) return 0;
            break;
        case 2:
            if (dia > 29) return 0;
            if (!anyTraspas(any) && dia > 28) return 0;
    }
    return 1;
}

int Data::anyTraspas(const int &any) {
    if (any <= 0) return 0;
    return (any % 4 == 0 && any % 100 != 0 || any % 400 == 0);
}

void Data::visualitzar(ostream &os, const int &saltarLinia) {
    if (saltarLinia)
		os << (int) dia << "-" << (int) mes << "-" << any << endl;
	else
		os << (int) dia << "-" << (int) mes << "-" << any;
}

void Data::visualitzar(ostream &os, const int &saltarLinia, const char &sep) {
    if (saltarLinia)
		os << (int) dia << sep << (int) mes << sep << any << endl;
	else
		os << (int) dia << sep << (int) mes << sep << any;
}

Data Data::operator+(const int &nDies) {
    int numDies = nDies;
    if (numDies == 0) {
        return Data(dia, mes, any);
    }
    int xDia = dia;
    int xMes = mes;
    int xAny = any;
    int diesMes;
    int diesMesAnterior;
    if (numDies > 0) { // Hem de calcular una data futura
        while (numDies > 0) {
            switch (xMes) {
                case 4: case 6: case 9: case 11:
                    diesMes = 30;
                    break;
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    diesMes = 31;
                    break;
                default: /* Febrer */
                    if (anyTraspas(xAny)) diesMes = 29;
                    else diesMes = 28;
                    break;
            }
            if (numDies > diesMes) {
                xMes++;
                numDies = numDies - diesMes;
            } else {
                xDia = xDia + numDies;
                numDies = 0;
                if (xDia > diesMes) {
                    xDia = xDia - diesMes;
                    xMes++;
                }
            }
            if (xMes == 13) {
                xMes = 1;
                xAny++;
            }
        }
    } else { // Case numDies<0 - Hem de calcular una data anterior
        while (numDies < 0) {
            switch (xMes) {
                case 5: case 7: case 10: case 12:
                    diesMesAnterior = 30;
                    break;
                case 1: case 2: case 4: case 6: case 8: case 9: case 11:
                    diesMesAnterior = 31;
                    break;
                default: /* Març */
                    if (anyTraspas(xAny)) diesMesAnterior = 29;
                    else diesMesAnterior = 28;
                    break;
            }
            if (-numDies > diesMesAnterior) {
                xMes--;
                numDies = numDies + diesMesAnterior;
            } else {
                xDia = xDia + numDies;
                numDies = 0;
                if (xDia <= 0) {
                    xDia = xDia + diesMesAnterior;
                    xMes--;
                }
            }
            if (xMes == 0) {
                xMes = 12;
                xAny--;
            }
        }
    }
    return Data(xDia, xMes, xAny);
}

int Data::dataCmp(const Data *d) {
    if (any == d->any && mes == d->mes && dia == d->dia) return 0;
    if (any > d->any || (any == d->any && (mes > d->mes || (mes == d->mes && dia > d->dia))))
        return 1;
    return -1;
}

Data Data::operator-(const int &numDies) {
    return (*this)+(-numDies);
    /* També:
    return this->operator+(-numDies);
     */
}

int Data::operator-(const Data &d) {
    int numDies = 0;
    Data aux;
    if (this->dataCmp(&d) == 0) return 0;
    /* El que segueix no és gens eficient, ja que anem comptant dia a dia... */
    if (this->dataCmp(&d) < 0) {
        aux = this->operator+(1);
        while (aux.dataCmp(&d) <= 0) {
            numDies--;
            aux = aux + 1;
        }
    } else {
        aux = ((Data) d).operator+(1);
        /* Cal la conversió cast, per què d està declarada com a const... */
        while (aux.dataCmp(this) <= 0) {
            numDies++;
            aux = aux + 1;
        }
    }
    return numDies;
}

int Data::operator<(const Data &d) {
    return this->dataCmp(&d) < 0;
}

int Data::operator<=(const Data &d) {
    return this->dataCmp(&d) <= 0;
}

int Data::operator>(const Data &d) {
    return this->dataCmp(&d) > 0;
}

int Data::operator>=(const Data &d) {
    return this->dataCmp(&d) >= 0;
}

int Data::operator==(const Data &d) {
    return this->dataCmp(&d) == 0;
}

int Data::operator!=(const Data &d) {
    return this->dataCmp(&d) != 0;
}

Data &Data::operator++(int) /* Operador ++ sufix */ {
    Data & aux = *this;
    *this = *this +1;
    return aux;
}

Data &Data::operator++() /* Operador ++ prefix */ {
    *this = *this +1;
    return *this;
}

Data &Data::operator--(int) /* Operador -- sufix */ {
    Data & aux = *this;
    *this = *this -1;
    return aux;
}

Data &Data::operator--() /* Operador -- prefix */ {
    *this = *this -1;
    return *this;
}

Data &Data::operator+=(const int &numDies) {
    *this = *this +numDies;
    return *this;
}

Data &Data::operator-=(const int &numDies) {
    *this = *this -numDies;
    return *this;
}

Data operator+(const int &numDies, const Data &d) {
    return ((Data) d) +numDies;
}
