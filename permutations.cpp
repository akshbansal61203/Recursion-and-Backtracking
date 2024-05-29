class Solution {
public:
    void f(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            ds.push_back(nums[ind]);
            f(ind+1,ds,ans,nums);
            swap(nums[i],nums[ind]);
            ds.pop_back();
        }
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        //vector<int>freq(n,0);
        f(0,ds,ans,nums);
        return ans;
    }
};
