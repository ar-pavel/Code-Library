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
const double r = 6378;
const double pi = 3.141592653589793;


 
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
 
	map<string,pair<double,double>>mp;
	string s,t; double a,b;
	while(cin>>s and s!="#"){
		cin>>a>>b;
		mp[s]={b,a};
	} 
	auto degToRad = [] (double x) -> double{ double pi=3.141592653589793; return x*pi/180.0; };

	auto distance = [] (double lng1, double lat1, double lng2, double lat2) -> double{
		double r = 6378;
		double dlon = lng2 - lng1; 
		double dlat = lat2 - lat1; 
	 	double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2); 
	 	double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
	 	double d = r * c; 
	 	return floor(d+0.5);
	};

	while(cin>>s>>t and (s!="#" or t!="#")){
		if(!mp.count(s) or !mp.count(t)){
			cout<<s<<" - "<<t<<endl<<"Unknown"<<endl;
			continue;
		}
		// cout<<s<<" - "<<t<<endl<<distance(degToRad(mp[s].first),degToRad(mp[s].second),degToRad(mp[t].first),degToRad(mp[t].second))<<" km"<<endl;
		cout<<s<<" - "<<t<<endl<<distance(mp[s].first*pi/180,mp[s].second*pi/180,mp[t].first*pi/180,mp[t].second*pi/180)<<" km"<<endl;
	}


	
    return 0;
}
