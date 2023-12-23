class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        int x = 0, y = 0;
        string temp = to_string(x) + "+" + to_string(y);
        st.insert(temp);
        for (char it : path) {
            if (it == 'N')
                y++;
            else if (it == 'S')
                y--;
            else if (it == 'E')
                x++;
            else
                x--;

            temp = to_string(x) + "+" + to_string(y);
            if (st.find(temp) != st.end())
                return 1;
            st.insert(temp);
        }
        return 0;
    }
};
