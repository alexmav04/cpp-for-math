#include <iostream>
using namespace std;

long turnPositive(long l) {
  long ans;
  ans = (l < 0) ? -l : l;
  return ans;
}

long gcd_1(long a, long b) {
  long answer;
  // if a and b are both zero, return error message
  if ((a == 0) && (b == 0)) {
    cerr << "It's not a valid input." << endl;
    return 0;
  }

  // check if a and b are both nonnegative
  a = turnPositive(a);
  b = turnPositive(b);

  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  for (long i = 1; i <= a; i++) {
    if ((a % i == 0) && (b % i == 0)) {
      answer = i;
    }
  }
  return answer;
}

// recursive
long gcd_rec(long a, long b) {
  long ansTemp;
  a = turnPositive(a);
  b = turnPositive(b);

  // if a and b are both zero, return error message
  if ((a == 0) && (b == 0)) {
    cerr << "It's not a valid input." << endl;
    return 0;
  }
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  ansTemp = a % b;

  return gcd_rec(b, ansTemp);
}

// iterative
long gcd_iter(long a, long b) {
  long a_tmp, b_tmp, tmp;
  a = turnPositive(a);
  b = turnPositive(b);

  // if a and b are both zero, return error message
  if ((a == 0) && (b == 0)) {
    cerr << "It's not a valid input." << endl;
    return 0;
  }

  // since gcd(a,b) = gcd(b,c) where c = a % b
  while (b != 0) {
    tmp = a % b;

    a = b;
    b = tmp;
  }
  return a;
}

int main(){
  long a, b;

  cout << "Enter number a: ";
  cin >> a;
  cout << "Enter number b: ";
  cin >> b;

  cout << gcd_1(a, b) << endl;
  cout << gcd_rec(a, b) << endl;
  cout << gcd_iter(a, b) << endl;
}