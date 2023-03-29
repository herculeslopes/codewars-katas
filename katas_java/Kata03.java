/*  6 kyu Bit Counting
    Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. You can guarantee that input is non-negative.

    Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*/

package katas_java;

public class Kata03 {
    public static void main(String[] args) {

        int sum = new Kata03().CountOnes(10);
        System.out.println(sum);

    }

    public int CountOnes(int integer) {
   
        String binary = Integer.toBinaryString(integer);
        System.out.printf("Binary %s\n", (binary));
        int ones = 0;
        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') ones++;
        }

        return ones;

    }
}