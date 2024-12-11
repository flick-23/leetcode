class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,unordered_set<int>> hash;

        //Create a hash of X coordinates that have same Y
        for(auto point:points){
            int x = point[0];
            int y = point[1];
            hash[x].insert(y);
        }
        int minArea = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];   //point A 
                int x2 = points[j][0], y2 = points[j][1];   //point B 

                //If A and B are diagonal
                if(x1 != x2 && y1 != y2){
                    //Check if point C and point D exist. For this x1 should have y2 in it's list and x2 should have y1
                    if(hash[x1].find(y2) != hash[x1].end() && hash[x2].find(y1) != hash[x2].end()){
                        int l = abs(x2-x1);
                        int b = abs(y2-y1);
                        minArea = min(minArea, (l*b));
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};