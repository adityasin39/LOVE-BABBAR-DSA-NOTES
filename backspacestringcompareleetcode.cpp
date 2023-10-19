class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int cnt1=0;
        int cnt2=0;
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    cnt1++;
                    i--;
                }
                else if(cnt1>0)
                {
                    cnt1--;
                    i--;
                }
                else break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    cnt2++;
                    j--;
                }
                else if(cnt2>0)
                {
                    cnt2--;
                    j--;
                }
                else break;
            }
            if(i>=0 && j>=0 && s[i]!=t[j]) return false;
            if((i>=0)!=(j>=0)) return false;
            i--;
            j--;
        }
        return true;
    }
};