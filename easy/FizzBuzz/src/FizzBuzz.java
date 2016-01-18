import java.io.*;

public class FizzBuzz {

    public static void main(String[] args) {

        File file = new File(args[0]);

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {

            String line;

            //read file line by line
            while ((line = reader.readLine()) != null) {

                line = line.trim();

                //parse line for divisor X, Y and count N
                String[] tokens = line.split(" ");
                int[] constraints = new int[3];
                for (int i = 0; i < tokens.length; i++) {
                    constraints[i] = Integer.parseInt(tokens[i]);
                }
                
                if (!constraintsAreMet(args[0], constraints)) return;

                //print numbers from 1 to N incorporating divisor constraints
                for (int i = 1; i <= constraints[2]; i++) {

                    //num divisible by X and Y
                    if (i % constraints[0] == 0 && i % constraints[1] == 0) System.out.print(" FB");

                    //num divisible by X
                    else if (i % constraints[0] == 0) System.out.print(" F");

                    //num divisible by Y
                    else if (i % constraints[1] == 0) System.out.print(" B");

                    else System.out.print(" " + i);
                }
                System.out.println();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static boolean constraintsAreMet(String filename, int[] constraints) throws IOException{
        if (constraints[0] < 1 || constraints[0] > 20) {
            System.out.println("X must be in range 1 - 20");
            return false;
        }
        
        if (constraints[1]  < 1 || constraints[1] > 20) {
            System.out.println("Y must be in range 1 - 20");
            return false;
        }

        if (constraints[2] < 21 || constraints[1] > 100) {
            System.out.println("N must be in range 21 - 100");
            return false;
        }

        LineNumberReader  lnr = new LineNumberReader(new FileReader(new File(filename)));
        lnr.skip(Long.MAX_VALUE);
        if (lnr.getLineNumber() + 1 > 20) {
            System.out.println("Test cases must be less than 20");
            return false;
        }

        return true;
    }
}
