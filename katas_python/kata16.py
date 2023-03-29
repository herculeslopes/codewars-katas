''' [5 kyu] Common Denominators

    Common denominators

    You will have a list of rationals in the form

    { {numer_1, denom_1} , ... {numer_n, denom_n} } 
    or
    [ [numer_1, denom_1] , ... [numer_n, denom_n] ] 
    or
    [ (numer_1, denom_1) , ... (numer_n, denom_n) ] 
    where all numbers are positive ints. You have to produce a result in the form:

    (N_1, D) ... (N_n, D) 
    or
    [ [N_1, D] ... [N_n, D] ] 
    or
    [ (N_1', D) , ... (N_n, D) ] 
    or
    {{N_1, D} ... {N_n, D}} 
    or
    "(N_1, D) ... (N_n, D)"
    depending on the language (See Example tests) in which D is as small as possible and

    N_1/D == numer_1/denom_1 ... N_n/D == numer_n,/denom_n.
    Example:
    convertFracs [(1, 2), (1, 3), (1, 4)] `shouldBe` [(6, 12), (4, 12), (3, 12)]
    Note:
    Due to the fact that the first translations were written long ago - more than 6 years - these first translations have only irreducible fractions.

    Newer translations have some reducible fractions. To be on the safe side it is better to do a bit more work by simplifying fractions even if they don't have to be.

    Note for Bash:
    input is a string, e.g "2,4,2,6,2,8" output is then "6 12 4 12 3 12"
    '''

import math
# Python 3.9+
'''
def convert_fracts(lst):
    denominators = [frac[1] for frac in lst]
    lcm = math.lcm(*denominators)
    newfracs = [(int(frac[0] * (lcm / frac[1])), lcm) for frac in lst]
    return newfracs'''

# For Codewars (Python 3.8)
import math
from functools import reduce
def convert_fracts(lst):
    denominators = [frac[1] for frac in lst]
    if denominators == []: return []
    lcm = abs(denominators[0] * denominators[1]) // math.gcd(denominators[0], denominators[1])
    for index, den in enumerate(denominators):
        if not index == 0:
            lcm = abs(lcm * den) // math.gcd(lcm, den)
    newfracs = [[int(frac[0] * (lcm // frac[1])), int(lcm)] for frac in lst]
    return newfracs

print(convert_fracts([
    (1, 2),
    (1, 3),
    (1, 4)
]))
