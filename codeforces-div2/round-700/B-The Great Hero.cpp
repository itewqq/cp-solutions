#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

long long a[maxn],b[maxn],loss[maxn],id[maxn];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,A,B,n;
    cin>>t;
    while(t--){
        cin>>A>>B>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){
            cin>>b[i];
        }
        ll sum=0;
        for(int i=1;i<=n;++i){
            id[i]=i;
            loss[i]=(b[i]+A-1)/A*a[i];
            sum+=loss[i];
        }
        sort(id+1,id+1+n,[](int i,int j){
            return a[i]<a[j];
        });
        if(sum-B<a[id[n]]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
