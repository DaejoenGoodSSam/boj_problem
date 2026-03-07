#include <iostream>
#include <limits.h>

#define MAX 10000
using namespace std;


int tree[MAX];

void print_array() {
  for(int i = 0; i < MAX; i++) {
    if (tree[i] <= 0)
      break;

    cout << tree[i] <<" ";
  }
  cout << endl;
}
void postorder (int start, int end) {
  for (int i = start + 1; i < end + 1; i++) {
    if (tree[i] > tree[start]) {
      postorder (start + 1, i - 1 )
    }
  }
}
int main () {
  int key;
  int idx = 0;

  while(std::cin >> key) {
    if (std::cin.fail())
      break;
    tree[idx] = key;

    idx++;
  }

  //print_array();

}
