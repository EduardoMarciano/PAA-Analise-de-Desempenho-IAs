import java.util.*;

public class MatrixPlucking {
    static class Coord {
        int i, j;
        Coord(int i, int j) {
            this.i = i;
            this.j = j;
        }
        
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Coord coord = (Coord) o;
            return i == coord.i && j == coord.j;
        }
        
        @Override
        public int hashCode() {
            return Objects.hash(i, j);
        }
    }
    
    static Set<Coord> getAffected(Coord coord) {
        int i = coord.i, j = coord.j;
        return new HashSet<>(Arrays.asList(
            new Coord(i-1, j), new Coord(i, j-1), new Coord(i, j),
            new Coord(i, j+1), new Coord(i+1, j)
        ));
    }
    
    static int pluckMatrix(Set<Coord> coordinates) {
        int plucks = 0;
        
        while (!coordinates.isEmpty()) {
            Coord bestPluck = Collections.max(coordinates, (a, b) -> {
                Set<Coord> affectedA = getAffected(a);
                Set<Coord> affectedB = getAffected(b);
                affectedA.retainAll(coordinates);
                affectedB.retainAll(coordinates);
                return Integer.compare(affectedA.size(), affectedB.size());
            });
            
            Set<Coord> affected = getAffected(bestPluck);
            coordinates.removeAll(affected);
            plucks++;
        }
        
        return plucks;
    }
    
    public static void main(String[] args) {
        Set<Coord> coordinates = new HashSet<>(Arrays.asList(
            new Coord(0, 0), new Coord(0, 1), new Coord(1, 0),
            new Coord(1, 1), new Coord(2, 2)
        ));
        System.out.println("Minimum plucks required: " + pluckMatrix(coordinates));
    }
}