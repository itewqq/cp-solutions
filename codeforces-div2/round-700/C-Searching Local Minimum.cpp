#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

int arr[maxn];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l,r,mid,n;
    cin>>n;
    l=1,r=n;
    arr[0]=arr[n+1]=1e9+7;
    if(n<=100){
        for(int i=1;i<=n;++i){
            cout<<"? "<<i<<endl;
            cin>>arr[i];
        }
        for(int i=1;i<=n;++i){
            if(arr[i-1]>arr[i]&&arr[i]<arr[i+1]){
                cout<<"! "<<i<<endl;
                return 0;
            }
        }
    }
    int cnt=100;
    while(l!=r){
        if(r-l<=cnt){
            for(int i=l;i<=r;++i){
                cout<<"? "<<i<<endl;
                cin>>arr[i];
            }
            for(int i=l;i<=r;++i){
                if(arr[i-1]>arr[i]&&arr[i]<arr[i+1]){
                    cout<<"! "<<i<<endl;
                    return 0;
                }
            }
        }
        mid=(l+r)>>1;
        cout<<"? "<<mid<<endl;--cnt;
        cin>>arr[mid];
        cout<<"? "<<mid+1<<endl;--cnt;
        cin>>arr[mid+1];
        if(arr[mid]>arr[mid+1]){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<"! "<<l<<endl;
}
/*

*/
