package katas_java;

public class PrimeTest {
    public static void main(String[] args) {
        int n = 14;

        boolean isPrime = false;
        if (n <= 1) {
            isPrime = false;
        } else if(n == 2) {
            isPrime = true;
        } else {
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0)  {
                    isPrime = false;
                    break;
                } else {
                    isPrime = true;
                }
            }
        }

        System.out.println(isPrime);
    }
}