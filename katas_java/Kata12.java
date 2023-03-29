/* [6 kyu] Your order, please

    Your task is to sort a given string. Each word in the string will contain a single number. This number is the position the word should have in the result.

    Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

    If the input string is empty, return an empty string. The words in the input String will only contain valid consecutive numbers.

    Examples
    "is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
    "4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
    ""  -->  ""
*/

package katas_java;

import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class Kata12 {
    public static void main(String[] args) {
        String words = "ma4th progr2amming co1de chem3istry";
        System.out.println(sortedString(words));
    }

    public static String sortedString(String numWords) {
        String[] wordArray = numWords.split(" ");
        Map<Integer, String> pairs = new HashMap<Integer, String>();

        for (int wordIndex = 0; wordIndex < wordArray.length; wordIndex++) {
            String word = wordArray[wordIndex];
            for (int i = 0; i < word.length(); i++) {
                String letter = Character.toString(word.charAt(i));
                try {
                    if (Integer.parseInt(letter) < 0 || Integer.parseInt(letter) < 10) {
                        pairs.put(Integer.parseInt(letter), word);
                        continue;
                    }
                } catch (Exception e) {
                    System.out.println(e);

                }
            }
        }   

        for (int wordIndex = 0; wordIndex < pairs.size(); wordIndex++) {
            wordArray[wordIndex] = pairs.get(wordIndex + 1);
        }

        String str = wordArray[0];
        for (String word : Arrays.copyOfRange(wordArray, 1, wordArray.length)) {
            str += " " + word;
        }

        return str;
    }
}
