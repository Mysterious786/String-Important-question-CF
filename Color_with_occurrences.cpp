#define ll long long
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,ll>& p1,pair<string,ll>& p2){
    if(p1.first.size() == p2.first.size()) return p1<p2;
    else return p1.first.size() > p2.first.size();
}

void solve() {
  string t;
  cin>>t;
  ll n;
  cin>>n;
  vector<pair<string,ll>> v;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    v.push_back(make_pair(s,i));
  }
  sort(v.begin(),v.end(),cmp);
  vector<pair<ll,ll>> ans;
  ll start =0;
  ll prev = -1;
  while(start < t.size()){
    ll currS = start;
    ll tempS =-1,tempE = -1,tempIdx =-1;

  
    while(currS > prev){
        int size = t.size()-currS;
        for(int i=0;i<n;i++){
            if(v[i].first.size() > size) continue;
            string test = t.substr(currS,v[i].first.size());
            if(test == v[i].first){
                int idx = currS+v[i].first.size()-1;
                if(idx > tempE){
                    tempE = idx;
                    tempS = currS;
                    tempIdx = v[i].second;
                    break;
                }
            }


        }   currS--;


    }
    if(tempIdx == -1){
        cout<<-1<<endl;
        break;

    }
    else{
        ans.push_back(make_pair(tempIdx,tempS));
        prev = tempS;
        start = tempE +1;

    }

  }
  if(start==t.size()){
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
  }
}

int main() {
    ll test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
