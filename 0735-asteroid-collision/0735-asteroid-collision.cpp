class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {

            if (a < 0) {
                bool destroyed = false;

                while (!st.empty() && st.top() > 0 &&
                       st.top() <= abs(a)) {

                    if (st.top() == abs(a)) {
                        st.pop();
                        destroyed = true;
                        break;
                    }

                    st.pop();
                }

                if (!destroyed && (st.empty() || st.top() < 0)) {
                    st.push(a);
                }
            }
            else {
                st.push(a);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};