#include <iostream>

using namespace std;

void chetninechetn(int* A, int n, int i, int j) {
	if (A[i] % 2 == 0 && j == 0) cout << A[i] << "  ";
	if (A[i] % 2 == 1 && j == 1) cout << A[i] << "  ";
	i++;
	if (i < n) chetninechetn(A, n, i, j);
	if (i == n && j == 0) {
		j++;
		cout << '\n';
		i = 0;
		chetninechetn(A, n, i, j);
	}
}


int main()
{
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	chetninechetn(A, n, 0, 0);
	return 0;
}