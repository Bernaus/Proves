

package ra1;

import java.awt.Point;
import java.awt.geom.Point2D;

/**
 *
 * @author Usuari
 */
public class Ex1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Point t[] = new Point[4];
        
        t[0] = new Point(3,2);
        t[1] = new Point(-3,2);
        t[2] = new Point(-3,-2);
        t[3] = new Point(3,-2);
        
        System.out.println("Visualització de la taula de punts.");
        
        for(int i=0;i<4;i++){
            System.out.println("Punt "+ i +" es: "+t[i]);
        }
        
        System.out.println();
        
        double resultat=Point2D.distance(t[1].getX(),t[1].getY(),t[2].getX(),t[2].getY());
        
        System.out.println("Resultat d'invocar el metode distance: "+resultat);
        
        Point pb = new Point(5,5);        
        resultat = sumaTaula(t,pb);
        System.out.println("Resultat de la suma de les distancies: "+resultat);
        
    }
    
    public static double sumaTaula(Point t[],Point p){
        
        double resultat=0;
        
        for(int i=0;i<t.length;i++){
            resultat=+Point2D.distance(t[i].getX(),t[i].getY(),p.getX(),p.getY());
        }
        
        return resultat;
    }
}
