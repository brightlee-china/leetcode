class Solution {
public:
    bool isNumber(string s) {
        int state=0, flag=0; // flag to judge the special case "."
        while(s[0]==' ')  s.erase(0,1);//delete the  prefix whitespace 
        while(s[s.length()-1]==' ') s.erase(s.length()-1, 1);//delete the suffix whitespace
        for(int i=0; i<s.length(); i++){
            if('0'<=s[i] && s[i]<='9'){
                flag=1;
                if(state<=2) state=2;
                else state=(state<=5)?5:7;
            }
            else if('+'==s[i] || '-'==s[i]){
                if(state==0 || state==3) state++;
                else return false;
            }
            else if('.'==s[i]){
                if(state<=2) state=6;
                else return false;
            }
            else if('e'==s[i]){
                if(flag&&(state==2 || state==6 || state==7)) state=3;
                else return false;
            }
            else return false;
        }
        return (state==2 || state==5 || (flag&&state==6) || state==7);
        
    }
};