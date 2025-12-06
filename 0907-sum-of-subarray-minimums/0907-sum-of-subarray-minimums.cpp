/*class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mini = 0;
        int sum = 0;
        int n = arr.size();
        const int mod = (1e9 + 7);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                mini = min(mini,arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                temp.push_back(arr[i]);
                sum += arr[i];
                if(j >= i+1){
                    temp[i] = arr[i];
                    for(int k = i+1; k <= j; k++){
                        minimum = min(temp[k-1], arr[k]);
                    }
                    sum += minimum;
                    minimum = 0;
                }
                else if(j == n-1){
                    for(int k = 0; k < n; k++){
                        temp.erase(temp.begin());
                    }
                }
            }
        }
        return sum;
    }
};
*/

/*
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        const int mod = 1e9 + 7;
        
        for(int i = 0; i < n; i++){
            int mini = arr[i];   // reset for each subarray start
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        
        return sum;
    }
};

*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        vector<int> left(n), right(n);
        stack<int> st;
        
        // 1. Previous strictly smaller element (distance)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        
        // clear stack for reuse
        while (!st.empty()) st.pop();
        
        // 2. Next smaller OR equal element (distance)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        
        // 3. Sum contributions
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long ways = 1LL * left[i] * right[i];
            long long contrib = (ways % MOD) * arr[i] % MOD;
            ans = (ans + contrib) % MOD;
        }
        
        return (int)ans;
    }
};

