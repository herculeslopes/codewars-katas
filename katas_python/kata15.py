''' [5 kyu] String incrementer
    Your job is to write a function which increments a string, to create a new string.

    If the string already ends with a number, the number should be incremented by 1.
    If the string does not end with a number. the number 1 should be appended to the new string.
    Examples:

    foo -> foo1

    foobar23 -> foobar24

    foo0042 -> foo0043

    foo9 -> foo10

    foo099 -> foo100

    Attention: If the number has leading zeros the amount of digits should be considered.
    '''

import re
digitRegex = re.compile(r'\d{0,}$')

def increment_string(string):
    mo = digitRegex.search(string)
    number = mo.group()
    if len(number) == 0:
        string += '1'
        # return string
    else:
        string = string[:-len(number)]
        string += f'{int(number) + 1:0>{len(number)}}'
    
    return string

print(increment_string('foo00'))
