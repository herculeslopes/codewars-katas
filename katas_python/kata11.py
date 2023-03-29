''' [5 kyu] Calculating with Functions

    This time we want to write calculations using functions and get the results. Let's have a look at some examples:

    seven(times(five())) # must return 35
    four(plus(nine())) # must return 13
    eight(minus(three())) # must return 5
    six(divided_by(two())) # must return 3
    Requirements:

    There must be a function for each number from 0 ("zero") to 9 ("nine")
    There must be a function for each of the following mathematical operations: plus, minus, times, dividedBy (divided_by in Ruby and Python)
    Each calculation consist of exactly one operation and two numbers
    The most outer function represents the left operand, the most inner function represents the right operand
    Division should be integer division. For example, this should return 2, not 2.666666...:
    eight(divided_by(three()))
    '''

# Operations 
def check_op(expression):
    if expression[1] == '+': return expression[0] + expression[2]
    elif expression[1] == '-': return expression[0] - expression[2]
    elif expression[1] == '*': return expression[0] * expression[2]
    elif expression[1] == '/': return expression[0] // expression[2] if 0 not in expression else 0


def plus(n):
    operation = ['+', n]
    return operation


def minus(n):
    operation = ['-', n]
    return operation


def times(n):
    operation = ['*', n]
    return operation


def divided_by(n):
    operation = ['/', n]
    return operation

# Numbers
def zero(expression=None):
    if expression == None: return 0
    expression.insert(0, 0)
    return check_op(expression)


def one(expression=None):
    if expression == None: return 1
    expression.insert(0, 1)
    return check_op(expression)


def two(expression=None):
    if expression == None: return 2
    expression.insert(0, 2)
    return check_op(expression)


def three(expression=None):
    if expression == None: return 3
    expression.insert(0, 3)
    return check_op(expression)


def four(expression=None):
    if expression == None: return 4
    expression.insert(0, 4)
    return check_op(expression)


def five(expression=None):
    if expression == None: return 5
    expression.insert(0, 5)
    return check_op(expression)


def six(expression=None):
    if expression == None: return 6
    expression.insert(0, 6)
    return check_op(expression)


def seven(expression=None):
    if expression == None: return 7
    expression.insert(0, 7)
    return check_op(expression)


def eight(expression=None):
    if expression == None: return 8
    expression.insert(0, 8)
    return check_op(expression)


def nine(expression=None):
    if expression == None: return 9
    expression.insert(0, 9)
    return check_op(expression)


print(f'Conta: {two(divided_by(zero()))}')
