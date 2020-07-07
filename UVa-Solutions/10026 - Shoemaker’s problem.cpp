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
 		int n;
 		read(n);
 		vector<tuple<int,int,int>>lst;

 		for(int i=1,a,b; i<=n; ++i)
 			read(a,b), lst.push_back({a,b,i});

 		// sort(lst.begin(), lst.end(), [] ( const tuple<int,int,int>& a, const tuple<int,int,int>& b) -> bool{
 		// 		return (get<0>(a)*1.0 / get<1>(a) == get<0>(b)*1.0 / get<1>(b))? get<2>(a) < get<2>(b): get<0>(a)*1.0 / get<1>(a) < get<0>(b)*1.0 / get<1>(b);});
		
		sort(lst.begin(), lst.end(), [] ( auto a, auto b) -> bool{
				auto [a1,a2,a3] = a; auto [b1,b2,b3] = b;
				return a1*1.0/a2 == b1*1.0/b2? a3<b3 : a1*1.0/a2 < b1*1.0/b2;});


 	// 	for(auto [a,b,x]: lst)
		// 	cout<<x<<" ";
		// cout<<endl;	

		for(int i=0; i<n; ++i){
			auto [a,b,x] = lst[i];
			cout<<x<<" \n"[i==n-1];
		}  	

		cout<<(tc>1?"\n":"");	  	
 	}

    return 0;
}
