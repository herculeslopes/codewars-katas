/* [6 kyu] Counting Duplicates

    Count the number of Duplicates
    Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

    Example
    "abcde" -> 0 # no characters repeats more than once
    "aabbcde" -> 2 # 'a' and 'b'
    "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
    "indivisibility" -> 1 # 'i' occurs six times
    "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
    "aA11" -> 2 # 'a' and '1'
    "ABBA" -> 2 # 'A' and 'B' each occur twice
*/

/*
function addToSum(total, init) {
    return total + init
}

function duplicateCount(text) {
    let chars = []
    let count = []

    for (let i = 0; i < text.length; i++) {

        let character = text[i].toLowerCase()

        if (chars.indexOf(character) != -1) {
            count[chars.indexOf(character)] += 1
        } else {
            chars.push(character)
            count.push(1)
        }
        console.log(`character: ${character}`)
        console.log(`chars: ${chars}`)
        console.log(`count: ${count}`)
        console.log()

    }
    console.log(`count is at: ${count}`)
    return count.reduce(addToSum, 0) - chars.length
}
*/
function countChars(char, string) {
    let count = 0
    for (let index in string) {
        if (string[index] == char) count += 1
    }
    return count
}

function duplicateCount(text) {
    let duplicates = []
    let count = 0
    for (let index in text) {
        let char = text[index].toLowerCase()
        if (countChars(char, text.toLowerCase()) > 1 && duplicates.indexOf(char) == -1) {
            duplicates.push(char)
            count += 1
        }
    }
    return count
}

console.log('This is the start')
console.log(duplicateCount('aabBcde'))
// console.log(countChars('i', 'invincible'))

