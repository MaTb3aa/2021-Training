int freq[30005];
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0 , rem = 0 , ans = 0;
        freq[0]=1;
        for(auto &t : nums){
            sum+=t;
            rem = ((sum % k) + k )%k;
            if(freq[rem])
                ans+=freq[rem];
            freq[rem]++;  
        }
        return ans;
    }
