import java.io.*;
import java.util.*;

/**
 * Created by yaoming on 3/21/16.
 */
public class Main {

    public static boolean isPrime(int num) {

        //special case 2 is the only even prime number
        if (num == 2) return true;

        //check if num is even, divisible by 2
        if (num % 2 == 0) return false;

        //check if num is divisible by odd numbers
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static int findClosestPowerOfTwo(int num) {
        int exp = (int) Math.floor(Math.log(num) / Math.log(2));
        return (int) Math.pow(2, exp);
    }

    public static void mersennePrimes(int num) {

        //find closest 2^n < num
        int max = findClosestPowerOfTwo(num);

        //Mersenne Prime start at 3
        int powerOfTwo = 4;

        StringBuilder output = new StringBuilder();

        while (powerOfTwo <= max) {
            if (isPrime(powerOfTwo - 1)) {
                output.append(Integer.toString(powerOfTwo-1)).append(", ");
            }
            powerOfTwo *= 2;
        }
        //delete space and comma at the end, then print
        System.out.println(output.substring(0, output.length()-2));
    }

    public static void main(String[] args) {
        File file = new File(args[0]);
        try (Scanner in = new Scanner(file)) {
            while (in.hasNextLine()) {
                mersennePrimes(Integer.parseInt(in.nextLine()));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
