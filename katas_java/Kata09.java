/* [5 kyu] Directions Reduction

    Once upon a time, on a way through the old wild mountainous west,…
    … a man was given directions to go from one point to another. The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are opposite, "WEST" and "EAST" too.

    Going to one direction and coming back the opposite direction right away is a needless effort. Since this is the wild west, with dreadfull weather and not much water, it's important to save yourself some energy, otherwise you might die of thirst!

    How I crossed a mountainous desert the smart way.
    The directions given to the man are, for example, the following (depending on the language):

    ["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
    or
    { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    or
    [North, South, South, East, West, North, West]
    You can immediatly see that going "NORTH" and immediately "SOUTH" is not reasonable, better stay to the same place! So the task is to give to the man a simplified version of the plan. A better plan in this case is simply:

    ["WEST"]
    or
    { "WEST" }
    or
    [West]
    Other examples:
    In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH" is going north and coming back right away.

    The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each other, therefore, the final result is [] (nil in Clojure).

    In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH" are not directly opposite but they become directly opposite after the reduction of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].

    Task
    Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

    The Haskell version takes a list of directions with data Direction = North | East | West | South.
    The Clojure version returns nil when the path is reduced to nothing.
    The Rust version takes a slice of enum Direction {North, East, West, South}.
    See more examples in "Sample Tests:"
    Notes
    Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
    if you want to translate, please ask before translating.
*/

package katas_java;

import java.util.*;

public class Kata09 {
    public static void main(String[] args) {
        // String[] path = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        // String[] path = {"NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"};
        String[] path = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH"};
        String[] newPath = new Kata09().dirReduc(path);
        System.out.println("Final path: " + Arrays.toString(newPath));
    }
    
    public String[] dirReduc(String[] directions) {
        List<String> shortcut = new ArrayList<String>(Arrays.asList(directions));
        List<Integer> redundancies = new ArrayList<Integer>();
        boolean toRemove;
        int last;
        int i = 1;

        do {
            System.out.println();
            System.out.println("Working on: " + String.join(", ", shortcut.toArray(new String[0])));
            System.out.println("Shortcut size: " + shortcut.size());

            System.out.println();
            toRemove = false;
            // for (int i = 1; i < shortcut.size(); i++) {
            i = 1;
            while (i < shortcut.size()) {
                last = i - 1;
                System.out.println("Current direction: " + shortcut.get(i) + " | " + "Last: " + shortcut.get(last));
                if (
                    (shortcut.get(last).equals("NORTH") && shortcut.get(i).equals("SOUTH")) ||
                    (shortcut.get(last).equals("SOUTH") && shortcut.get(i).equals("NORTH")) ||
                    (shortcut.get(last).equals("EAST") && shortcut.get(i).equals("WEST"))   ||
                    (shortcut.get(last).equals("WEST")  && shortcut.get(i).equals("EAST"))
                ) {
                    redundancies.add(last);
                    redundancies.add(i);
                    toRemove = true;
                    System.out.println("Positions " + last + " and " + i + " should be removed");
                    i += 2;
                } else {
                    i += 1; 
                }
            }

            System.out.println();

            int index;
            
            Collections.sort(redundancies, Collections.reverseOrder());
            System.out.println("To be removed: " + redundancies.toString());
            if (toRemove) {
                for (int j = 0; j < redundancies.size(); j++) {
                    index = redundancies.get(j);
                    shortcut.remove(index);
                }
            }
            redundancies.clear();
        } while (toRemove);

        return shortcut.toArray(new String[0]);
    }

}
