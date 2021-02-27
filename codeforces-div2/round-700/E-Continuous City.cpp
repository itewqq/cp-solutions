#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;

int g[100][100];
vector<int> vec;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int l,r,cntn=0,cntm=0,base=1;
    cin>>l>>r;
    if(l>1){
        g[1][2]=l-1;cntm++;
        base=2;
    }
    if(r==l){
        cout<<"YES\n"<<"2 1\n"<<"1 2 "<<l<<"\n";
        return 0;
    }else if(l+1==r){
        cout<<"YES\n"<<"3 2\n"<<"1 2 "<<l<<"\n"<<"2 3 1\n";
        return 0;
    }
    for(int diff=r-l;diff;diff>>=1){
        if(diff&1){
            vec.push_back(diff/2+1);
        }else{
            vec.push_back(diff/2);
        }
    }
    sort(vec.begin(),vec.end());
    int len=vec.size(),presum=0;
    cntn=len+1+base;
    g[base][cntn]=1;cntm++;
    for(int i=0;i<len;++i){
        int to=base+i+1;
        for(int j=(presum==vec[i]?0:-1);j<i;++j){
            int from=base+j+1;
            g[from][to]=vec[i];cntm++;
        }
        g[to][cntn]=1;cntm++;
        presum+=vec[i];
    }
    cout<<"YES\n"<<cntn<<" "<<cntm<<"\n";
    for(int i=1;i<cntn;++i){
        for(int j=i+1;j<=cntn;++j){
            if(g[i][j]){
                cout<<i<<" "<<j<<" "<<g[i][j]<<"\n";
            }
        }
    }
}
/*
1 5
 1 5
YES
4 6
1 2 1
1 3 2
1 4 1
2 3 2
2 4 1
3 4 1


1 6
YES
5 8
1 2 1
1 5 1
2 3 1
2 4 2
2 5 1
3 4 2
3 5 1
4 5 1

*/
