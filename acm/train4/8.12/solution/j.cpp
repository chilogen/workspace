#include <bits/stdc++.h>

using namespace std;

typedef vector<int> lnum;
const int base = 1000*1000*1000;


int primes[] = {103127047,
				984466009,
				653452649,
				378452077,
				475201777,
				915279049,
				379146109,
				110954237,
				510750281,
				392857511,
				296005727,
				378297167,
				811592627,
				222398747,
				100812793,
				906533717,
				336385711,
				989985119,
				639420011,
				289273939};

void rlz(lnum &a){//remove leading zeros
	while ((int)a.size() > 1 && a.back() == 0)a.pop_back();
}

lnum read(string s){
	lnum a;
	for(int i=(int)s.length(); i>0; i-=9)
		if(i<9) a.push_back(atoi(s.substr (0, i).c_str()));
		else a.push_back(atoi(s.substr (i-9, 9).c_str()));	
	rlz(a);
	return a;
}


int divc(lnum a,int b){
	int carry = 0;
	for (int i=(int)a.size()-1; i>=0; --i) {
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int (cur / b);
		carry = int (cur % b);
	}
	rlz(a);
	return carry;
}

int fpow(int a, int b, int p){
	int c = 1;
	for (;b; b >>= 1 , a = a * 1ll * a % p) {
		if (b & 1) {
			c = c * 1ll * a % p;
		}
	}
	return c;

}

int main() {
	string s;
	cin >> s;
	lnum at = read(s);
	int a, b, p;
	int ok =  1;
	for (int i = 0; i < 20; ++i) {
		a = divc(at,primes[i]);
		b = (primes[i]-1)/2;
		p = primes[i];
		if (fpow(a, b, p) != 1) {
			ok = 0;
		}
	} 
	if (ok) puts("Yes");
	else puts("No");



}