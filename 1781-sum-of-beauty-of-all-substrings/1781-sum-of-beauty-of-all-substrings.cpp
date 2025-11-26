class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            vector <int> v(26,0);
            for(int j = i; j < n; j++){
                v[s[j] - 'a']++;
                int mx = 0,mn = 1000;
                for(int k = 0; k < 26; k++){
                    if(v[k] > 0){
                        mx = max(mx,v[k]);
                        mn = min(mn,v[k]);
                    }
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};