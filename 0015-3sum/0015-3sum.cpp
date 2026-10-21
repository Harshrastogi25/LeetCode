class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target=-nums[i];
            unordered_map<int,int> map;
            for(int j=i+1;j<n;j++){
                int req=target-nums[j];
                if (map.find(req)!=map.end()){
                    ans.push_back({nums[i],nums[j],req});
                    while (j+1<n && nums[j]==nums[j+1]) j++;
                }
                map[nums[j]]=j;
            }
        }
        return ans;
    }
};