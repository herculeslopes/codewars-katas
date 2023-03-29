/* [6 kyu] Delete occurrences of an element if it occurs more than n times

    Enough is enough!
    Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, since the motive usually repeats. He isn't fond of seeing the Eiffel tower 40 times. He tells them that he will only sit during the session if they show the same motive at most N times. Luckily, Alice and Bob are able to encode the motive as a number. Can you help them to remove numbers such that their list contains each number only up to N times, without changing the order?

    Task
    Given a list lst and a number N, create a new list that contains each number of lst at most N times without reordering. For example if N = 2, and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].

    Example
    delete_nth ([1,1,1,1],2) # return [1,1]
    
    delete_nth ([20,37,20,21],1) # return [20,37,21]
*/

#include <iostream>
#include <vector>
#include <map>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> newArray = {};
    std::map<int, int> numbers;
    
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr.at(i);
        
        // Number exists in map
        // std::cout << (numbers.find(num) != numbers.end());
        if (numbers.find(num) != numbers.end())
        {
            numbers[num]++;
            if (numbers[num] < n)
                newArray.push_back(num);
        }
        else
        {
            numbers.insert(num, 1);
            newArray.push_back(num);
        }
    }

    return newArray;
}

int main()
{
    std::vector<int> vec = {1,1,1,1};

    std::vector<int> newVec = deleteNth(vec, 2);

    std::cout << "{";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << newVec[i] << ", ";
    }
    std::cout << "}";

    return 0;
}