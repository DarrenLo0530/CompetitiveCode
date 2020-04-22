/**
 * FibonacciSpiral
 */
import java.util.*;

public class FibonacciSpiral {
    static class Coord{
        long x, y;
        Coord(long x, long y){
            this.x = x;
            this.y = y;
        }
    }
    static class Square{
        Coord topLeft;
        Coord bottomRight;

        Square(Coord topLeft, Coord bottomRight){
            this.topLeft = topLeft;
            this.bottomRight = bottomRight;
        }   
    }
    
    public static boolean isInBounds(Square fibSquare, Coord curr){
        if(curr.x >= fibSquare.topLeft.x && curr.x <= fibSquare.bottomRight.x && curr.y <= fibSquare.topLeft.y && curr.y >= fibSquare.bottomRight.y){
            return true;
        }
        return false;
    }
    public static void generateNextSquare(ArrayList<Square> fib, int direction){
        Square sq1 = fib.get(fib.size()-1);
        Square sq2 = fib.get(fib.size()-2);
        long sq1Len = sq1.bottomRight.x - sq1.topLeft.x;
        long sq2Len = sq2.bottomRight.x - sq2.topLeft.x;
        long newSqLen = sq1Len + sq2Len;
        Coord newTopLeft, newBottomRight;

        if(direction == 1){
            newTopLeft = new Coord(sq1.bottomRight.x, sq1.topLeft.y);
            newBottomRight = new Coord(sq1.bottomRight.x + newSqLen, sq1.topLeft.y - newSqLen);
        } else if (direction == 2){
            newTopLeft = new Coord(sq1.bottomRight.x - newSqLen, sq1.bottomRight.y);
            newBottomRight = new Coord(sq1.bottomRight.x ,sq1.bottomRight.y - newSqLen);
        } else if (direction == 3){
            newTopLeft = new Coord(sq1.topLeft.x - newSqLen, sq1.bottomRight.y + newSqLen);
            newBottomRight = new Coord(sq1.topLeft.x, sq1.bottomRight.y);
        } else {    
            newTopLeft = new Coord(sq1.topLeft.x, sq1.topLeft.y + newSqLen);
            newBottomRight = new Coord(sq1.topLeft.x + newSqLen, sq1.topLeft.y);
        }

        fib.add(new Square(newTopLeft, newBottomRight));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Square> fib = new ArrayList<>();
        int direction = 3;

        fib.add(new Square(new Coord(0, 0), new Coord(0, 0)));
        fib.add(new Square(new Coord(0, 0), new Coord(1, -1)));

        for(int i = 0; i<10; i++){
            Coord curr = new Coord(sc.nextInt(), sc.nextInt());
            boolean found = false;

            for(int j = 1; j<fib.size() && !found; j++){
                if(isInBounds(fib.get(j), curr)){
                    System.out.println(j);
                    found = true;
                }
            }

            while(!found){
                generateNextSquare(fib, direction);
                if(isInBounds(fib.get(fib.size()-1), curr)){
                    found = true;
                    System.out.println(fib.size()-1);
                }

                if(direction == 4){
                    direction = 1;
                } else {
                    direction++;
                }
            }

        }
        sc.close();
    }
}