import java.io.*;

public class Main {

    static int[] cache;

    public static void main(String[] args) throws IOException {

        File file = new File(args[0]);

        BufferedReader in = new BufferedReader(new FileReader(file));
        String line;
        while ((line = in.readLine()) != null) {
            int n = Integer.parseInt(line);
            cache = new int[n+1];
            System.out.println(fib(n));
        }
    }

    public static int fib(int n) {

        if (n <= 1) {
            return n;
        }

        if (cache[n] != 0) {
            return cache[n];
        }

        cache[n] = (int)Math.pow(fib(n-1),2) + fib(n-2);

        return cache[n];
    }
}
