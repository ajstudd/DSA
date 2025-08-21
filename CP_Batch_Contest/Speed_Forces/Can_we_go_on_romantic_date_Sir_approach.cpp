#include <iostream>
#include <vector>
using namespace std;
// could have been solved using alternating prefix sum
// array : 2,6,1,5,7,8
// even prefix : 0,0,6,6,11,11,19
// odd prefix : 0,2,2,3,3,10,10
// or prefix XOR?

// map<int, int> freq;
// int satisfy = 0;
// freq[0]++;
// for(int i=1;i<=n;i++){
//     int diff = evenPrefix[i]-oddPrefix[i];
//     if(freq[diff]>0){
//         satisfy++;
//     }
//     freq[diff]++;
// }
// if(satisfy) cout << YES;
// else cout << NO;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        bool subArrayHasEqualDrink = false;

        for (int i = 0; i < n && !subArrayHasEqualDrink; i++)
        {
            int IuliaDrinks = 0, DateDrinks = 0;
            for (int j = i; j < n; j++)
            {
                if ((j - i) % 2 == 0)
                {
                    DateDrinks += nums[j];
                }
                else
                {
                    IuliaDrinks += nums[j];
                }

                if (IuliaDrinks == DateDrinks)
                {
                    subArrayHasEqualDrink = true;
                    break;
                }
            }
        }

        cout << (subArrayHasEqualDrink ? "YES" : "NO") << endl;
    }
    return 0;
}