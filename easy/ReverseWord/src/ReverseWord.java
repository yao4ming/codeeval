import java.io.*;

public class ReverseWord {

    public static void main(String[] args) {

        File file = new File(args[0]);

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {

            String line;
            while ((line = reader.readLine()) != null) {

                String[] words = line.split(" ");
                for (int i = words.length-1; i >= 0; i--) {
                    System.out.print(words[i] + " ");
                }
                System.out.println();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
