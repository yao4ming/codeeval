import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new FileReader(new File(args[0])));
        String line;
        while ((line = in.readLine()) != null) {
            String[] tokens = line.split(";");

            String[] words = tokens[0].split(" ");
            String[] nums = tokens[1].split(" ");

            String[] organizedWords = new String[words.length];
            for (int i = 0; i < nums.length; i++) {
                int pos = Integer.parseInt(nums[i]);
                organizedWords[pos-1] = words[i];
            }

            //organize last word in words
            for (int i = 0; i < organizedWords.length; i++) {
                if (organizedWords[i] == null) {
                    organizedWords[i] = words[words.length-1];
                }
            }

            for (String word : organizedWords) System.out.print(word + " ");
            System.out.println();

        }
    }
}
