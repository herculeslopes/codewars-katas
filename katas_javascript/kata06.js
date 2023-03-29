/*  [6 kyu] Duplicate Encoder
    The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore capitalization when determining if a character is a duplicate.

    Examples
    "din"      =>  "((("
    "recede"   =>  "()()()"
    "Success"  =>  ")())())"
    "(( @"     =>  "))((" 
    Notes

    Assertion messages may be unclear about what they display in some languages. If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!
*/

function duplicateEncode(string) {
    parenthese = ''
    string = string.toLowerCase()
    for (index1 in string) {
        duplicate = false
        char = string[index1]
        for (index2 in string) {
            if (index1 != index2 && char == string[index2]) duplicate = true
        }
        if (duplicate) parenthese += ')'
        else parenthese += '('
    }
    return parenthese
}

console.log(ConvertString('Success'))
