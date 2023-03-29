''' [5 kyu] Maximum subarray sum

    The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

    max_sequence([-2, 1, -3, 4, -1, 2, 1, -5, 4])
    # should be 6: [4, -1, 2, 1]
    Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

    Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.
    '''

def max_sequence(array):
    if array == []: return 0
    for init_sequence in range(len(array)):
        sequence = []
        new_sequence = []

        for integer_index in range(init_sequence, len(array)):
            new_sequence.append(array[integer_index])
            if integer_index == 0:
                sequence = new_sequence[:]
            elif sum(new_sequence) > sum(sequence):
                sequence = new_sequence[:]

        if init_sequence == 0:
            maximum_sequence = sequence[:]
        elif sum(sequence) > sum(maximum_sequence):
            maximum_sequence = sequence[:]

    return sum(maximum_sequence) if not maximum_sequence == [] else 0

print(max_sequence([5, 6, 7, 8]))

