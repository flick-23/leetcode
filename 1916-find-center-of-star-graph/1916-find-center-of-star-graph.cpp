class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        cout<<n<<endl;
        vector<int>count(n+1,0);
        int ans = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            count[u]++;
            count[v]++;
        }
        for(int i = 1; i < count.size(); i++){
            if(count[i] == n-1){
                ans = i;
            }
        }
        return ans;
    }
};