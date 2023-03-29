''' [5 kyu] Moving Zeros To The End
    Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

    move_zeros([1, 0, 1, 2, 0, 1, 3]) # returns [1, 1, 2, 1, 3, 0, 0]
    '''

def move_zeros(array):
    moved = []
    zeros = 0
    for value in array:
        if value == 0:
            zeros += 1
        else:
            moved.append(value)
    for z in range(zeros): moved.append(0)
    return moved

print(move_zeros([1, 0, 1, 2, 0, 1, 3]))
