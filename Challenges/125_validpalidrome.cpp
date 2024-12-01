class Solution
{
public:
    bool isPalindrome(string s)
    {
        string temp = "";
        int size = s.length();
        // Convert to lowercase and remove non-alphanumeric characters
        for (int i = 0; i < size; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                temp.push_back(s[i] + 32); // Convert uppercase to lowercase
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                temp.push_back(s[i]); // Keep lowercase as is
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                temp.push_back(s[i]); // Keep digits as is
            }
        }

        // Check if the processed string is a palindrome
        int lastIndex = temp.size() - 1;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != temp[lastIndex])
            {
                return false;
            }
            lastIndex--;
        }
        return true;
    }
};

// LABEL: Optimised code
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1; // Initialize two pointers: one at the start and one at the end of the string.

        while (left < right)
        {
            // Move 'left' pointer forward until it points to an alphanumeric character.
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            // Move 'right' pointer backward until it points to an alphanumeric character.
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }

            // Compare the characters pointed to by 'left' and 'right' after converting them to lowercase.
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false; // If they don't match, it's not a palindrome.
            }

            // Move both pointers toward the center for the next comparison.
            left++;
            right--;
        }

        // If all characters match, the string is a palindrome.
        return true;
    }
};
