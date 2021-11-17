// problem link :- https://leetcode.com/problems/diagonal-traverse/
vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> mp(n-1+m-1+1); // size = max(i)+max(j) + 1 = (n-1) + (m-1) + 1
        // (i+j) is same for all elements on the same diagonal. (i-j) is also same. !!
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        mp[i+j].push_back(mat[i][j]);
        for(int i=0;i<mp.size();i++)
        {
            if(i%2==0)
            reverse(mp[i].begin(),mp[i].end());
            for(int j=0;j<mp[i].size();j++)
            ans.push_back(mp[i][j]);
        }
        return ans;
    }
