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
  if (start > end) {
    return;
  }
  int tmp = start + 1;
  for (int i = start + 1; i < end + 1; i++) {
    if (tree[i] > tree[start]) {
      tmp = i;
      break;
    }
  }
  // PostOrder Letf Child
  postorder (start + 1, tmp - 1 );
  // PostOrder Right Child
  postorder (tmp, end);
  // Print Root Node
  cout << tree[start] << endl;
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
  postorder (0, idx - 1);

  //print_array();

}
