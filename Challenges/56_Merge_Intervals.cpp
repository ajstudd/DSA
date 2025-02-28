// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> result;
//         int size = intervals.size();
//         int lastVal = 0;
//         vector<int> range(10001, -1);

//         for (int i = 0; i < size; i++) {
//             for (int j = intervals[i][0]; j < intervals[i][1]; j++) {
//                 if (range[j] != -1) {
//                     range[j] = range[j];
//                 } else {
//                     range[j] = i;
//                 }
//             }
//             if(intervals[i][0]==[i][1]){

//             }
//             lastVal = max(lastVal, intervals[i][1]);
//         }

//         int start = -1, end = -1;
//         for (int i = 0; i <= lastVal; i++) {
//             if (start == -1 && range[i] != -1) {
//                 start = i;
//             }
//             if (range[i + 1] == -1 && start != -1) {
//                 end = i+1;
//                 result.push_back({start, end});
//                 start = -1;
//                 end = -1;
//             }
//         }

//         return result;
//     }
// };
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {}; // Edge case

        // Step 1: Sort intervals by the start value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        // Step 2: Merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &lastInterval = result.back();

            if (intervals[i][0] <= lastInterval[1])
            {
                // Merge intervals
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            }
            else
            {
                // No overlap, push to result
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
