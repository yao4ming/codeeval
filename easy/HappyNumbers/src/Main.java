import java.io.*;
import java.util.*;

public class Main {

    static ArrayList<Integer> digits = new ArrayList<Integer>();

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

        Set<Integer> checked = new HashSet<Integer>();
        int sum = Integer.parseInt(num);
        do {

            //endless loop, break
            if (checked.contains(sum)) return false;
            checked.add(sum);

            //extract digits from sum
            extractDigits(sum);

            sum = 0;

            //square each digit and add to sum
            for (Integer digit : digits) {
                sum = sum + digit * digit;
            }

            digits.clear();

        } while (sum != 1);

        checked.clear();
        return true;
    }

    public static void extractDigits(int num) {
        do {
            digits.add(num % 10);
            num /= 10;
        } while (num >= 1);
    }

}


