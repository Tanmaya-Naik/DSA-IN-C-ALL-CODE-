#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t; cin >> t;
    int X, Y; cin >> X >> Y;

    auto toInt2 = [&](char a, char b){ return (a - '0') * 10 + (b - '0'); };
    int h0 = toInt2(t[0], t[1]), m0 = toInt2(t[3], t[4]);

    vector<int> mask = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
    unordered_map<int,int> rev; for (int i=0;i<10;++i) rev[mask[i]]=i;
    array<int,4> digs = {t[0]-'0', t[1]-'0', t[3]-'0', t[4]-'0'};

    auto valid=[&](int h,int m){ if(h==0)h=12; return 1<=h&&h<=12&&0<=m&&m<=59; };
    auto hs=[&](int a,int b){ a%=12; b%=12; int d=abs(a-b); return min(d,12-d); };
    auto ms=[&](int a,int b){ int d=abs(a-b); return min(d,60-d); };

    long long best=LLONG_MAX; int bh=-1,bm=-1;

    for(int p=0;p<4;++p){
        int cd=digs[p], cm=mask[cd];
        for(int s=0;s<7;++s){
            int f=cm^(1<<s);
            if(!rev.count(f)) continue;
            int nd=rev[f]; if(nd==cd) continue;
            auto ndigs=digs; ndigs[p]=nd;
            int HH=ndigs[0]*10+ndigs[1], MM=ndigs[2]*10+ndigs[3];
            if(!valid(HH,MM)) continue;
            int dh=hs(h0,HH==0?12:HH), dm=ms(m0,MM);
            long long cost=1LL*X*(dh*5)+1LL*Y*dm;
     if(cost<best||(cost==best&&make_pair(HH,MM)<make_pair(bh,bm))){
                best=cost; bh=HH; bm=MM;
            }
        }
    }

    if(best==LLONG_MAX) cout<<"No closest valid time possible\n";
    else cout<<setw(2)<<setfill('0')<<bh<<":"<<setw(2)<<setfill('0')<<bm<<"\n";
}