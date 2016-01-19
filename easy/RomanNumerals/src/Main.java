import java.io.*;
import java.util.*;

import static java.lang.Math.pow;

public class Main {

    static Map<Integer, String> romanNumeral;

    public static void main(String[] args) throws IOException {

        mapRomanNumerals();

        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {

            int degree = line.length() - 1;

            for (int i = 0; i < line.length(); i++, degree--) {

                int digit = Character.getNumericValue(line.charAt(i));

                //print some degree of 9
                if (digit == 9) {
                    System.out.print(romanNumeral.get(9 * (int) pow(10, degree)));
                    digit -= 9;
                }
                //print some degree of 5
                else if (digit >= 5) {
                    System.out.print(romanNumeral.get(5 * (int) pow(10, degree)));
                    digit -= 5;
                }
                //print some degree of 4
                else if (digit == 4) {
                    System.out.print(romanNumeral.get(4 * (int) pow(10, degree)));
                    digit -= 4;
                }

                //print some degree of 1
                for (int j = 0; j < digit; j++) {
                    System.out.print(romanNumeral.get((int) pow(10, degree)));
                }
            }
            System.out.println();
        }
    }

    public static void mapRomanNumerals() {

        romanNumeral = new HashMap<Integer, String>();
        romanNumeral.put(1, "I");
        romanNumeral.put(4, "IV");
        romanNumeral.put(5, "V");
        romanNumeral.put(9, "IX");
        romanNumeral.put(10, "X");
        romanNumeral.put(40, "XL");
        romanNumeral.put(50, "L");
        romanNumeral.put(90, "XC");
        romanNumeral.put(100, "C");
        romanNumeral.put(400, "CD");
        romanNumeral.put(500, "D");
        romanNumeral.put(900, "CM");
        romanNumeral.put(1000, "M");
    }
}
