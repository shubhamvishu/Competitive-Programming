//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, q, x;
  cin >> n;
  queue<int> q1;
  for (int i = 0; i < n; i++) {
    cin >> q;
    if (q == 1) {
      cin >> x;
      q1.push(x);
    } else if (q == 2)
      q1.pop();
    else
      cout << q1.front() << endl;
  }

  return 0;
}

