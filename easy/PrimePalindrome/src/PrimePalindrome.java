public class PrimePalindrome {

    public static void main(String[] args) {

        for (int i = 1000;; i--) {
            if (isPrimePalindrome(i)) {
                System.out.println(i);
                return;
            }
        }
    }

    public static boolean isPalindrome(int num) {
        String strnum = Integer.toString(num);

        for (int beg = 0, end = strnum.length()-1; beg < end; beg++, end--) {

            if (strnum.charAt(beg) != strnum.charAt(end)) {
                //System.out.println("Not a palindrome " + num);
                return false;
            }
        }
        return true;
    }

    public static boolean isPrime(int num) {

        //special case 2 is the only even prime number
        if (num == 2) return true;

        //check if num is even, divisible by 2
        if (num % 2 == 0) return false;

        //check if num is divisible by odd numbers
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static boolean isPrimePalindrome(int num) {
        if (isPalindrome(num) && isPrime(num)) {
            return true;
        }
        else {
            return false;
        }
    }
}
