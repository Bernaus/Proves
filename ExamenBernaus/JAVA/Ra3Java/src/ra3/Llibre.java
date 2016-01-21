
package ra3;

import info.infomila.temporal.Data;
import ra2.Fitxa;

/**
 *
 * @author Usuari
 */
public class Llibre extends Fitxa{
    
    private String autor;
    private Integer anyCreacio;

    public Llibre(String autor, Integer anyCreacio, String referencia, String titol, Double cost, Data dataAlta) {
        super(referencia, titol, cost, dataAlta);
        this.autor = autor;
        this.anyCreacio = anyCreacio;
    }

    public Llibre(String autor, Integer anyCreacio, String referencia, String titol, Data dataAlta) {
        super(referencia, titol, dataAlta);
        this.autor = autor;
        this.anyCreacio = anyCreacio;
    }

    
    public Llibre(String autor, String referencia, String titol, Double cost, Data dataAlta) {
        super(referencia, titol, cost, dataAlta);
        this.autor = autor;
    }

    public Llibre(String autor, String referencia, String titol, Data dataAlta) {
        super(referencia, titol, dataAlta);
        this.autor = autor;
    }

    final public String getAutor() {
        return autor;
    }

    final public void setAutor(String autor) {
        this.autor = autor;
    }

    final public Integer getAnyCreacio() {
        return anyCreacio;
    }

    final public void setAnyCreacio(Integer anyCreacio) {
        if(anyCreacio<=0){
             throw new RuntimeException ("anyCreacio a de ser estrictament positiu.");
        }
        this.anyCreacio = anyCreacio;
    }

    @Override
    public String toString() {
        String aux = "Sóc llibre - ";
        aux = aux + super.toString();        
        aux = aux + " - Autor: " + autor;
        aux = aux + " - Any: " + (anyCreacio==null?"":anyCreacio);
        return aux;
    }
    
    
    
    
    

    
}
