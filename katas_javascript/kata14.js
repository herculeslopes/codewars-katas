/* [6 kyu] Roman Numerals Encoder

    Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral representation of that integer.

    Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

    Example:

    solution(1000); // should return 'M'
    Help:

    Symbol    Value
    I          1
    V          5
    X          10
    L          50
    C          100
    D          500
    M          1,000
    Remember that there can't be more than 3 identical symbols in a row.

    More about roman numerals - http://en.wikipedia.org/wiki/Roman_numerals
*/

function solution (number) {
    let roman = '';

    let thousands = hundreds = tens = units = 0;

    if (number >= 1000) {
        thousands = Math.floor(number / 1000);
        number -= thousands * 1000;
        roman += 'M'.repeat(thousands);
    }
    if (number >= 900) {
        roman += 'CM';
        number -= 900;
    } else if (number >= 500) {
        roman += 'D';
        number -= 500
    }
    if (number >= 400) {
        roman += 'CD';
        number -= 400;
    } else {
        hundreds = Math.floor(number / 100);
        roman += 'C'.repeat(hundreds);
        number -= hundreds * 100;
    }
    if (number >= 90) {
        roman += 'XC';
        number -= 90;
    } else if (number >= 50) {
        roman += 'L';
        number -= 50;
    }
    if (number >= 40) {
        roman += 'XL';
        number -= 40;
    } else {
        tens = Math.floor(number / 10);
        roman += 'X'.repeat(tens);
        number -= tens * 10;
    }
    if (number == 9) {
        roman += 'IX';
        number -= 9;
    } else if (number >= 5) {
        roman += 'V';
        number -= 5;
    }
    if (number == 4) {
        roman += 'IV';
    } else {
        roman += 'I'.repeat(number);
    }

    return roman;
}

console.log(solution(3470));
