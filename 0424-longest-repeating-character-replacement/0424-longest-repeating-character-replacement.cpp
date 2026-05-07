class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int>freq(26,0);
      int left=0;
      int ans=0;
      int maxfreq=0;  
      for(int right=0; right<s.size(); right++){
        freq[s[right]-'A']++;
        maxfreq=max(maxfreq,freq[s[right]-'A']);
        int ws=right-left+1;

        while(ws-maxfreq>k){
            freq[s[left]-'A']--;
            left++;
            ws=right-left+1;
        }
        ans=max(ans,ws);
      }
      return ans;
    }
};