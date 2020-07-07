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
	
	map<string,string>mp;

	string line,s,t;
	while(getline(cin,s) and s.size()){
		stringstream ss;
		ss << s;

		ss >> s;
		ss >> t;
		ss >> t;

		mp[t]=s;

		// cout<<s<<"\t"<<t<<endl;
	}

	while(cin>>s){
		cout<<(mp.count(s)?mp[s]:"eh")<<endl;
	}
    
 
	#ifndef ONLINE_JUDGE
	    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif
 
	return 0;
}
