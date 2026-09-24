class Solution {
public:
    int n;
    int t[1001][1001];
    bool isPred(string &prev, string &curr ){
        int M=prev.length();
        int N=curr.length();
        if(M>=N || N-M!=1){
            return false;
        }
        int i=0, j=0;
        while(i<M && j<N){
            if(prev[i]==curr[j])
              i++;
            j++;  
        }
        return i==M;
    }

    static bool myFunction(string & word1, string & word2){
        return word1.length()< word2.length();
    }
    int lis(vector<string> & words, int prev_idx, int curr_idx ){
        if(curr_idx==n)
          return 0;
   
    if(prev_idx!= -1 && t[prev_idx][curr_idx] != -1){
        return t[prev_idx][curr_idx];
    }
     int taken=0, not_taken=0;
     if(prev_idx ==-1 || isPred(words[prev_idx],words[curr_idx])){
         taken= 1+ lis(words, curr_idx, curr_idx+1);
     }
    not_taken=lis(words, prev_idx, curr_idx+1);
    if(prev_idx!= -1)
        t[prev_idx][curr_idx]=max(taken, not_taken);
    return max(taken, not_taken);
    
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words), end(words), myFunction);
        memset(t,-1, sizeof(t));
        return lis(words, -1, 0);
    }
};