''' [6 kyu] Highest Rank Number in an Array

    Complete the method which returns the number which is most frequent in the given input array. If there is a tie for most frequent number, return the largest number among them.

    Note: no empty arrays will be given.

    Examples
    [12, 10, 8, 12, 7, 6, 4, 10, 12]              -->  12
    [12, 10, 8, 12, 7, 6, 4, 10, 12, 10]          -->  12
    [12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10]  -->   3
    '''

def highest_rank(arr):
    number_count = {}
    for i in arr:
        if i in number_count.keys():
            number_count[i] += 1
        else:
            number_count[i] = 1
    numbers = list(number_count.keys())
    most = []
    for index, i in enumerate(list(number_count.values())):
        if index == 0:
            most.append(numbers[0])
        elif i > number_count[most[0]]: 
            most = [numbers[index]]
        elif i == number_count[most[0]]:
            most.append(numbers[index])
    return max(most)

print(highest_rank([4, 3, 3, 5, 2, 1, 3, 4]))
