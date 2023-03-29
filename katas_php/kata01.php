<!-- [8 kyu] Find the smallest integer in the array

    Given an array of integers your solution should find the smallest integer.

    For example:

    Given [34, 15, 88, 2] your solution will return 2
    Given [34, -345, -1, 100] your solution will return -345
    You can assume, for the purpose of this kata, that the supplied array will not be empty.
-->

<?php
    function smallestInteger ($arr) {
        for ($contador = 0; $contador < count($arr); $contador++) {
            if ($contador == 0) $menor = $arr[$contador];
            else if ($arr[$contador] < $menor) $menor = $arr[$contador]; // It's working tho
        }
        return $menor;
    }
?>