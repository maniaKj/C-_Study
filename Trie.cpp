//Trie : 노드에서 자식 노드로 이동할 때  이동 경로 자체가 값이 된는 자료구조
//해커랭크 문제 : https://www.hackerrank.com/challenges/maximum-xor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
void printBit(int n) {
    if(n ==0) {
        cout << '0' << endl;
        return;
    }
  string str = "";
  while (n > 0) {
    str += '0' + n % 2;
    n = n >> 1;
  }
  for (auto iter = str.rbegin(); iter != str.rend(); iter++) {
    cout << *iter;
  }
  cout << endl;
}

int p;
struct node {
  int val;
  node *child[2] = {nullptr, nullptr};
};

void insert(node *trie, int x, int ind) {
  if (ind < 0) {
    return;
  }
  int k = (x >> ind) & 1;

  if (trie->child[k] == nullptr) {
    trie->child[k] = new node;
  }
  insert(trie->child[k], x, ind - 1);
}

void dfs(node *trie, int ind, string str) {
  if (ind < 0) {
    cout << str << endl;
    return;
  }

  if (trie->child[0] != nullptr)
    dfs(trie->child[0], ind - 1, str + '0');
  if (trie->child[1] != nullptr)
    dfs(trie->child[1], ind - 1, str + '1');
}

void find(node *trie, int x, int ind) {
  if (ind < 0) {
    return;
  }

  int k = (x >> ind) % 2;
  k ^= 1;

  if (trie->child[k] == nullptr) {
    k ^= 1;

  } 
  
  p = p << 1 | k; //요거 이해하는데 한참 걸림. 왼쪽시프트 1번 하고 1 더하겠다는 뜻.
  //p += k;
  //printBit(p);
  find(trie->child[k], x, ind - 1);
}

int main() {
  int n, i, x;
  cin >> n;
  vector<int> tt;
  vector<int> a(n);
  for (i = 0; i < n; ++i) {
    cin >> a[i];
  }

  node *trie = new node;
  for (i = 0; i < n; ++i) {
    // max 32 bits
    insert(trie, a[i], 31);
  }

  //dfs(trie, 31, "");

  int t;
  cin >> t;
  while (t--) {
    cin >> x;
    tt.push_back(x);
  }

  for (auto tmp : tt) {
    p = 0;
    find(trie, tmp, 31);
    cout << (p ^ tmp)  << endl;
    //printBit(tmp); printBit(p);
    
    
  }

  return 0;
}
