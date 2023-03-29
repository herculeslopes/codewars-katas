/* [8 kyu] Rock Paper Scissors!

    Rock Paper Scissors
    Let's play! You have to return which player won! In case of a draw return Draw!.

    Examples:

    rps('scissors','paper') // Player 1 won!
    rps('scissors','rock') // Player 2 won!
    rps('paper','paper') // Draw!
*/

#include <iostream>
#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    if (
        p1 == "rock" && p2 == "scissors" ||
        p1 == "scissors" && p2 == "paper" ||
        p1 == "paper" && p2 == "rock"
    ) {
        return "Player 1 won!";
    } else if (p1 == p2) {
        return "Draw!";
    } else {
        return "Player 2 won!";
    }
}
