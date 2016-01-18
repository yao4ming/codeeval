import java.io.*;
import java.util.Scanner;

public class LowerCase {
    
    public static void main(String[] args) {
        File file = new File(args[0]);

        try (Scanner in = new Scanner(file)) {

            while (in.hasNextLine()) {
                String line = in.nextLine().toLowerCase();
                System.out.println(line);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}

