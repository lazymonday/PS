#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX_N 20000
using namespace std;

int N, X, Y, Z;
int A[MAX_N + 1], B[MAX_N + 1];

int main(void)
{
  freopen("milktemp/8.in", "r", stdin);
  cin >> N >> X >> Y >> Z;
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i];

  sort(A, A + N);
  sort(B, B + N);
  A[N] = 1000000001;
  B[N] = 1000000001;

  // scan through A and B simultaneously
  int i = 0, j = 0;
  int current_milk = N * X;
  int answer = N * X;
  while (i < N || j < N) {
    // look at A[i] and B[j].
    if (A[i] <= B[j]) {
      // next event comes from A array
      current_milk += Y - X;
      i++;
    } else {
      // next event comes from B array
      current_milk += Z - Y;
      j++;
    }
    if (current_milk > answer)
      answer = current_milk;
  }

  cout << answer << "\n";
  return 0;
}