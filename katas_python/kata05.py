''' [7 kyu] Mumbling
    This time no story, no theory. The examples below show you how to write function accum:

    Examples:
    accum("abcd") -> "A-Bb-Ccc-Dddd"
    accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
    accum("cwAt") -> "C-Ww-Aaa-Tttt"
    The parameter of accum is a string which includes only letters from a..z and A..Z.
    '''

def accum(letters):
    finalstring = ''
    for index, letter in enumerate(letters):
        print(f'Index: {index} | Letter: {letter}')
        midstring = ''
        for i in range(index+1):
            midstring += letter
        finalstring += midstring.title() + '-' if not index == len(letters) - 1 else midstring.title()
    
    return finalstring


print(accum('abcd'))
