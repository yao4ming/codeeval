import java.io.*;
import java.util.*;

import static java.lang.Math.pow;

public class Main {

    static ArrayList<Integer> digits;

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {

            int num = Integer.parseInt(line);
            digits = new ArrayList<Integer>();
            extractDigits(num);

            if (isArmstrongNumber(num)) {
                System.out.println("True");
            }
            else {
                System.out.println("False");
            }
        }
    }

    public static void extractDigits(int num) {
        do {
            digits.add(num % 10);
            num /= 10;
        } while (num >= 1);
    }

    public static boolean isArmstrongNumber(int num) {

        int sum = 0;
        for (Integer digit : digits) {
            sum = sum + (int) pow(digit, digits.size());
        }
        return sum == num;
    }
 }

