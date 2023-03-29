/* [5 kyu] Simple Pig Latin

    Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

    Examples
    pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
    pigIt('Hello world !');     // elloHay orldway !
 */

package katas_java;

import java.util.ArrayList;

public class Kata13 {
    public static void main(String[] args) {
        String str = "Hello world !";
        String result = pigInt(str);
        System.out.println(result);
    }

    public static String pigInt(String str) {
        String[] sentence = str.split(" ");
        ArrayList<String> newWords = new ArrayList<String>();

        String newWord;
        for (String word : sentence) {
            if (!word.equals("!") && !word.equals("?")) {
                char firstLetter = word.charAt(0);
                newWord = word.substring(1) + Character.toString(firstLetter) + "ay";
            } else {
                newWord = word;
            }
            newWords.add(newWord);
        }

        return String.join(" ", newWords);
    }
}