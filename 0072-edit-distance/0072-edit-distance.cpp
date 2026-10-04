class Solution {
public:
    int m, n;
    int t[501][501];
    int solve(string &s1,string &s2, int m, int n){
        if(m==0 ||n==0){
            return m+n;
        }
        

        if(t[m][n]!=-1){
            return t[m][n];
        }

        if(s1[m-1]==s2[n-1]){
            return t[m][n]= solve(s1, s2, m-1, n-1);
        }
        else{
            int insertc=1+solve(s1, s2, m, n-1);
            int deletec=1+solve(s1, s2, m-1, n);
            int updatec=1+solve(s1, s2, m-1, n-1);
            return t[m][n]=min({insertc, deletec, updatec});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        m=s1.length();
        n=s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, m,n);
    }
};