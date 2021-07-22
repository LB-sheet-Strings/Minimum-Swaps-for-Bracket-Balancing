/*
This is GFG solution. revise it later

Pending : check function:
. Go through the string maintaining a count of the number of ‘[‘ brackets encountered. 
Reduce this count when we encounter a ‘]’ character. 
If the count hits negative, then we must start balancing the string.

*/

#include <bits/stdc++.h>
using namespace std;
 
long swapCount(string chars)
{
     
    // Stores total number of Left and
    // Right brackets encountered
    int countLeft = 0, countRight = 0;
     
    // swap stores the number of swaps
    // required imbalance maintains
    // the number of imbalance pair
    int swap = 0 , imbalance = 0;
      
    for(int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {
             
            // Increment count of Left bracket
            countLeft++;
             
            if (imbalance > 0)
            {
                 
                // swaps count is last swap count + total
                // number imbalanced brackets
                swap += imbalance;
                 
                // imbalance decremented by 1 as it solved
                // only one imbalance of Left and Right
                imbalance--;    
            }
        }
        else if(chars[i] == ']' )
        {
             
            // Increment count of Right bracket
            countRight++;
             
            // imbalance is reset to current difference
            // between Left and Right brackets
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}
 
// Driver code 
int main()
{
    string s = "[]][][";
    cout << swapCount(s) << endl;
 
    s = "[[][]]";
    cout << swapCount(s) << endl;
 
    return 0;
}
