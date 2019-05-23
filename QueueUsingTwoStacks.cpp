//Stack 두 개를 사용하여 Queue 구현. 시간복잡도는 O(n)
//해커랭크 https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//pop. top 명령이 있을때면 먼저 두번째 스택에 역순으로 값을 옮겨버림
void Move(stack<int> &front, stack<int> &rear) {
  if (front.empty()) {
    while (!rear.empty()) {
      front.push(rear.top());
      rear.pop();
    }
  }
}

int main() {
  stack<int> front, rear;

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t, val;
    cin >> t;
    switch (t) {
    case 1: //push
      cin >> val;
      rear.push(val);
      break;
    case 2: //pop
      Move(front, rear);
      front.pop();
      break;
    case 3: //top
      Move(front, rear);
      cout << front.top() << endl;
      break;
    }
  }
  return 0;
}
