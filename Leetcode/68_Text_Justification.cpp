#include <vector>
#include <string>

// REMARK: This was my own code, fixed by gemini

using namespace std;

class Solution
{
private:
    /**
     * @brief Formats a line to be left-justified.
     * This is used for the VERY LAST line or any line with only ONE word.
     */
    string createLeftJustifiedLine(const vector<string> &words, int currentLineLength, int maxWidth)
    {
        string line = "";
        for (int i = 0; i < words.size(); ++i)
        {
            line += words[i];
            // Only add a single space if it's not the last word
            if (i < words.size() - 1)
            {
                line += " ";
            }
        }

        // Add all remaining spaces as padding to the end
        int padding = maxWidth - line.length();
        line += string(padding, ' ');
        return line;
    }

    /**
     * @brief Formats a line to be fully-justified.
     * This is used for all lines EXCEPT the last one.
     */
    string createFullJustifiedLine(const vector<string> &words, int currentLineLength, int maxWidth)
    {
        int numWords = words.size();

        // --- Scenario 2: Single-word line ---
        // This is a special case of full-justification, treated as left-justified.
        if (numWords == 1)
        {
            return createLeftJustifiedLine(words, currentLineLength, maxWidth);
        }

        // --- Scenario 3: Normal, multi-word line ---
        int totalSpaces = maxWidth - currentLineLength;
        int numGaps = numWords - 1; // Gaps are between words

        // Calculate base spaces for each gap and extra spaces to distribute
        int baseSpaces = totalSpaces / numGaps;
        int extraSpaces = totalSpaces % numGaps;

        string line = words[0]; // Start with the first word

        // Loop from the second word to add gaps and words
        for (int i = 1; i < numWords; ++i)
        {
            // Add the minimum (base) number of spaces
            line += string(baseSpaces, ' ');

            // Distribute the extra spaces, one per gap, from the left
            if (extraSpaces > 0)
            {
                line += " ";
                extraSpaces--;
            }

            // Add the next word
            line += words[i];
        }
        return line;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        vector<string> currentLineWords;
        int currentLineLength = 0; // Tracks the length of *words only*

        for (const string &word : words)
        {
            // --- This is the corrected packing logic ---
            // Check if the new word *CAN'T* fit.
            // The length check is:
            // (current words length) + (new word length) + (minimum 1-space gaps)
            // currentLineWords.size() IS the number of minimum gaps needed.

            if (currentLineLength + word.length() + currentLineWords.size() > maxWidth)
            {
                // The line is full. Format it and add to the result.
                result.push_back(createFullJustifiedLine(currentLineWords, currentLineLength, maxWidth));

                // Clear and start a new line with the current word
                currentLineWords.clear();
                currentLineLength = 0;
            }

            // Add the current word to the line being built
            currentLineWords.push_back(word);
            currentLineLength += word.length();
        }

        // --- Handle the VERY LAST line ---
        // After the loop, currentLineWords holds the last line, which
        // must be left-justified.
        if (!currentLineWords.empty())
        {
            result.push_back(createLeftJustifiedLine(currentLineWords, currentLineLength, maxWidth));
        }

        return result;
    }
};