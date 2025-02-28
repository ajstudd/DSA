class Solution
{
public:
    bool parityChecker(int i, int j)
    {
        if ((i % 2 == 0 && j % 2 != 0) || (j % 2 == 0 && i % 2 != 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isArraySpecial(vector<int> &nums)
    {
        int current = nums[0];
        bool output = true;
        int next;
        for (int i = 1; i < nums.size(); i++)
        {
            next = nums[i];
            if (!parityChecker(current, next))
            {
                output = false;
            }
            current = next;
        }
        return output;
    }
};