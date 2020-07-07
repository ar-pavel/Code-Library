#include "bits/stdc++.h"
 
using namespace std;
 
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
 
template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}

#define deb(x) cerr << #x << " " << x <<endl;

#define debs(args ...) cerr << __LINE__ << ": ", err(new istringstream(string(#args)), args), cerr << '\n'
void err(istringstream *iss) {}
template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) {
    string _name;
    *iss >> _name;
    if (_name.back()==',') _name.pop_back();
    cerr << _name << " = " << _val << "; ", err(iss, args ...);
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int tc,t(1);
	for(cin>>tc; tc; ++t,--tc){
		int a,b,c,d;
		cin>>a>>b>>c>>d;

		debs(a, b, c, d);

		auto chk = [] (int a, int b, int c, int d) -> bool{long long sum=a+b+c+d; return !a or !b or !c or !d or sum-a<=a or sum-b<=b or sum-c<=c or sum-d<=d;};

		cout<<((a==b and b==c and c==d)?"square":((a==c and b==d) or (a==b and c==d) or (a==d and c==b))?"rectangle" :!chk(a,b,c,d)?"quadrangle":"banana")<<endl;


	}

    return 0;
}

