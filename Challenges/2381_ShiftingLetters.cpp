// // initial insight : using mod to get how much more than 26
// // abc
// //  shifts = [[0,1,0],[1,2,1],[0,2,1]]
// //  0: zac
// //  1: zbd
// //  2: ace

// // a -- 97
// // z -- 122
// class Solution {
// public:
//     string shifted(string s, int d, int start, int end) {
//         for (int i = start; i <= end; i++) {
//             int ascii = s[i];
//             if (d == 1 && ascii == 122) {
//                 s[i] = char(97);
//             } else if (d == 0 && ascii == 97) {
//                 s[i] = char(122);
//             } else {
//                 if (d == 1) {
//                     s[i]++;
//                 } else {
//                     s[i]--;
//                 }
//             }
//         }
//         return s;
//     }
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         //instead of shifting all , just find the count of shift each char will have, then do it at end.
//         for (int i = 0; i < shifts.size(); i++) {
//             int direction = shifts[i][2];
//             int start = shifts[i][0];
//             int end = shifts[i][1];
//             s = shifted(s, direction, start, end);
//         }
//         return s;
//     }
// };

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> delta(n + 1, 0); // Prefix sum array to store net shifts

        // Populate the delta array based on the shifts
        for (const auto &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            if (direction == 1)
            {
                delta[start] += 1;
                delta[end + 1] -= 1;
            }
            else
            {
                delta[start] -= 1;
                delta[end + 1] += 1;
            }
        }

        // Compute the prefix sum to find net shifts for each character
        int netShift = 0;
        for (int i = 0; i < n; i++)
        {
            netShift += delta[i];
            // Apply the shift to the character
            int shiftAmount = (netShift % 26 + 26) % 26; // Normalize to [0, 25]
            s[i] = char((s[i] - 'a' + shiftAmount) % 26 + 'a');
        }

        return s;
    }
};
