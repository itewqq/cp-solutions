#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

bool done[64];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int len=s.length();
        memset(done,0,sizeof(done));
        for(int i=0;i<len;++i){
            for(int j=0;j<len;++j){
                if(!done[j]){
                    done[j]=true;
                    if(i&1){
                        s[j] = (s[j] == 'z' ? 'y' : 'z');
                    }else {
                        s[j] = (s[j] == 'a' ? 'b' : 'a');
                    }
                    break;
                }
            }
        }
        cout<<s<<"\n";
    }
}
