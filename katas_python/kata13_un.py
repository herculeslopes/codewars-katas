''' [4 kyu] Pyramid Slide Down

    Lyrics...
    Pyramids are amazing! Both in architectural and mathematical sense. If you have a computer, you can mess with pyramids even if you are not in Egypt at the time. For example, let's consider the following problem. Imagine that you have a pyramid built of numbers, like this one here:

    /3/
    \7\ 4 
    2 \4\ 6 
    8 5 \9\ 3
    Here comes the task...
    Let's say that the 'slide down' is the maximum sum of consecutive numbers from the top to the bottom of the pyramid. As you can see, the longest 'slide down' is 3 + 7 + 4 + 9 = 23

    Your task is to write a function longestSlideDown (in ruby/crystal/julia: longest_slide_down) that takes a pyramid representation as argument and returns its' largest 'slide down'. For example,

    longestSlideDown([[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]) => 23
    By the way...
    My tests include some extraordinarily high pyramids so as you can guess, brute-force method is a bad idea unless you have a few centuries to waste. You must come up with something more clever than that.

    (c) This task is a lyrical version of the Problem 18 and/or Problem 67 on ProjectEuler.
    '''

def longest_slide_down(pyramid):
    # slide = pyramid[0]
    slide = [pyramid[0][0]]
    print(pyramid[0][0])

    index = 0
    for column, line in enumerate(pyramid[1:]):
        print(f'Column: {column} | Line: {line} | {line[index]} | {line[index + 1]}')
        subslide = [line[index], line[index + 1]]
        slide.append(max(subslide))
        index = line.index(max(subslide))
        # highest = max(line)
        # index = line.index(highest)


    return sum(slide)

print(longest_slide_down([[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]))
'''
    Column: 0 | Line: [95, 64] | 95 | 64
    Column: 1 | Line: [17, 47, 82] | 17 | 47
    Column: 2 | Line: [18, 35, 87, 10] | 35 | 87
    Column: 3 | Line: [20, 4, 82, 47, 65] | 82 | 47
    Column: 4 | Line: [19, 1, 23, 75, 3, 34] | 23 | 75
    Column: 5 | Line: [88, 2, 77, 73, 7, 63, 67] | 73 | 7
    Column: 6 | Line: [99, 65, 4, 28, 6, 16, 70, 92] | 28 | 6
    Column: 7 | Line: [41, 41, 26, 56, 83, 40, 80, 70, 33] | 56 | 83
    Column: 8 | Line: [41, 48, 72, 33, 47, 32, 37, 16, 94, 29] | 47 | 32
    Column: 9 | Line: [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14] | 25 | 43
    Column: 10 | Line: [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57] | 73 | 17
    Column: 11 | Line: [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48] | 14 | 91
    Column: 12 | Line: [63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31] | 63 | 66
    Column: 13 | Line: [4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23] | 62 | 98
'''