/*  [6 kyu] Array.diff 
    Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.

    It should remove all values from list a, which are present in list b keeping their order.

    Kata.arrayDiff(new int[] {1, 2}, new int[] {1}) => new int[] {2}
    If a value is present in b, all of its occurrences must be removed from the other:

    Kata.arrayDiff(new int[] {1, 2, 2, 2, 3}, new int[] {2}) => new int[] {1, 3}
*/

package katas_java;

import java.util.*; 

public class Kata02 {
    public static void main(String[] args) {
        int[] list1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int[] list2 = {3, 5, 7};
        int[] newList = new Kata02().arrayDiff(list1, list2);
        System.out.println(Arrays.toString(newList));
    }

    public int[] arrayDiff(int[] list1, int[] list2) {
        ArrayList<Integer> list3 = new ArrayList<Integer>();
        boolean exisits = false;

        for (int l1 = 0; l1 < list1.length; l1++) {
            for (int l2 = 0; l2 < list2.length; l2++) {
                if (list1[l1] == list2[l2]) {
                    exisits = true;
                    break;
                }
            }
            if (!exisits) {
                list3.add(list1[l1]);
            } else {
                exisits = false;
            }
        }

        int[] array = list3.stream().mapToInt(i -> i).toArray();

        return array;
    }
}
