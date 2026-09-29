class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        for(int i = 0;i<n;i++){
            mp1[s[i]-'a']++;
            mp2[t[i]-'a']++;
        }
        bool check = true;
        for(int i = 0;i<26;i++){
            if(mp1[i]!=mp2[i]){
                check = false;
                return false;
            }
        }
        return true;
    }
};
