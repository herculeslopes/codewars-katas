lowers = 'abcdefghijklmnopqrstuvwxyz'
uppers = list(lowers.upper())
lowers = list(lowers)
numbers = list('0123456789')
specials = list('.,? ')

# all_characters = lowers + uppers + numbers + specials
ALL_CHARACTERS = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? '

FORWARD_CHARACTERS = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? '
BACKWARD_CHARACTERS = FORWARD_CHARACTERS[::-1]

# all_characters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? '

def test_1():
    print(encode('áéíóú'))
    #     string = 'lll'
    #     print(string)

    #     new_string = string
    #     for i in range(100):
    #         new_string = encode(new_string)
    #         print(new_string)

    #         if new_string == string: print(i)
    
    
    print(encode("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"))
    print(encode("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"))
    print(encode("!@#$%^&*()_+-"))
    a,b,c = "", "", ""

    print()
    for index, w in enumerate("abcdefghijklmnopqrstuvwxyz"):
        print(f'{index + 1}º Iteration')
        print()
        
        
        a += encode(  "" + w)[0]
        print(f'a: {a}')
        print(f'encode( "" + {w}): {encode(  "" + w)}')
        
        b += encode( "_" + w)[1]
        print(f'b: {b}')
        print(f'encode( "_" + {w}): {encode(  "_" + w)}')
        
        c += encode("__" + w)[2]
        print(f'c: {c}')
        print(f'encode( "__" + {w}): {encode(  "__" + w)}')
        
        print()
        
    print()
    print(a)
    print(b)
    print(c)
    
    
def test_2():
    string = '?'
    print(string)
    
    lowers = 'abcdefghijklmnopqrstuvwxyz'
    
    uppers = list(lowers.upper())
    lowers = list(lowers)
    numbers = list('0123456789')
    specials = list('?., ')
    
    lista = [string]
    new_string = string
    for i in range(66):
        new_string = encode(new_string)
        print(new_string)
        lista.append(new_string)
    
    lista = [x for x in lista if x not in uppers + lowers + numbers]
    print(lista)
    

def character_change_tracker(current='e', repeat=1):

    
#     current = 'e'
#     current = '5'
    print(''.join(ALL_CHARACTERS))
    lista = [current]
#     encode_string = ''.join([current for i in range(65)])
#     new_string = string
#     repeat = 2
    for i in range(66):
#         print(f'current: {current * repeat}')
        next = encode(current * repeat)[-1]
#         print(f'next: {next}')
#         new_string = encode(new_string)
#         print(new_string)

#         lista.append(new_string)
    
        try:
            current_pos = ALL_CHARACTERS.index(current)
            next_pos = ALL_CHARACTERS.index(next)
        except ValueError:
            return
#         print(f'{current_pos} {next_pos}')
        
        
        if current_pos < next_pos:
            print(f'{" " * current_pos + "|" + "_" * (next_pos - current_pos)}')
            
        elif current_pos > next_pos:
#             print(f'{" " * current_pos + "|" + "_" * (next_pos - current_pos)}')
            print(f'{" " * next_pos + "_" * (current_pos - next_pos)}|')

        print(f'{" " * next_pos}|')
        print(''.join(ALL_CHARACTERS))
        
        current = next
        lista.append(current)
        
    print()
    print(f'Encoded String: {"".join(lista)}')
    
    
def decode(s):

#     character_change_tracker()
    
    decoded_string = ''
    isForward = True
    has_changed_direction = False

#     s = 'ae'
    print(s)
    modded_times = 0
    for index, char in enumerate(s):
#         character_change_tracker(char, index + 1)
    
        i = 0
        while i < 65: 
            
            try:
                char_pos = FORWARD_CHARACTERS.index(char) + 1
#                 print(f'Foward char ({char}) pos: {char_pos}')

#                 if isForward:
#                     char_pos = FORWARD_CHARACTERS.index(char) + 1
#                     print(f'Foward char ({char}) pos: {char_pos}')
                    
#                 else:
#                     char_pos = BACKWARD_CHARACTERS.index(char) + 1
#                     print(f'Backward char ({char}) pos: {char_pos}')
                    
                
            except ValueError:
                break
            
            
            step = 2 ** (index + 1) - 1
#             for j in range(index):
#                 step *= 2
#             print(f'step: {step}')
                
            
#             new_pos = char_pos * 2 - 1
#             print(f'char_pos: {char_pos}')
            new_pos = char_pos + (char_pos * step) - 1
#             print(f'new_pos: {new_pos}')
            quotient, remainder = divmod(new_pos, len(FORWARD_CHARACTERS))
#             print(f'quotient, remainder: {quotient, remainder}')
#             new_pos = FORWARD_CHARACTERS[quotient - remainder]
#             char = FORWARD_CHARACTERS[remainder - quotient]
#             char = FORWARD_CHARACTERS[remainder - quotient] if remainder  > quotient else FORWARD_CHARACTERS[-remainder]
#             char = FORWARD_CHARACTERS[remainder - quotient] if remainder  > quotient else FORWARD_CHARACTERS[- quotient + remainder + 1]
            if (quotient, remainder) == (79, 33):
                char = FORWARD_CHARACTERS[21]
    
#             if (quotient, remainder) == (89, 13):
#                 char = FORWARD_CHARACTERS[58]        
#             elif (quotient, remainder) == (114, 27):
#                 char = FORWARD_CHARACTERS[47]        
#             elif (quotient, remainder) == (93, 5):
#                 char = FORWARD_CHARACTERS[46]
#             elif (quotient, remainder) == (91, 9):
#                 char = FORWARD_CHARACTERS[52]
    
            if remainder  > quotient:
                char = FORWARD_CHARACTERS[remainder - quotient]
            elif remainder < quotient:
                if quotient > len(FORWARD_CHARACTERS):
#                     q_quotient, r_remainder = divmod(-quotient + remainder, 66)
#                     char = FORWARD_CHARACTERS[r_remainder + abs(q_quotient)]

#                     result = (remainder - quotient) % 66 + 1
#                     while result >= 66:
#                         quotient, remainder = divmod(result, 66)        
#                         result = remainder - quotient 
                        
                    quotient, remainder = divmod(remainder - quotient, 66)
#                     print(f'quotient, remainder: {quotient, remainder}')
                    while remainder - quotient >= 66 or remainder - quotient < 0:
                        quotient, remainder = divmod(remainder - quotient, 66)
#                         print(f'quotient, remainder: {quotient, remainder}')
                    result = remainder - quotient
                
#                     q_quotient, r_remainder = divmod(remainder - quotient, 66)
#                     char = FORWARD_CHARACTERS[r_remainder - q_quotient]
#                     print(f'r - q {result}')
                    char = FORWARD_CHARACTERS[result]
                    
#                     char = FORWARD_CHARACTERS[(-quotient + remainder +  1) % 66 + 1]
                    
                
                else:
                    char = FORWARD_CHARACTERS[-quotient + remainder + 1]
            else:
                char = FORWARD_CHARACTERS[0]
                
            
            
#             if (quotient, remainder) == (3, 1):
#                 char = FORWARD_CHARACTERS[65]
#             elif (quotient, remainder) == (14, 3):
#                 char = FORWARD_CHARACTERS[56]
#             elif (quotient, remainder) == (12, 7):
#                 char = FORWARD_CHARACTERS[62]
#             elif (quotient, remainder) == (11, 9):
#                 char = FORWARD_CHARACTERS[64]
            
#             char = FORWARD_CHARACTERS[remainder - quotient]
            
#             new_pos = char_pos + (char_pos * index * 3) - 1

#             if len(FORWARD_CHARACTERS) <= new_pos:
#                 pass
#                 if has_changed_direction:
#                     modded_times += 1
#                     print(f'dealing with mod')
# #                     print(f'new_pos = {new_pos} % {len(FORWARD_CHARACTERS)} - 1 - {modded_times} = {new_pos % len(FORWARD_CHARACTERS) - 1 - modded_times}')            
# #                     new_pos = new_pos % len(FORWARD_CHARACTERS) - 1 - modded_times
#                     print(f'new_pos = {new_pos} % {len(FORWARD_CHARACTERS)} - 2 = {new_pos % len(FORWARD_CHARACTERS) - 2}')            
#                     new_pos = new_pos % len(FORWARD_CHARACTERS) - 2
        
#                 else:
#                     print('changing direction')
#                     isForward = not isForward
#                     has_changed_direction = True
#                     continue

#             elif has_changed_direction:
#                 new_pos = new_pos % len(FORWARD_CHARACTERS) - 2
#                 has_changed_direction = False
                
            
#             char = FORWARD_CHARACTERS[new_pos] if isForward else BACKWARD_CHARACTERS[new_pos]
#             has_changed_direction = False
#             modded_times = 0
            
            i += 1
#             print(f'i = {i}')
#         print(f'For index: {index}')
        decoded_string += char
#         print('-'*100)
        print(decoded_string)
        
#         print(f'Decoded char: {char}')

    
    return decoded_string;


def minimum_result(quotient, remainder):
#     quotient, remainder = divmod(reminder - quotient, 66)
#     print(f'quotient, remainder: {quotient, remainder}')
#     result = (remainder - quotient) % 66 + 1
#     result = remainder - quotient
#     q_quotient, r_remainder = divmod(remainder - quotient, 66)
    quotient, remainder = divmod(remainder - quotient, 66)
    print(f'quotient, remainder: {quotient, remainder}')
    
#     print(f'result: {result}')
    while remainder >= 66:
        quotient, remainder = divmod(result, 66)
        print(f'quotient, remainder: {quotient, remainder}')
#         result = remainder - quotient
#         print(f'new result: {result}')
    
    return remainder - quotient


def minimum_result(quotient, remainder):
    quotient, remainder = divmod(remainder - quotient, 66)
    print(f'quotient, remainder: {quotient, remainder}')
    while remainder - quotient >= 66:
        quotient, remainder = divmod(remainder - quotient, 66)
        print(f'quotient, remainder: {quotient, remainder}')
    return remainder - quotient


