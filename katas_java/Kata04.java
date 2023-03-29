/*  7 kyu Descending Order
    Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

    Examples:
    Input: 42145 Output: 54421

    Input: 145263 Output: 654321

    Input: 123456789 Output: 987654321
*/

package katas_java;

import java.util.*;

public class Kata04 {
    public static void main(String[] args) {
        int newNumber = new Kata04().sortDesc(224433);
        System.out.println(newNumber);
    }

    public int sortDesc(int integer) {
        ArrayList<Integer> sortedList = new ArrayList<Integer>();
        String current = String.valueOf(integer);
        int swap = 0;
        for (int i = 0; i < current.length(); i++) {
            sortedList.add(Character.getNumericValue((current.charAt(i))));
        }
        current = "";
        for (int run1 = 0; run1 < sortedList.size(); run1++) {
            for (int run2 = run1; run2 < sortedList.size(); run2++) {

                if (sortedList.get(run2) > sortedList.get(run1)) {
                    swap = sortedList.get(run1);
                    sortedList.set(run1, sortedList.get(run2));
                    sortedList.set(run2, swap);
                }
            }
            current += sortedList.get(run1);
        }

        return Integer.parseInt(current);
    }
}
