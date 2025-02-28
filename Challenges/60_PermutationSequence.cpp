class Solution
{
public:
    void permutation(int index, vector<vector<int>> &result, vector<int> combi, vector<int> nums, int &k)
    {
        if (k <= 0)
        {
            return;
        }
        if (index == nums.size() - 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                combi.push_back(nums[i]);
            }
            result.push_back(combi);
            k--;
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            // combi.push_back(nums[index]);
            permutation(index + 1, result, combi, nums, k);
            // swap back so it can be re-used by the next iteration
            swap(nums[index], nums[i]);
        }
    };
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        vector<int> combi;
        string final;
        int nth = k - 1;
        vector<vector<int>> result;
        permutation(0, result, combi, nums, k);
        for (int i = 0; i < result[nth].size(); i++)
        {
            final.append(to_string(result[nth][i]));
        }
        return final;
    }
};