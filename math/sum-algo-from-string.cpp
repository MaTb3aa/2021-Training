//https://leetcode.com/problems/basic-calculator/description/ 
long long ans = 0;
        int sign =1;
        stack<pair<long long ,int>>stk;
        for(int i=0;i<s.size();i++){
            char cur = s[i];
            if(isdigit(cur)){
                long long num = 0;
                while(i<s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                i--;
                ans += (sign*num);
                cout<<ans<<endl;
                sign = 1;
            }
            else if(cur=='('){
                stk.push({ans,sign});
                ans=0;
                sign=1;
            }
            else if(cur==')'){
                ans=stk.top().first + (ans*stk.top().second);
                stk.pop();
            }
            else if(cur=='-') {
                sign*=-1;
            }

        }
        

        return ans;
////////////////////////////////////////////////////////////////////////////

int solve(int &idx,string &s){
        long long ans = 0,num=0 ;
        int sign = 1;
        for(;idx<s.size();idx++){
            if(s[idx]==' ')continue;
            else if(s[idx]=='+'||s[idx]=='-'){
                ans += sign*num;
                num=0;
                sign=(s[idx]=='-') ? -1 : 1; 
            }
            else if(s[idx]=='(')ans += sign*solve(++idx,s);
            else if(s[idx]==')')break;
            else num = num*10+(s[idx]-'0');
        }
        return ans+(sign*num);
    }
    int calculate(string s) {
        int idx=0;
        return solve(idx,s);
    }
