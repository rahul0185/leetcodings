/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        for(int i=1; i<n; i++){
            while(!(asteroids[i] > -1) && asteroids[i-1] < -asteroids[i] ){
                asteroids.erase(asteroids.begin() + i-1);
            }
            if(asteroids[i] <= -1 && asteroids[i-1] > -asteroids[i]){
                asteroids.erase(asteroids.begin() + i);
            }
            
            else if(asteroids[i] <= -1 && asteroids[i-1] < -asteroids[i]){
                asteroids.erase(asteroids.begin() + i-1);
            }
           
            else if(asteroids[i] <= -1 && asteroids[i-1] == -asteroids[i]){
                asteroids.erase(asteroids.begin() + i);
                asteroids.erase(asteroids.begin() + i-1);
            }
            
            
            else {
                continue;
            }
        }
        return asteroids;
    }
};
*/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;   // acts like a stack

        for (int cur : asteroids) {

            bool destroyed = false;

            // collision happens only when st.back() is moving right (+)
            // and current asteroid is moving left (-)
            while (!st.empty() && st.back() > 0 && cur < 0) {

                if (abs(st.back()) < abs(cur)) {
                    // top asteroid is smaller → remove it
                    st.pop_back();
                } 
                else if (abs(st.back()) == abs(cur)) {
                    // both same → both destroyed
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                else {
                    // top asteroid is bigger → current is destroyed
                    destroyed = true;
                    break;
                }
            }

            // if current asteroid survived collision, push it
            if (!destroyed) {
                st.push_back(cur);
            }
        }

        return st;   // final state of asteroids
    }
};


