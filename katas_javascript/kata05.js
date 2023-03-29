/*  [7 kyu] Binary Addition

    Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

    The binary number returned should be a string.

    Examples:

    add_binary(1, 1) == "10" (1 + 1 = 2 in decimal or 10 in binary)
    add_binary(5, 9) == "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/

function getBinary(number) {
    return (number >>> 2).toString()
}

function addBinary(n1, n2) {
    let sum = n1 + n2
    // return (sum >>> 0).toString(2)
    return sum.toString(2)
}

console.log(addBinary(5, 9))
