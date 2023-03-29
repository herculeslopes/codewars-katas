/*  [6 kyu] Find The Parity Outlier
    You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

    Examples
    [2, 4, 0, 100, 4, 11, 2602, 36]
    Should return: 11 (the only odd number)

    [160, 3, 1719, 19, 11, 13, -21]
    Should return: 160 (the only even number)
*/

function findOutlier(array) {
    type = (Math.abs(array[0] % 2) + Math.abs(array[1] % 2) + Math.abs(array[2] % 2)) >= 2 ? 'odd' : 'even'
    if (type == 'odd') {
        for (integer in array) {
            if (Math.abs(array[integer] % 2) == 0) return array[integer]
        }
    } else {
        for (integer in array) {
            if (Math.abs(array[integer] % 2) == 1) return array[integer]
        }
    }
}

console.log(findOutlier([-116805013,-2801001,-122853129,56299303,4850195,-18485859,-148347703,44208303,42428167,69062011,-121400409,-128586447,137317571,-189123303,-187056871,48996563,149565899,55141803,-89212869,-64679439,-116001683,195551785,-54618623,-164597287,-1518617,-16685294,192591817,-22615711,186882999,-156796725,179037713,-175154215,139625967,146848803,56782015,170254479,116359211,-149731963,6213693,-60464815,145265815,-76609221,19928379,16056723,-30252567]))
