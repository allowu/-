/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string value = s;
            sort(s.begin(),s.end());
            mp[s].push_back(value);
        }
        vector<vector<string>>res;
        for(auto&p:mp){
            res.push_back(p.second);
        }
        return res;
    }
};