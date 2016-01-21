/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package info.infomila.utilsOrdenacio;


/**
 *
 * @author Usuari
 */
public class UtilsOrdenacio {
    /**
     * Metode que ordena una taula de ???
     * @param t Taula de persones a ordenar
     * @param q Quantitat de persones (posicions) a ordenar des de 0
     */
    public static void ordenarTaula(BaseOrdenacio t[],int q) {
        
        boolean canvi = true;
        int i, j;
        BaseOrdenacio aux;
        
        for (i=0; i<q-1 && canvi; i++) {
            canvi = false;
            for (j=q-1; j>0; j--) {
                   if (t[j].compararAmb(t[j-1]) < 0 ) {
                    aux = t[j];
                    t[j] = t[j-1];
                    t[j-1] = aux;
                    canvi = true;
                }
            }
        }        
    }
}
