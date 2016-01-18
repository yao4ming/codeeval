import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class SumOfDigits {

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);
        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {

            int sum = 0;
            for (int i = 0; i < line.length(); i++) {
                sum += Character.getNumericValue(line.charAt(i));
            }
            System.out.println(sum);
        }
    }
}
