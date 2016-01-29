import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(new File(args[0])));
        String line;
        while ((line = in.readLine()) != null) {
            line = line.trim();
            String strByDev = line.split("[|]")[0].trim();
            String strByDesign = line.split("[|]")[1].trim();

            int bug = 0;
            for (int i = 0; i < strByDesign.length(); i++) {
                Character c1 = strByDesign.charAt(i);
                Character c2 = strByDev.charAt(i);
                if (c1.compareTo(c2) != 0) bug++;
            }

            if (bug < 1) {
                System.out.println("Done");
            } else if (bug <= 2) {
                System.out.println("Low");
            } else if (bug <= 4) {
                System.out.println("Medium");
            } else if (bug <= 6) {
                System.out.println("High");
            } else {
                System.out.println("Critical");
            }
        }
    }
}
