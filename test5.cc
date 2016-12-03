#include <iostream>
#include <vector>

using namespace std;


int rows() {
  return 4;
}

int cols() {
  return 7;
}


  void hola(EvalCell &evalCell) {
    evalCell.color = "aded";

  }
struct EvalCell {
    string unitOrWall = "empty";
    bool knighted = false;
    bool extra_haunted = false;
    string color = "None";
  } ;


  typedef vector< vector<EvalCell> > Matrix;
  Matrix M(rows(),vector<EvalCell>(cols()));


int main() {
  EvalCell evalCell = M[0][1];
 hola(evalCell);
 cout << evalCell.color;
}