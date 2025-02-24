class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        string original = nums[0];
        for(int i = 0; i < n; i++){
            char ch = nums[0][i];
            if(ch == '0'){
                ch = '1';
            } else{
                ch = '0';
            }
            string mutated = original;
            mutated[i]=ch;
            if(mpp[mutated] == 0){
                return mutated;
            }
        }
        return "";
    }
};