#include <iostream>
#include <vector>

using namespace std;

int rows() {
	return 5;
}

int cols() {
	return 9;
}
 typedef vector< vector<int> > Matrix;




  /**
   * Play method, invoked once per each round.
   */

 int main () {
    Matrix M(rows(),vector<int>(cols()));
    for (int i = 0; i < rows(); i++)
    	for (int j = 0; j < cols(); j++)
    		M[i][j] = i;

    for (int i = 0; i < rows(); i++) {
    	for (int j = 0; j < cols(); j++)
    		cout << M[i][j] << " ";
    	cout << endl;
    }



}