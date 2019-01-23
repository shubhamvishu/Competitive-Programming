//https://www.hackerrank.com/challenges/prettyprint/copy-from/94452015

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    printf("0x%lx\n",(long)A);
    cout.setf(ios::showpos);
   // cout.fill('_');
    cout<<right<<setfill('_')<<setw(15)<<fixed<<setprecision(2)<<B<<endl;
    cout.unsetf(ios::showpos);
    cout<<scientific<<setprecision(9)<<C<<endl;

	}
	return 0;

}
