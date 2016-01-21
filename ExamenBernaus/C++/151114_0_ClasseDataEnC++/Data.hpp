
#ifndef __DATA__HPP__

#define __DATA__HPP__
#include <iostream>

using namespace std;

class Data {
	friend ostream &operator<<(ostream &os, Data &d);
private:
    unsigned char dia, mes;
    short any;
public:
    Data(const int &dia, const int &mes, const int &any);
    Data();
    short getAny();
    void setAny(const int &any);
    unsigned char getMes();
    void setMes(const int &mes);
    unsigned char getDia();
    void setDia(const int &dia);
    void setData(const int &dia, const int &mes, const int &any);
    static int dataOK(const int &dia, const int &mes, const int &any);
    static int anyTraspas(const int &any);
	virtual void visualitzar(ostream &os, const int &saltarLinia);
    virtual void visualitzar(ostream &os, const int &saltarLinia, const char &separador);
	Data operator+(const int &numDies); // sumaDies de Java
	Data operator-(const int &numDies); // restaDies (no l'hem fet en Java)
	int operator-(const Data &d); // restaDates de Java
    int dataCmp(const Data *d);
    int operator<(const Data &d);
    int operator<=(const Data &d);
    int operator>(const Data &d);
    int operator>=(const Data &d);
    int operator==(const Data &d);
    int operator!=(const Data &d);
    Data &operator++(int); /* Operador ++ sufix */
    Data &operator++(); /* Operador ++ prefix */
    Data &operator--(int); /* Operador -- sufix */
    Data &operator--(); /* Operador -- prefix */
    Data &operator+=(const int &numDies);
    Data &operator-=(const int &numDies);

    virtual ~Data() {};
};

/* L'operador següent no pot ser mètode de cap de les maneres...
   És necessaris per poder sumar a un enter, una data,
   i com que no el podem incorporar a la classe dels "int",
   doncs l'hem de dissenyar com a funció no mètode.
 */
Data operator+(const int &numDies, const Data &d);


#endif
