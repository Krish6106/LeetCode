class Solution {
public:
    bool IsAlphanum(char ch){
        if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z')) {
            return true;
        }

        return false;
    }
    bool isPalindrome(string s) {
        int st = 0, end = s.length()-1;
        while(st<end){
            if(!IsAlphanum(s[st])){
                st++;
                continue;
            }
            if(!IsAlphanum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }
            st++,end--;
        }
        return true;
        
    }
};