// class Solution {
// public:
//     int baseToOnesFinder(int num, int base) {
//         int converted = 0;
//         int value = num;
//         while (value > 0 && base <= num) {
//             int rem = value % base;
//             if (rem == 0) {
//                 return baseToOnesFinder(num, (base + 1));
//             } else {
//                 //issue is here
//                 converted = (10 * converted) + (rem);
//                 value = value / base;
//             }
//         }
//         return base;
//     };
//     string smallestGoodBase(string n) {
//         long long stringToNum = stoll(n); // Use stoll instead of stoi
//         string base = to_string(baseToOnesFinder(stringToNum, 1));
//         return base;
//     }
// };

// class Solution {
// public:
//     bool isAllOnes(int num, int base) {
//         while (num > 0) {
//             int rem = num % base;
//             if (rem != 1) return false;
//             num /= base;
//         }
//         return true;
//     }

//     int baseToOnesFinder(int num, int base) {
//         if (base >= num) return num - 1;

//         while (base < num) {
//             if (isAllOnes(num, base)) {
//                 return base;
//             }
//             base++;
//         }
//         return num - 1;
//     }

//     string smallestGoodBase(string n) {
//         long long stringToNum = stoll(n);
//         string base = to_string(baseToOnesFinder(stringToNum, 2));
//         return base;
//     }
// };

// 1,2,3,4,5,6,

class Solution
{
public:
    long long convertBaseToNum(int ones, int base)
    {
        long long finalVal = 0;
        for (int i = 0; i < ones; i++)
        {
            finalVal = finalVal + (pow(base, i) * 1);
        }
        return finalVal;
    }
    int smallestGoodBaseFinder(int num)
    {
        for (int i = 63; i >= 2; i--)
        {
            long start = 2;
            long end = num - 1;
            long mid = start + (end - start) / 2;
            while (start <= end)
            {
                if (convertBaseToNum(i, mid) > num)
                {
                    end = mid - 1;
                    mid = start + (end - start) / 2;
                }
                else if (convertBaseToNum(i, mid) < num)
                {
                    start = mid + 1;
                    mid = start + (end - start) / 2;
                }
                else
                {
                    return mid;
                }
            }
        }
        return num - 1;
    }
    string smallestGoodBase(string n)
    {
        long long stringToNum = stoll(n);
        string base = to_string(smallestGoodBaseFinder(stringToNum));
        return base;
    }
};

// Sir's solution
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long long num = stol(n);
        for (long long i = 63; i >= 1; i--)
        {
            long long low = 2;
            long long high = num - 1;
            while (low <= high)
            {
                long long mid = low + (high - low) / 2;
                long long val = 0;
                long long x = 1;
                for (long long j = 1; j <= i; j++)
                {
                    val += x;
                    if (val >= num)
                        break;
                    if (j < i && ((num - val) / x) < mid)
                    {
                        val = 2e18;
                        break;
                    }
                    if (j < i)
                        x *= mid;
                }
                if (val > num)
                    high = mid - 1;
                else if (val < num)
                    low = mid + 1;
                else
                    return to_string(mid);
            }
        }
        return "";
            
    }
};