/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package info.infomila.temporal;


/**
 *
 * @author Isidre Guixà
 */
public class Data  {

    private byte dia, mes;
    private short any;

    /**
     * Intenta construir una data amb la combinació dels paràmetres introduïts.
     *
     * @throws RuntimeException si la combinació de dia-mes-any és errònia
     * @param dia
     * @param mes
     * @param any
     */
    public Data(int dia, int mes, int any) {
        setData(dia, mes, any);
    }

    /**
     * Constructor còpia
     *
     * @param d Data a copiar
     */
    public Data(Data d) {
        if (d==null)
            throw new RuntimeException("No es pot crear una data a partir de null");
        dia = d.dia;
        mes = d.mes;
        any = d.any;
        // També hagués pogut ser:
        // this(d.dia, d.mes, d.any);
        // Hauria de ser la 1a. instrucció del constructor
        // Aquí no té sentit, doncs no cal que torni a verificar
        // la correctesa de la terna (d.dia, d.mes, d.any) com a data
    }

    /**
     * Facilita l'any de la data
     *
     * @return - Any de la data
     */
    public short getAny() {
        return any;
    }

    /**
     * Permet modificar l'any de la data
     *
     * @throws RuntimeException en cas que la nova data fos errònia
     * @param any Nou any
     */
    public void setAny(int any) {
        if (!dataOK(dia, mes, any)) {
            throw new RuntimeException("La nova data no seria vàlida");
        }
        this.any = (short) any;
    }

    /**
     * Facilita el mes de la data
     *
     * @return Mes de la data
     */
    public byte getMes() {
        return mes;
    }

    /**
     * Permet modificar el mes de la data
     *
     * @throws RuntimeException en cas que la nova data fos errònia
     * @param mes Nou mes
     */
    public void setMes(int mes) {
        if (!dataOK(dia, mes, any)) {
            throw new RuntimeException("La nova data no seria vàlida");
        }
        this.mes = (byte) mes;
    }

    /**
     * Facilita el dia de la data
     *
     * @return - Dia de la data
     */
    public byte getDia() {
        return dia;
    }

    /**
     * Permet modificar el dia de la data
     *
     * @throws RuntimeException en cas que la nova data fos errònia
     * @param dia Nou dia
     */
    public void setDia(int dia) {
        if (!dataOK(dia, mes, any)) {
            throw new RuntimeException("La nova data no seria vàlida");
        }
        this.dia = (byte) dia;
    }

    /**
     * Permet modificar dia, més i any de la data amb els nous valors passats
     * per paràmetre
     *
     * @throws RuntimeException en cas que la nova data fos errònia
     * @param dia Nou dia
     * @param mes Nou mes
     * @param any Nou any
     */
    public void setData(int dia, int mes, int any) {
        if (dataOK(dia, mes, any)) {
            this.dia = (byte) dia;
            this.mes = (byte) mes;
            this.any = (short) any;
        } else {
            throw new RuntimeException("La nova data (" + any + "-" + mes + "-" + dia + ") no seria vàlida");
        }
    }

    /**
     * Permet modificar una data com a còpia de la data passada per paràmetre
     *
     * @param novaData Nova data
     */
    public void setData(Data novaData) {
        dia = novaData.dia;
        mes = novaData.mes;
        any = novaData.any;
    }

    /**
     * Informa si la combinació dia-mes-any correspondria a una data correcta
     *
     * @param dia Dia
     * @param mes Mes
     * @param any Any
     * @return true si la combinació correspon a una data correcta; false en cas
     * contrari
     */
    public static boolean dataOK(int dia, int mes, int any) {
        if (dia <= 0 || mes <= 0 || mes > 12 || any <= 0 || dia > Byte.MAX_VALUE || mes > Byte.MAX_VALUE || any > Short.MAX_VALUE) {
            return false;
        }
        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (dia > 31) {
                    return false;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (dia > 30) {
                    return false;
                }
                break;
            case 2:
                if (dia > 29) {
                    return false;
                }
                if (!anyTraspas(any) && dia > 28) {
                    return false;
                }
        }
        return true;
    }

    /**
     * Informa si es tracta d'un any de traspàs
     *
     * @param any Any
     * @return true si correspon a any de traspàs; false en cas contrari
     */
    public static boolean anyTraspas(int any) {
        if (any <= 0) {
            return false;
        }
        return (any % 4 == 0 && any % 100 != 0 || any % 400 == 0);
    }

    /**
     * Mostra la data per la consola
     * <p>
     * S'utilitza el guió per separar les parts de la data</p>
     *
     * @param saltarLinia Si true, s'afegeix un salt de línia; si false, no
     * s'afegeix cap salt de línia
     */
    public void visualitzar(boolean saltarLinia) {
        if (saltarLinia) {
            System.out.println(dia + "-" + mes + "-" + any);
        } else {
            System.out.print(dia + "-" + mes + "-" + any);
        }
    }

    /**
     * Mostra la data per la consola
     *
     * @param saltarLinia Si true, s'afegeix un salt de línia; si false, no
     * s'afegeix cap salt de línia
     * @param separador Caràcter separador de les parts de la data
     */
    public void visualitzar(boolean saltarLinia, char separador) {
        String sep = Character.toString(separador);
        if (saltarLinia) {
            System.out.println(dia + sep + mes + sep + any);
        } else {
            System.out.print(dia + sep + mes + sep + any);
        }
    }

    /**
     * Obté una nova data sumant els dies indicats
     *
     * @param numDies Número de dies a sumar, que pot ser negatiu
     * @return Nova data
     */
    public Data sumaDies(int numDies) {
        if (numDies == 0) {
//         return new Data(dia, mes, any);   /* En cas que no tinguem
//            un constructor de Data passant per paràmetre una Data */
            return new Data(this);
        }
        int xDia = dia;
        int xMes = mes;
        int xAny = any;
        int diesMes;
        int diesMesAnterior;
        if (numDies > 0) { // Hem de calcular una data futura
            while (numDies > 0) {
                switch (xMes) {
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        diesMes = 30;
                        break;
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        diesMes = 31;
                        break;
                    default: /* Febrer */

                        if (anyTraspas(xAny)) {
                            diesMes = 29;
                        } else {
                            diesMes = 28;
                        }
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
        } else {   // Case numDies<0 - Hem de calcular una data anterior
            while (numDies < 0) {
                switch (xMes) {
                    case 5:
                    case 7:
                    case 10:
                    case 12:
                        diesMesAnterior = 30;
                        break;
                    case 1:
                    case 2:
                    case 4:
                    case 6:
                    case 8:
                    case 9:
                    case 11:
                        diesMesAnterior = 31;
                        break;
                    default: /* Març */

                        if (anyTraspas(xAny)) {
                            diesMesAnterior = 29;
                        } else {
                            diesMesAnterior = 28;
                        }
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
        return new Data(xDia, xMes, xAny);
    }

    /**
     * Compara la data amb una altra data passada per paràmetre
     *
     * @param d Data amb la què es compara la data sobre la que s'invoca el
     * mètode
     * @return 0 Les dates són iguals<BR> -1 si this <BR> 1 si this > d
     */
    public int dataCmp(Data d) {
        if (any == d.any && mes == d.mes && dia == d.dia) {
            return 0;
        }
        if (any > d.any || (any == d.any && (mes > d.mes || (mes == d.mes && dia > d.dia)))) {
            return 1;
        }
        return -1;
    }

    /**
     * Resta una data a la data sobre la que s'executa el mètode, obtenint el
     * nombre de dies que les separa.
     *
     * @param d Data sustraend
     * @return El nombre de dies que separa les dues dates. Valor positiu si la
     * data sobre la que s'invoca el mnètode és posterior a la data que es
     * resta, i negatiu en cas contrari.
     */
    public int restaData(Data d) {
        int numDies = 0;
        Data aux;
        if (this.dataCmp(d) == 0) {
            return 0;
        }
        /* El que segueix no és gens eficient, ja que anem comptant dia a dia... */
        if (this.dataCmp(d) < 0) {
            // if (dataCmp(d) < 0) 
            aux = this.sumaDies(1);
            while (aux.dataCmp(d) <= 0) {
                numDies--;
                aux = aux.sumaDies(1);
            }
        } else {
            aux = d.sumaDies(1);
            while (aux.dataCmp(this) <= 0) {
                numDies++;
                aux = aux.sumaDies(1);
            }
        }
        return numDies;
    }

    /**
     * Facilita una representació en cadena d'un objecte Data, en el format
     * ANSI per a les dates (aaaa-mm-dd).
     * 
     * @return Una representació en cadena de l'objecte
     */
    public String toString() {
        return any + "-" + mes + "-" + dia;
    }

    /**
     * Indica quan un objecte és igual a una data.
     * Dues dates són iguals si tenen igual any, més i dia.
     * @param obj La referència a l'objecte a dataCmp
     * @return true si l'objecte referenciat pel paràmetre és una data amb igual
     * dia, més i any que la pròpia data.
     */
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (!(obj instanceof Data)) {
            return false;
        }
        /* Arribats aquí, estem segurs que obj apunta una Data */
        Data aux = (Data) obj;
        return dia == aux.dia && mes == aux.mes && any == aux.any;
    }

    /**
     * Calcula un valor de Hash per a una data, de forma coherent amb el 
     * mètode equals.
     * Aquest mètode no verifica la primera condició del contracte del mètode
     * hashCode, ja que el seu càlcul es basa en el dia, mes i any i aquests
     * valors no són immutables. En conseqüència, quan s'utilitzi una data en
     * col·leccions amb tècniques de Hash, en cas d'haver de modificar la data, 
     * caldrà extreure l'element de la col·lecció abans de la modificació i tor-
     * nar-lo a incloure després de la modificació.
     * @return El valor de hash de l'objecte
     */
    public int hashCode() {
        int hash = 7;
        hash = 29 * hash + this.dia;
        hash = 29 * hash + this.mes;
        hash = 29 * hash + this.any;
        return hash;
    }
    
}
