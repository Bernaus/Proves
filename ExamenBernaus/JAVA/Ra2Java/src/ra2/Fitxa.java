
package ra2;

import info.infomila.temporal.Data;
import info.infomila.utilsOrdenacio.BaseOrdenacio;
import java.util.Date;
import java.util.Objects;

/**
 *
 * @author Usuari
 */
public class Fitxa implements BaseOrdenacio{
    private String referencia;
    private String titol;
    private Double cost;
    private Data dataAlta;

    public Fitxa(String referencia, String titol, Double cost, Data dataAlta) {
        if(cost<=0){
            throw new RuntimeException ("Cost a de ser estrictament positiu.");
        }
        this.referencia = referencia;
        this.titol = titol;
        this.cost = cost;
        this.dataAlta = dataAlta;
    }
    
    public Fitxa(String referencia, String titol, Data dataAlta) {
        this.referencia = referencia;
        this.titol = titol;
        this.dataAlta = dataAlta;
    }

    public String getreferencia() {
        return referencia;
    }

    public String getTitol() {
        return titol;
    }

    public void setTitol(String titol) {
        this.titol = titol;
    }

    public Double getCost() {
        return cost;
    }

    public void setCost(Double cost) {
        this.cost = cost;
    }

    public Data getDataAlta() {
        return dataAlta;
    }

    public void setDataAlta(Data dataAlta) {
        this.dataAlta = dataAlta;
    }
    
    public Data getDays(){
        Data dataIngres = null;
        //
        return dataIngres;
    }

    @Override
    public String toString() {
        return "Referència: " + referencia + " - Títol: " + titol;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 71 * hash + Objects.hashCode(this.referencia);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Fitxa other = (Fitxa) obj;
        
        return referencia.equals(other.referencia);
    }

    @Override
    public int compararAmb(BaseOrdenacio obj) {
        Fitxa aux = (Fitxa)obj;
        return referencia.compareTo(aux.referencia);
    }
    
    
    
    
    
}
