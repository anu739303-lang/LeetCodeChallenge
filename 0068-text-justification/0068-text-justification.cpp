class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, len = 0;

            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                while (line.size() < maxWidth)
                    line += " ";
            } else {
                int spaces = (maxWidth - len) / gaps;
                int extra = (maxWidth - len) % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spaces + (extra-- > 0), ' ');
                }
                line += words[j - 1];
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};