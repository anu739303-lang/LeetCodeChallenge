class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        int count1[26] = {0};
        int count2[26] = {0};

        for(int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for(int i = s1.size(); i < s2.size(); i++) {

            if(equal(count1, count1 + 26, count2))
                return true;

            count2[s2[i] - 'a']++;
            count2[s2[i - s1.size()] - 'a']--;
        }

        return equal(count1, count1 + 26, count2);
    }
};