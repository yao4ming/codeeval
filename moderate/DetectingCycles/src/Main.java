import java.io.*;

/*
Naive approach O(n^2)
 */
public class Main {

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);
        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {

            int[] nums = parseLineToIntArray(line);

            detectCycles(nums);

            System.out.println();
        }
    }

    public static int[] parseLineToIntArray(String line) {

        String[] tokens = line.split(" ");
        int[] nums = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            nums[i] = Integer.parseInt(tokens[i]);
        }

        return nums;
    }

    public static void detectCycles(int[] nums) {

        int cycleBeg = 0, cycleEnd = 0;
        cycleFound:
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    cycleBeg = i;
                    cycleEnd = j;
                    break cycleFound;
                }
            }
        }

        while (cycleBeg < cycleEnd) {
            System.out.print(nums[cycleBeg++] + " ");
        }
    }
}
