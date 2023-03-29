/*  [7 kyu] Exes and Ohs

    Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

    Examples input/output:

    XO("ooxx") => true
    XO("xooxx") => false
    XO("ooxXm") => true
    XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
    XO("zzoo") => false
*/

function XO(string) {
    string = string.toLowerCase()
    count = [0, 0]
    for (index in string) {
        if (string[index] == 'o') count[0] += 1
        else if (string[index] == 'x') count[1] += 1
    }
    return count[0] == count[1]
}


console.log(XO('oojxx'))
