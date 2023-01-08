int maxPoints(vector<vector<int>>& v) {
        int ans=0,n=v.size();
        
        for(int i=0;i<n;i++){
            
            int overlap =1, vertical = 1 ,curmx=0;
            map<pair<int,int>,int>mp;
            
            for(int j=i+1;j<n;j++){
                if(v[i]==v[j])overlap++;
                else if(v[i][0]==v[j][0])vertical++;
                else {
                    int yDif = v[j][1] - v[i][1];
                    int xDif = v[j][0] - v[i][0];
                    int g = __gcd(xDif, yDif);
                    yDif /= g;
                    xDif /= g;
                    mp[make_pair(yDif, xDif)]++;
                    curmx = max(curmx, mp[make_pair(yDif, xDif)]);
                }
            }
            ans=max(vertical,max(curmx+overlap,ans));
        }
        return ans;
    }
