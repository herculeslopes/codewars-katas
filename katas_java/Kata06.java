/* [5 kyu] Scramblies

    Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

    Notes:

    Only lower case letters will be used (a-z). No punctuation or digits will be included.
    Performance needs to be considered
    Input strings s1 and s2 are null terminated.
    Examples
    scramble('rkqodlw', 'world') ==> True
    scramble('cedewaraaossoqqyt', 'codewars') ==> True
    scramble('katas', 'steak') ==> False
*/

package katas_java;

import java.util.*;

public class Kata06 {
    public static void main(String[] args) {
        boolean canScramble = new Kata06().Scramble("katas", "steak");
        System.out.println("canScramble: " + canScramble);
    }
    public boolean Scramble(String str1, String str2) {
        List<String> chars = new ArrayList<String>();
        List<Integer> countStr2 = new ArrayList<Integer>();
        boolean isPossible = true;
        String letter;
        int letterIndex;

        for (int i = 0; i < str2.length(); i++) {
            letter = Character.toString(str2.charAt(i));
            letterIndex = chars.indexOf(letter);

            if (letterIndex == -1) {
                chars.add(letter);
                countStr2.add(1);
            } else {
                countStr2.set(letterIndex, countStr2.get(letterIndex) + 1);
            }
        }

        int[] countStr1 = new int[countStr2.size()];

        for (int j = 0; j < str1.length(); j++) {
            letter = Character.toString(str1.charAt(j));
            letterIndex = chars.indexOf(letter);
            if (letterIndex != -1) {
                countStr1[letterIndex] += 1;
            }
        }

        System.out.println("str.size() = " + countStr1.length);
        for (int k = 0; k < countStr1.length; k++) {
            if (countStr1[k] < countStr2.get(k)) {
                isPossible = false;
            }
        }

        System.out.println("chars: " + chars.toString());
        System.out.println("countStr1: " + Arrays.toString(countStr1));
        System.out.println("countStr2: " + countStr2.toString());

        return isPossible;
    }
}
