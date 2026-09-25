class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n=username.size();
        vector<tuple<int,string,string>> v;
        for(int i=0;i<n;i++) v.push_back({timestamp[i],username[i],website[i]});
        sort(v.begin(),v.end());
        unordered_map<string,vector<string>> users;
        for(auto it:v){
            users[get<1>(it)].push_back(get<2>(it));
        }
        map<vector<string>,int> freq;
        for(auto it:users){
            string user=it.first;
            vector<string> sites=it.second;
            int size=sites.size();
            set<vector<string>> seen;
            for(int i=0;i<size;i++){
                for(int j=i+1;j<size;j++){
                    for(int k=j+1;k<size;k++) seen.insert({sites[i],sites[j],sites[k]});
                }
            }
            for(auto it:seen) freq[it]++;
        }
        int ans=0;
        vector<string> arr;
        for(auto it:freq){
            if(it.second>ans){
                ans=it.second;
                arr=it.first;
            }
        }
        return arr;
    }
};