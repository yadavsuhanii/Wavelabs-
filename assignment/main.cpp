#include<bits/stdc++.h>
using namespace std;

 int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int maxi=0;
        queue<int>q;
        vector<int>v(n, 0), v1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    int val=adj[i].size()+adj[j].size();
                    int chk=1;
                    for(auto it: adj[i]){
                        if(it==j){chk=-1; break;}
                    }
                    if(chk==-1){val--;}
                    maxi=max(maxi, val);
                }
            }
        }
        return maxi;
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > roads;
    for(int i=0;i<n;i++)
    {
        int a,b;
        vector<int> temp;
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        roads.push_back(temp);
        temp.clear();
    }
    int ans=maximalNetworkRank(n,roads);
    cout<<ans<<endl;
    return 0;
}