public class SumOfPrimes {

    public static void main(String[] args) {

        int sum = 0, count = 0;
        for (int i = 2; i < 10000; i++) {

            if (count == 1000) break;

            if (isPrime(i)) {
                sum += i;
                count++;
            }
        }
        System.out.println(sum);
    }

    public static boolean isPrime(int num) {

        if (num == 2) return true;

        if (num % 2 == 0) return false;

        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
