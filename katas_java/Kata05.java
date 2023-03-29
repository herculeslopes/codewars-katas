/* [6 kyu] Two Sum

    Write a function that takes an array of numbers (integers for the tests) and a target number. It should find two different items in the array that, when added together, give the target value. The indices of these items should then be returned in a tuple like so: (index1, index2).

    For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

    The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; target will always be the sum of two different items from that array).

    Based on: http://oj.leetcode.com/problems/two-sum/

    twoSum [1, 2, 3] 4 === (0, 2)

 */

package katas_java;

import java.util.*;

public class Kata05 {
    public static void main(String[] args) {

        int[] myArray = {1, 2, 3};
        System.out.println(Arrays.toString((new Kata05().twoSum(myArray, 4))));

    }
    public int[] twoSum(int[] array, int target) {
        List<Integer> indices = new ArrayList<Integer>();
        int n1 = 0, n2 = 0;
        boolean found = false;

        for (int i = 0; i < array.length - 1; i++) {
            n1 = i;
            for (int j = i + 1; j < array.length; j++) {
                n2 = j;
                if (array[n1] + array[n2] == target) found = true;
                if (found) break;
            }
            if (found) break;
        }

        indices.add(n1);
        indices.add(n2);

        return indices.stream().mapToInt(i -> i).toArray();
    }
}
