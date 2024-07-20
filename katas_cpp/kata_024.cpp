/* [5 kyu] Josephus Permutation

    This problem takes its name by arguably the most important event in the life of the ancient historian Josephus: according to his tale, he and his 40 soldiers were trapped in a cave by the Romans during a siege.

    Refusing to surrender to the enemy, they instead opted for mass suicide, with a twist: they formed a circle and proceeded to kill one man every three, until one last man was left (and that it was supposed to kill himself to end the act).

    Well, Josephus and another man were the last two and, as we now know every detail of the story, you may have correctly guessed that they didn't exactly follow through the original idea.

    You are now to create a function that returns a Josephus permutation, taking as parameters the initial array/list of items to be permuted as if they were in a circle and counted out every k places until none remained.

    Tips and notes: it helps to start counting from 1 up to n, instead of the usual range 0 to n-1; k will always be >=1.

    For example, with an array=[1,2,3,4,5,6,7] and k=3, the function should act this way.

    [1,2,3,4,5,6,7] - initial sequence
    [1,2,4,5,6,7] => 3 is counted out and goes into the result [3]
    [1,2,4,5,7] => 6 is counted out and goes into the result [3,6]
    [1,4,5,7] => 2 is counted out and goes into the result [3,6,2]
    [1,4,5] => 7 is counted out and goes into the result [3,6,2,7]
    [1,4] => 5 is counted out and goes into the result [3,6,2,7,5]
    [4] => 1 is counted out and goes into the result [3,6,2,7,5,1]
    [] => 4 is counted out and goes into the result [3,6,2,7,5,1,4]
    So our final result is:

    [3,6,2,7,5,1,4]
    For more info, browse the Josephus Permutation page on wikipedia; related kata: Josephus Survivor.

    Also, live game demo by OmniZoetrope.
*/
#include <iostream>
#include <vector>

void print(std::vector < int > v)
{
    for (unsigned long j = 0; j < v.size(); j++)
    {
        std::cout << v[j] << " - ";
    }

    std::cout << std::endl;
}

std::vector < int> josephus(std::vector < int > items, int k) {
    std::cout << std::endl << "josephus()" << std::endl << std::endl;
  
    std::cout << "k: " << k << std::endl;
    print(items);
  
    std::vector < int > permutation;

    int i = -1;

    std::cout << "Size: " << items.size() << std::endl;
  
    while (items.size())
    {
        i += k;
        if ((unsigned) i > items.size() - 1) {
          std::cout << "IF TRUE" << std::endl;
          i = i % items.size();
        }
        
        std::cout << "Items[" << i << "]: " << items[i] << std::endl;
        
        permutation.push_back(items[i]);
        items.erase(items.begin() + i);

      
        i--;
        
    std::cout << "Size: " << items.size() << std::endl;
      
    }
  
//     for (unsigned long j = 0; j < permutation.size(); j++)
//     {
//         std::cout << permutation[j] << std::endl;
//     }

    print(permutation);
  
    return permutation;
}

int main()
{
    std::vector < int > v;

    // v.push_back(4);
    // v.push_back(6);
    // v.push_back(8);
    
    // std::cout << "Size: " << v.size() << std::endl;
    
    // for (int i = 0; i < v.size(); i++)
    // {
    //     std::cout << v[i] << std::endl;
    // }
    
    // v.erase(v.begin() + 1);
    
    // std::cout << "Size: " << v.size() << std::endl;

    // std::cout << "Hello world" << std::endl;
    
    return 0;
}