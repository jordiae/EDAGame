#include <iostream>

using namespace std;

double Sovereignv22, Sovereignv12, Sovereignv24, Sovereignv23;

void print_stats() {
	cout.setf(ios::fixed);
    cout.precision(2);
	int n = Sovereignv22+Sovereignv12+Sovereignv24+Sovereignv23;
	cout << "Win rate over " << n << " matches: " << endl;
	cout << "Sovereignv22: " << 100*Sovereignv22/n << "%" << endl;
	cout << "Sovereignv12: " << 100*Sovereignv12/n << "%" << endl;
	cout << "Sovereignv24: " << 100*Sovereignv24/n << "%" <<endl;
	cout << "Sovereignv23: " << 100*Sovereignv23/n << "%" <<endl;
}

int main() {

	string s;
	Sovereignv22 = 0; Sovereignv12=0; Sovereignv24=0; Sovereignv23=0;

	while (cin >> s) {
		if (s == "Sovereignv22") {
			Sovereignv22++;
			print_stats();
		}
		else if (s == "Sovereignv12") {
			Sovereignv12++;
			print_stats();
		}
		else if (s == "Sovereignv24") {
			Sovereignv24++;
			print_stats();
		}
		else if (s == "Sovereignv23") {
			Sovereignv23++;
			print_stats();
		}
	}
}
