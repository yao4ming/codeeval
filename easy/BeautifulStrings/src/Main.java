import java.io.*;
import java.util.*;

public class Main {

    static Map<Character, Integer> charCount;

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);

        String line;
        BufferedReader in = new BufferedReader(new FileReader(file));
        charCount = new HashMap<>();

        while ((line = in.readLine()) != null) {

            countLetterFrequencies(line);

            int maxBeauty = findMaxBeauty();
            System.out.println(maxBeauty);

        }
    }

    public static void countLetterFrequencies(String line) {

        for (int i = 0; i < line.length(); i++) {

            Character upperLetter = Character.toUpperCase(line.charAt(i));

            //only process upper case letters
            if (upperLetter >= 'A' && upperLetter <= 'Z') {

                //add count of 1 and store in map
                if (charCount.get(upperLetter) == null) {
                    charCount.put(upperLetter, 1);
                }
                //increase count by 1
                else {
                    Integer count = charCount.get(upperLetter);
                    charCount.put(upperLetter, count+1);
                }
            }
        }
    }

    public static int findMaxBeauty() {

        int maxBeauty = 0;
        int beautyPower = 26;

        while (!charCount.isEmpty()) {

            Map.Entry<Character,Integer> currentMax = findMaxEntry();

            //beautyPower * maxFrequency
            maxBeauty += beautyPower * currentMax.getValue();

            //decrement max frequency by removing key entry
            //decrement beautypower
            charCount.remove(currentMax.getKey());
            beautyPower--;
        }

        return maxBeauty;
    }

    public static Map.Entry<Character, Integer> findMaxEntry() {

        Map.Entry<Character, Integer> maxEntry = null;
        for (Map.Entry<Character, Integer> entry : charCount.entrySet()) {
            if (maxEntry == null || entry.getValue().compareTo(maxEntry.getValue()) > 0) {
                maxEntry = entry;
            }
        }
        return maxEntry;
    }
}

