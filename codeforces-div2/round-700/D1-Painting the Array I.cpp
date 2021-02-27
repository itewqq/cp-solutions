#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

int arr[maxn],dp[maxn][3],cnt[maxn],top;
vector<int> a1,a2;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>arr[i];
    for(int i=1;i<=n;++i){
        if(i<n&&(a1.empty()||*a1.rbegin()!=arr[i])&&(a2.empty()||*a2.rbegin()!=arr[i])){
            if(!a1.empty()&&*a1.rbegin()==arr[i+1]){
                a1.push_back(arr[i]);
            }else{
                a2.push_back(arr[i]);
            }
        }
        else if(a1.empty()||*a1.rbegin()!=arr[i]){
            a1.push_back(arr[i]);
        }
        else if(a2.empty()||*a2.rbegin()!=arr[i]){
            a2.push_back(arr[i]);
        }
    }
    ans=max(ans,(int)a1.size()+(int)a2.size());
    cout<<ans;
}
/*
6
 3 3 1 2 3 3
4
 1 2 2 1
10
 1 1 2 2 3 2 2 3 2 2
 7
 2 2 3 2 2 3 3
*/
