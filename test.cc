#include <iostream>
#include <map>

using namespace std;

int main() {
	int i = 0;
	map<int,int> m;
	m.insert(make_pair(0,0));
	m.insert(make_pair(1,0));
	m.insert(make_pair(2,1));
	int x;
	int aux;
	while (x != i) {
		aux = x;
		cout << x << endl;
		x = m[x];
	}
	cout << "aux: " << aux << endl;

}