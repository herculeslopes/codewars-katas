package katas_java;

import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class codingClass {

    public static boolean isPrime(int n) {
        boolean is = false;

        if (n <= 1) {
            is = false;
        } else {
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0)  {
                    is = false;
                    break;
                } else {
                    is = true;
                }
            }
        }

        return is;
    }

    public static int getPreviousPrime(int n) {
        for (int i = n - 1; i > 2; i--) {
            if (isPrime(i)) return i;
        }

        return 0;
    }

    public static int getNextPrime(int n ) {
        int num = n;
        do {
            num++;
            if (isPrime(num)) return num;
        } while(true);

        // return 0;
    }
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        System.out.print("Número primo: ");
        int n = in.nextInt();

        // Write an answer using System.out.println()
        // To debug: System.err.println("Debug messages...");

        boolean isPrime = isPrime(n);
        
        if (isPrime) {

            int previous = getPreviousPrime(n);
            int next = getNextPrime(n);

            double mean = (double) previous / (double) next;
            
            System.out.println("Prime: " + n);
            System.out.println("Previuos Prime: " + previous);
            System.out.println("Next Prime: " + next);
            System.out.println("Mean: " + mean);

        }

        System.out.println("answer");
    }
}