import java.io.*;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));

        String line;

        while ((line = in.readLine()) != null) {

            //parse line for point values
            int[] pointValues = getPoints(line);

            //calculate distance
            int x1 = pointValues[0];
            int y1 = pointValues[1];
            int x2 = pointValues[2];
            int y2 = pointValues[3];
            int x = (int) pow(x1-x2, 2);
            int y = (int) pow(y1-y2, 2);

            int distance = (int) sqrt(x+y);
            System.out.println(distance);
        }
    }

    public static int[] getPoints(String line) {

        int[] pointValues = new int[4];
        int n = 0;

        //use regex to parse line to point values
        String[] tokens = line.split("\\(|\\)|,");
        for (int i = 0; i < tokens.length; i++) {
            tokens[i] = tokens[i].trim();

            //point value found
            if (tokens[i].matches("-?\\d+")) {
                pointValues[n++] = Integer.parseInt(tokens[i]);
            }
        }

        return pointValues;
    }
}
