class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        // Perform k operations
        for (int i = 0; i < k; ++i)
        {
            // Find the index of the maximum element
            int maxIndex = max_element(gifts.begin(), gifts.end()) - gifts.begin();
            // Update the maximum element with floor(sqrt(gifts[maxIndex]))
            gifts[maxIndex] = floor(sqrt(gifts[maxIndex]));
        }
        // Calculate the sum of the remaining gifts
        long long sumleft = 0;
        for (int gift : gifts)
        {
            sumleft += gift;
        }
        return sumleft;
    }
};
