import java.io.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;

        while ((line = in.readLine()) != null) {

            line = line.trim();

            if (isHappyNumber(line)) {
                System.out.println("1");
            }
            else {
                System.out.println("0");
            }
        }
    }

    public static boolean isHappyNumber(String num) {

        int loop = 10000;
        int sum = Integer.parseInt(num);
        do {

            if (--loop == 0) return false;

            //parse num into digits
            ArrayList<Integer> digits = convertNumberToDigits(Integer.toString(sum));

            //reset sum
            sum = 0;

            //square each digit and add to sum
            for (Integer digit : digits) {
                sum = sum + digit * digit;
            }
        } while (sum != 1);

        return true;
    }

    public static ArrayList<Integer> convertNumberToDigits(String num) {

        //separate string num into digits
        ArrayList<Integer> digits = new ArrayList<Integer>();
        for (int i = 0; i < num.length(); i++) {
            digits.add(Character.getNumericValue(num.charAt(i)));
        }

        return digits;
    }
}


