class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        // Loop through both strings from the end to the start
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry; // Start with the carry

            if (i >= 0)
                sum += a[i--] - '0'; // Add digit from 'a' if available
            if (j >= 0)
                sum += b[j--] - '0'; // Add digit from 'b' if available

            result += (sum % 2) + '0'; // Append the current binary digit
            carry = sum / 2;           // Update the carry
        }

        reverse(result.begin(), result.end()); // Reverse the result to get the correct order
        return result;
    }
};
