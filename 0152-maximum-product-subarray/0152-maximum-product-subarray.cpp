class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long curmax = nums[0];
        long long curmin = nums[0];
        long long maxprod = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long curr = nums[i];

            long long prevmax = curmax;
            long long prevmin = curmin;

            curmax = max({curr,
                          curr * prevmax,
                          curr * prevmin});

            curmin = min({curr,
                          curr * prevmax,
                          curr * prevmin});

            maxprod = max(maxprod, curmax);
        }

        return (int)maxprod;
    }
};