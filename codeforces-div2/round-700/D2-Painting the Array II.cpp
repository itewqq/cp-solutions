#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

int arr[maxn],lst[maxn],pos[maxn],dp[maxn][3],cnt[maxn],top;
vector<pair<int,int> > a1,a2;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    cnt[top=1]=1;
    for(int i=2;i<=n;++i){
        if(arr[top]!=arr[i]){
            arr[++top]=arr[i];
            cnt[top]=1;
        }else{
            cnt[top]++;
        }
    }
    memset(pos,0x3f,sizeof(pos));
    for(int i=top;i>=1;--i){
        lst[i]=pos[arr[i]];
        pos[arr[i]]=i;
    }

    for(int i=1;i<=top;++i){
        if(!a1.empty() && (a1.rbegin()->second==arr[i])){
            a1.rbegin()->first=i;
        }else if(!a2.empty() && (a2.rbegin()->second==arr[i])){
            a2.rbegin()->first=i;
        }else if(a1.empty()){
            a1.push_back({i,arr[i]});
        }else if(a2.empty()){
            a2.push_back({i,arr[i]});
        }else{
            if(lst[a1.rbegin()->first]<lst[a2.rbegin()->first]){
                a2.push_back({i,arr[i]});
            }else{
                a1.push_back({i,arr[i]});
            }
        }
    }
    cout<<a1.size()+a2.size();
}
/*
 * 1 2 3 1 2
10
1 2 1 2 3 1 2 1 2 3
 1
 2 3
 1 3 1
 2 3

6
 1 2 3 1 3 2
4
 1 2 2 1
10
 1 1 2 2 3 2 2 3 2 2
 7
 2 2 3 2 2 3 3
*/
