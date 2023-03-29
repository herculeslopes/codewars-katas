/*  [6 kyu] Multiples of 3 or 5
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

    Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in. Additionally, if the number is negative, return 0  (for languages that do have them).

    Note: If the number is a multiple of both 3 and 5, only count it once.
    
    Courtesy of projecteuler.net (Problem 1)
*/

package katas_java;

public class Kata01 {
    public static void main(String[] args) {
        System.out.println(new Kata01().Multiple(10));   
    }
    
    public int Multiple(int number) {
        if (number < 0) return 0;
        int sum = 0;
        for (int i = number - 1; i >=3; i--) {
            if (i % 5 == 0 || i % 3 == 0) sum += i;
        }
        return sum;
    }
}
