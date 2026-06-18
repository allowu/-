/*给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。*/
//c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(char a:magazine){
            mp[a]++;
        }
        for(char b:ransomNote){
            mp[b]--;
            if(mp[b]<0){
                return false;
            }
        }
        return true;
    }
};
//c
bool canConstruct(char* ransomNote, char* magazine) {
    int len2=strlen(magazine),len1=strlen(ransomNote),arr[26]={0},i;
    for(i=0;i<len2;i++){
        arr[magazine[i]-'a']++;
    }
    for(i=0;i<len1;i++){
        arr[ransomNote[i]-'a']--;
        if(arr[ransomNote[i]-'a']<0){
            return false;
        }
    }
    return true;
}