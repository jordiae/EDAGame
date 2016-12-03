#include <iostream>

using namespace std;

int main() {
	int victories = 0;
	int defeats = 0;
	int n;
	while (cin >> n) {
		if (n == 0)
			defeats++;
		else
			victories++;
	}
	cout << "Win rate over " << victories+defeats << " matches: " << 100*victories/(victories+defeats) << endl;;
}