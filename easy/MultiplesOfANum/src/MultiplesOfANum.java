import java.io.*;

public class MultiplesOfANum {

    public static void main(String[] args) {

        File file = new File(args[0]);

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {

            String line;
            while ((line = reader.readLine()) != null) {
                int x = Integer.parseInt(line.split(",")[0]);
                int n = Integer.parseInt(line.split(",")[1]);

                //print smallest multiple of n > x
                int i = n;
                while (i < x) {
                    i += n;
                }
                System.out.println(i);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
