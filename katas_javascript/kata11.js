/* [7 kyu] String ends with?


    Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

    Examples:

    solution('abc', 'bc') // returns true
    solution('abc', 'd') // returns false
*/

function solution(str, ending) {
    if (ending.length == 0) return true;
    else if (ending.length > str.length) return false;
    let ending_i = ending.length;
    for (let i = str.length - 1; i >= 0; i--) {
        ending_i--;
        if (str[i] != ending[ending_i]) return false;
        if (ending_i == 0) return true;
    }
    return true;
}

console.log(solution('Herkules', 'rkules'));
