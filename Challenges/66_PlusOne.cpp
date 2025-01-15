class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = digits.size();
        int carry = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] + carry > 9)
            {
                digits[i] = (digits[i] + carry) - 10;
                carry = 1;
            }
            else
            {
                digits[i] += 1;
                carry = 0;
                break;
            }
        }
        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};