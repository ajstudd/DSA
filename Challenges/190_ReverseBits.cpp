// Input: n = 00000010100101000001111010011100
// Output:    964176192 (00111001011110000010100101000000)
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t reversed = 0;

        for (int i = 0; i < 32; ++i)
        {
            // Shift the reversed value to the left by 1 position
            reversed <<= 1;
            // Add the least significant bit of 'n' to reversed
            reversed |= (n & 1);
            // Shift 'n' to the right by 1 to process the next bit
            n >>= 1;
        }

        return reversed;
    }
};
