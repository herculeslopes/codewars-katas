''' [6 kyu] Create Phone Numbe
    Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.
    Example
    create_phone_number([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) # => returns "(123) 456-7890"
    The returned format must be correct in order to complete this challenge.
    Don't forget the space after the closing parentheses!
    '''

def create_phone_number(numbers):
    phonenumber = '('
    for pos, n in enumerate(numbers):
        if pos < 3:
            phonenumber += str(n)
        elif pos == 3:
            phonenumber += f') {n}'
        elif pos < 6:
            phonenumber += str(n)
        elif pos == 6:
            phonenumber += f'-{n}'
        else:
            phonenumber += str(n)

    return phonenumber


myphone = create_phone_number([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])
print(myphone)
