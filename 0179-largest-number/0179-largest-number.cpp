bool compare(int a, int b) {
    string x = to_string(a);
    string y = to_string(b);
    return ((x + y) > (y + x));
}
class Solution {
public:
    /*custom comparator => sort based on the concatenation of a+b or b+a
        "9"+"1" > "1"+"9"
    */
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) {
            return "0";
        }
        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};