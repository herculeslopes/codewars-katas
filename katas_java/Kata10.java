/* [6 kyu] Are they the "same"?

    Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements, with the same multiplicities. "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.

    Examples
    Valid arrays
    a = [121, 144, 19, 161, 19, 144, 19, 11]  
    b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
    comp(a, b) returns true because in b 121 is the square of 11, 14641 is the square of 121, 20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. It gets obvious if we write b's elements in terms of squares:

    a = [121, 144, 19, 161, 19, 144, 19, 11] 
    b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
    Invalid arrays
    If, for example, we change the first number to something else, comp may not return true anymore:

    a = [121, 144, 19, 161, 19, 144, 19, 11]  
    b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
    comp(a,b) returns false because in b 132 is not the square of any number of a.

    a = [121, 144, 19, 161, 19, 144, 19, 11]  
    b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
    comp(a,b) returns false because in b 36100 is not the square of any number of a.

    Remarks
    a or b might be [] or {} (all languages except R, Shell).
    a or b might be nil or null or None or nothing (except in C++, Elixir, Haskell, PureScript, Pascal, Perl, R, Rust, Shell).
    If a or b are nil (or null or None, depending on the language), the problem doesn't make sense so return false.

    Note for C
    The two arrays have the same size (> 0) given as parameter in function comp.
*/

package katas_java;

import java.util.Arrays;

public class Kata10 {
    public static void main(String[] args) {
        // int[] a = {121, 144, 19, 161, 19, 144, 19, 11};
        // int[] b = {121, 14641, 20736, 361, 25921, 361, 20736, 361};

        int[] a = {121, 144, 19, 161, 19, 144, 19, 11};
        int[] b = {122, 14641, 20736, 361, 25921, 361, 20736, 361};
        
        System.out.println(new Kata10().compSame(a, b));
    }

    public boolean compSame(int[] a, int[] b) {
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));
        if (a == null || b == null) return false;
        if ((a.length == 0 && b.length != 0) || (a.length != 0 && b.length == 0)) return false;
        else if (a.length == 0 && b.length == 0) return true;
        System.out.println(a.length);
        System.out.println(b.length);
        Arrays.sort(a);
        Arrays.sort(b);
    
        for (int i = 0; i < a.length; i++) {
          int numberA = a[i];
          int numberB = b[i];
          System.out.printf("A: %d | B: %d", numberA, numberB);
          if (numberB != Math.pow(numberA, 2)) return false;
        }
    
        return true;
    }
}
