/* [6 kyu] Multi-tap Keypad Text Entry on an Old Mobile Phone

    Prior to having fancy iPhones, teenagers would wear out their thumbs sending SMS messages on candybar-shaped feature phones with 3x4 numeric keypads.

    ------- ------- -------
    |     | | ABC | | DEF |
    |  1  | |  2  | |  3  |
    ------- ------- -------
    ------- ------- -------
    | GHI | | JKL | | MNO |
    |  4  | |  5  | |  6  |
    ------- ------- -------
    ------- ------- -------
    |PQRS | | TUV | | WXYZ|
    |  7  | |  8  | |  9  |
    ------- ------- -------
    ------- ------- -------
    |     | |space| |     |
    |  *  | |  0  | |  #  |
    ------- ------- -------
    Prior to the development of T9 (predictive text entry) systems, the method to type words was called "multi-tap" and involved pressing a button repeatedly to cycle through the possible values.

    For example, to type a letter "R" you would press the 7 key three times (as the screen display for the current character cycles through P->Q->R->S->7). A character is "locked in" once the user presses a different key or pauses for a short period of time (thus, no extra button presses are required beyond what is needed for each letter individually). The zero key handles spaces, with one press of the key producing a space and two presses producing a zero.

    In order to send the message "WHERE DO U WANT 2 MEET L8R" a teen would have to actually do 47 button presses. No wonder they abbreviated.

    For this assignment, write a module that can calculate the amount of button presses required for any phrase. Punctuation can be ignored for this exercise. Likewise, you can assume the phone doesn't distinguish between upper/lowercase characters (but you should allow your module to accept input in either for convenience).

    Hint: While it wouldn't take too long to hard code the amount of keypresses for all 26 letters by hand, try to avoid doing so! (Imagine you work at a phone manufacturer who might be testing out different keyboard layouts, and you want to be able to test new ones rapidly.)
*/

package katas_java;

import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

public class Kata15 {
    public static void main(String[] args) {
        String message = "WHERE DO U WANT 2 MEET L8R";

        int tot = presses(message);
        System.out.println(tot);
    }

    public static int presses(String phrase) {
        phrase = phrase.toLowerCase();
        Map<Integer, String[]> dictionary = new HashMap<Integer, String[]>();

        dictionary.put(1, new String[]{"1"});
        dictionary.put(2, new String[]{"a", "b", "c", "2"});
        dictionary.put(3, new String[]{"d", "e", "f", "3"});
        dictionary.put(4, new String[]{"g", "h", "i", "4"});
        dictionary.put(5, new String[]{"j", "k", "l", "5"});
        dictionary.put(6, new String[]{"m", "n", "o", "6"});
        dictionary.put(7, new String[]{"p", "q", "r", "s", "7"});
        dictionary.put(8, new String[]{"t", "u", "v", "8"});
        dictionary.put(9, new String[]{"w", "x", "y", "z", "9"});
        dictionary.put(0, new String[]{" ", "0"});
        dictionary.put(11, new String[]{"*"});
        dictionary.put(12, new String[]{"#"});

        int totalPresses = 0;

        for (char character : phrase.toCharArray()) {
            String letter = Character.toString(character);

            for (Map.Entry<Integer, String[]> entry : dictionary.entrySet()) {
                int key = entry.getKey();
                String[] options = entry.getValue();

                boolean contains =  Arrays.stream(options).anyMatch(letter::equals);

                
                if (contains) {
                    // int indexOfChar = Arrays.toString(options).indexOf(letter);
                    int indexOfChar = String.join("", options).indexOf(letter);
                    int optionPos = indexOfChar + 1;
            
                    System.out.println(String.join("", options));
                    System.out.println("letter: " + letter + " | " + contains);
                    System.out.println("key: " + key + " | pos: " + optionPos);
                    // System.out.println("tot: " + totalPresses);
                    System.out.println();

                    totalPresses += optionPos;
                }

            }
        }

        return totalPresses;
    }
}
