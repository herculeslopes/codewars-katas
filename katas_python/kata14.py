''' [6 kyu] Count characters in your string
    The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

    What if the string is empty? Then the result should be empty object literal, {}.
    '''

def count(string):
    if string == '': return {}
    chars = {}
    for letter in string:
        if letter not in chars: chars[letter] = 1
        else: chars[letter] += 1

    return chars

print(count('lluuccaass'))
