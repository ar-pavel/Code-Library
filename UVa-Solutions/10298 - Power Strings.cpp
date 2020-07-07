#include "bits/stdc++.h"

using namespace std;
#define deb(x,y) cout << #x << " " << x << " " << #y << " " << y <<endl;
#define deb1(x) cout << #x << " " << x <<endl;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string s;
    while(cin>>s and s!="."){

    	int res(0);

    	for(int i=1; i*2<=s.size(); ++i){
    		if(s.size()%i) continue;
    		bool chk = true;
    		string pat = s.substr(0,i);
    		// deb1(pat);
    		for(int j=0; s[j] and chk; j+=i){
    			string subPat = s.substr(j,i);
    			// deb1(subPat);
    			if(subPat!=pat)
    				chk = false;
    		}
    		if(chk){
    			res=pat.size();
    			// deb1(pat);
    			break;
    		}
    	}
    	cout<<(res?s.size()/res:1)<<endl;
    }   	

    return 0;
}
