#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {1,2,3,4};
  vec.push_back(5);
  vec.insert(--vec.end(), 1000);
  
  for (int i=0; i<vec.size(); i++) {
    cout << vec[i] << endl;  
  }
  cout << "------------" << endl;
  vec.erase(vec.end()-1);
  for (int i=0; i<vec.size(); i++) {
    cout << vec[i] << endl;  
  }
  cout << "------------" << endl;
  cout << "vec.capacity()=" << vec.capacity() << endl;
  return 0;
}
