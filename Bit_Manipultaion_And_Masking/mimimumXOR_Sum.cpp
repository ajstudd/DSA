// assuming n = 14
2 ^ n = 16, 384 int minXOR(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;
    // 1<<n basically means 2^n
    for (int mask = 0; mask < (1 << n); mask++)
    {
        // nums2 will stay as it is.
        // but we need to shuffle elements of nums1
        // for each mask , there will be some on bits, so if the mask is 40, it will have binary: 11000
        // so since here number of bits which are on are 2
        // we will pick the elements at position where bits are on from nums1,
        // that will be index 3 and index 4.
        // now we need to check which bits in mask are 0 or OFF,
        // check one by one by turning them on.
        // and store the minimum XOR sum
        // we will get partial sum as we might be solving for 3 elements
        // but eventually we will get the actual sum
        int alreadyDonePartialXOR = __builtin_popcount(mask); //--> number of ON bits in mask
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + (nums2[i] ^ nums1[already]));
            }
        }
    }
    return dp[(1 << n) - 1];
}
