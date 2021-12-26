//https://leetcode.com/problems/longest-duplicate-substring/

#define ULL unsigned long long

class Solution {
public:
    int check(const string &s, int len, ULL power) {
        unordered_set<ULL> seen;
        int n = s.length();

        ULL hash = 0;
        for (int i = 0; i < len; i++)
            hash = hash * 131 + s[i];

        seen.insert(hash);

        for (int i = len; i < n; i++) {
            hash = hash - power * s[i - len];
            hash = hash * 131 + s[i];
            if (seen.find(hash) != seen.end())
                return i - len + 1;

            seen.insert(hash);
        }

        return -1;
    }

    string longestDupSubstring(string S) {
        int n = S.length();
        int l = 0, r = n - 1;

        vector<ULL> power(n, 1);
        for (int i = 1; i < n; i++){
            power[i] = power[i - 1] * 131;
        }
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(S, mid + 1, power[mid]) == -1)
                r = mid;
            else
                l = mid + 1;
        }

        if (l == 0)
            return "";

        return S.substr(check(S, l, power[l - 1]), l);
    }
};
