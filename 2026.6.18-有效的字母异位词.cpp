/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& s:mp){
            res.push_back(s.second);
        }
        return res;
    }
};