import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {

            ArrayList<String> people = new ArrayList<String>(Arrays.asList(line.split(" ")));
            int blackSpot = Integer.parseInt(people.get(people.size()-1));
            
            //remove non-name tokens
            people.remove(people.size()-1);
            people.remove(people.size()-1);

            int peopleLeft = people.size();
            int counter = 1;
            int iter = 0;
            while (peopleLeft > 1) {

                //loopback
                if (iter >= peopleLeft) {
                    iter = 0;
                }

                //check person is blackcode
                if (counter == blackSpot) {
                    people.remove(iter);
                    counter = 1;
                    iter = 0;
                    peopleLeft--;
                }
                //move to next person
                else {
                    iter++;
                    counter++;
                }
            }
            System.out.println(people.get(0));
        }
    }
}
