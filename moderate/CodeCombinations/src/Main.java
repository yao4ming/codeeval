import java.io.*;
import java.util.*;

/**
 * Created by yaoming on 3/17/16.
 */
class Main {

    static boolean c = false, o = false, d = false, e = false;
    static int count = 0;

    public static boolean isCodeLetter(char value) {

        switch (value) {
            case 'c': c = true;
                break;
            case 'o': o = true;
                break;
            case 'd': d = true;
                break;
            case 'e': e = true;
                break;
            default:
                return false;
        }
        return true;
    }

    public static boolean foundCode() {
        return c & o & d & e;
    }

    public static void resetLetters() {
        c = false;
        o = false;
        d = false;
        e = false;
    }

    public static void main(String[] args) {

        File file = new File(args[0]);

        try (Scanner in = new Scanner(file)) {
            while (in.hasNextLine()) {
                String[] rows = in.nextLine().split("\\|");

                for (int i = 0; i < rows.length - 1; i ++) {
                    String row = rows[i].trim();
                    String nextRow = rows[i+1].trim();

                    for (int j = 0; j < row.length() - 1; j++) {

                        if (!isCodeLetter(row.charAt(j)) || !isCodeLetter(row.charAt(j+1))
                                || !isCodeLetter(nextRow.charAt(j)) || !isCodeLetter(nextRow.charAt(j+1))) {
                        } else if (foundCode()) {
                            count++;
                        }
                        resetLetters();
                    }
                }
                System.out.println(count);
                count = 0;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
