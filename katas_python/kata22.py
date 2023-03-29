# 6 kyu Multiplication table

''' Your task, is to create NxN multiplication table, of size provided in parameter.

    for example, when given size is 3:

    1 2 3
    2 4 6
    3 6 9
    for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]]
    '''

def multiplication_table(size):
    table = []
    for i in range(1, size + 1):
        line = []
        for ii in range(1, size + 1):
            num = i * ii
            line.append(num)
        table.append(line)
    
    return table

print(multiplication_table(3))
