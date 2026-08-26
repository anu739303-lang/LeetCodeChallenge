class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int count[100001] = {0};

        int l = 0;
        int ans = 0;
        int types = 0;

        for(int r = 0; r < fruits.size(); r++) {

            if(count[fruits[r]] == 0)
                types++;

            count[fruits[r]]++;

            while(types > 2) {

                count[fruits[l]]--;

                if(count[fruits[l]] == 0)
                    types--;

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};