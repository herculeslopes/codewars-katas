/* [5 kyu] Count IP Addresses
 
    Implement a function that receives two IPv4 addresses, and returns the number of addresses between them (including the first one, excluding the last one).

    All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.

    Examples
    * With input "10.0.0.0", "10.0.0.50"  => return   50 
    * With input "10.0.0.0", "10.0.1.0"   => return  256 
    * With input "20.0.0.10", "20.0.1.0"  => return  246
*/

package katas_java;

public class Kata18 {

    
    public static long ipsBetween(String start, String end) {
        
        
		return -1;
	}
    public static void main(String[] args) {
        // * With input "10.0.0.0", "10.0.0.50"  => return   50 
        // * With input "10.0.0.0", "10.0.1.0"   => return  256 
        // * With input "20.0.0.10", "20.0.1.0"  => return  246

        String ip1 = "10.0.0.0";
        String ip2 = "10.0.0.50";

        long count = ipsBetween(ip1, ip2);

        System.out.println("Between: " + count);
    }
}
