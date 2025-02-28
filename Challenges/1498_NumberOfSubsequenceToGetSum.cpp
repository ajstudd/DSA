class Solution {
    // execution
    // Modulo is there
    // nums = [3,5,6,7]
    // n = size = 4
    // sort : already sorted
    // vector of size n, that is 4
    // intiial vector[0] = 1, why power?? 
    // loop from 1 to n-1
    // filling power vector with previous power * 2 and modulo M, why?? 
    // power = [1,2,4,8]
    // taking left and right 
    // left = 0, r= n-1
    // l = 0, r=3
    // while loop till left does not cross right
        // if num on left index + right index <= target
        // find diff , why? 
        // diff = r-l;
        // cal result , prev result % M + power[difference index]%M
        // increasing left
        // l++
        // else
        // decrease r
        // r--
    // return result

public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        //1. Sort
        sort(begin(nums), end(nums));
        vector<int> power(n);
        power[0] = 1;
        
        //why power? 
        // each subsequence of size k will hold 2^k subsequence
        // for example 
        // [2,3,4]
        // <empty>
        // 2
        // 23
        // 24
        // 3
        // 34
        // 4
        // 234

        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }   
        
        //2. l = 0, r = n-1
        int l = 0, r = n-1;
        int result = 0;
        while(l <= r) {
            // when l=0, r=3
            // items in hand : 3, 7
            // reject
            // when l=0, r=2
            // items in hand : 3, 6
            // diff = 2
            // result = 0 + 4
            // why 4?
            // logic : 2^(r-l)
            // because each element has option to be in subsequence or not
            // we already found the minimum and maximum valid element,
            // now we can use combination of letter between to form valid subsequence
            // l = 1 , r=2
            // items in hand : 5, 6
            // reject
            // l=1, r=1
            // items in hand : 5,5
            // reject

            if(nums[l] + nums[r] <= target) {
                int diff = r-l;
                result = (result % M + power[diff]) % M;
                l++;
            } else {
                r--;
            }
            
        }
        
        return result;
    }
};