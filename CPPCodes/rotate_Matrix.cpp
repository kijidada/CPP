
#include <iostream>
#include<vector>
#include<string>
#include<chrono>
using namespace std;

void rotate(vector<vector<int> >& A) {
	int n = A.size();
	int i = n - 2, j = 0, k1 = -1, k2 = -1;
	for (int m = 0; m < n; m++) {
		for (int k = 0; k < n/2; k++) {
			int temp = A[m][k];
			A[m][k] = A[m][n -k - 1];
			A[m][n-k - 1] = temp;
		}
	}
	while (i >= 0 && j <= n - 2) {
		k1 = i;
		k2 = j;
		int lim = ((n - (i + j)) / 2) + (((n - (i + j)) % 2) != 0);
		for (int m = 0; m < lim; m++) {
			int temp = A[k1][k2];
			A[k1][k2] = A[n - 1 - k2][n - 1 - k1];
			A[n - 1 - k2][n - 1 - k1] = temp;
			k1++;
			k2++;
		}
		if (i != 0) i--;
		else j++;
	}
}

void rotate_best(vector<vector<int> >& A) {
	int d = 0, n = A.size();
	while (d < n / 2)
	{
		cout << "d= " << d << endl ;
		cout << "n - d - 1 =" << n - d - 1 << endl << endl;
		for (int i = d; i < n - d - 1; i++)
		{
			cout << "i= " << i << endl; 
			cout << " A[d][i]= " << A[d][i] << " A[i][n - d - 1]= " << A[i][n - d - 1] << endl;
			cout << "A[n - i - 1][d]= " << A[n - i - 1][d] << " n - i - 1 =" << n - i - 1 << " A[n - d - 1][n - i - 1]= " << A[n - d - 1][n - i - 1] << endl << endl;
			
			swap(A[d][i], A[i][n - d - 1]);
			swap(A[d][i], A[n - i - 1][d]);
			swap(A[n - i - 1][d], A[n - d - 1][n - i - 1]);
		}
		d++;
	}
}


#pragma region Merge

void merge(vector<int>& A, vector<int>& B) {
	int sz1 = A.size();
	int sz2 = B.size();
	int i = 0, j = 0;
	while (A.size() < sz1 + sz2) {
		cout << " i: " << i << " j: " << j;
		auto itr = A.begin();
		if (A[i] > B[j]) {
			
		}
		else
		{
			while (i < A.size()) { if (A[i] < B[j])i++; else break; }
			
		}
		A.insert(itr + i, 1, B[j]);
		i += 2;
		j++;
		if (i > A.size() - 1) i = A.size() - 1;
	}
}

#pragma endregion

#pragma region sortcolor

void sortColors(vector<int>& A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int j = 0, k = 0; int i = 0;
	while ( i < A.size()) {
		if (A[i] == k) { i++; j++; continue; }
		while (j < A.size()) { if (A[j] == k) break; j++;}
		if (j == A.size()) {
			j = i;
			k++;
			if (k == 2) break; continue;
		}
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
	}

}

#pragma endregion

#pragma region max sum subarray

bool inRange(int t, int B, int C) {
	return (t >= B) && (t <= C);
}
int sumRange(vector<int>& A, int s, int e, vector<vector<int>>& mat) {
	int sum = 0;
	if (mat[s][e] != -1) return mat[s][e];
	int i = s;
	//if(mat[e][s] != -1 ) return mat[e][s];

	while (i <= e)
	{
		sum += A[i];
		i++;
		//if(!inRange(sum,B,C)) break;
	}
	mat[s][e] = sum;
	return sum;
}
int numRange(vector<int>& A, int B, int C) {
	//sort(A.begin(),A.end());
	int sz = A.size();
	if (sz == 1) { return inRange(A[0], B, C); };
	
	//std::vector<int> v(sz, -1);

	//std::vector<std::vector<int>> mat(sz, v);
	
	vector<int> temp(sz, -1);
	vector<vector<int>> mat(sz, temp);
	int l = 0, h = 0, sum = 0, cnt=0;
	while (l < sz) {
		h = l;
		while (h < sz) {
			sum = sumRange(A, l, h, mat);
			if (inRange(sum, B, C)) { cnt++; }
			//else break;
			h++;
		}
		l++;
	}
	return cnt;
}

#pragma endregion


int main() {
	#pragma region rotate
		/*
					const int n = 3, m = 3;
		vector < vector<int>> mat = { { 2, 1, 7,1 },
									  { 3, 7, 2, 2},
									  { 5, 4, 9, 3},
									  { 4, 5, 6, 7} };
		rotate_best(mat);*/
	#pragma endregion

	#pragma region merge
		/*vector<int > A = { -4, -3, 0 };
		vector<int > B = {3 };
		merge(A, B);*/
	#pragma endregion
	
	#pragma region sortcolors
		/*vector<int> A = { 2, 0, 0, 1, 0, 0, 2, 2, 1, 1, 0, 0, 1, 0, 2, 1, 1, 0, 1, 0, 1, 2, 2, 2, 0, 0, 1, 0, 2, 1, 1, 2, 1, 2, 2, 1, 0, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 2, 0, 2, 0, 1, 1, 0, 2, 2, 1, 2, 0, 2, 1, 1, 1, 2, 0, 1, 0, 2, 2, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 2, 1, 1, 0, 2, 1, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 2, 1, 2, 2, 2, 1, 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 1, 2, 0, 1, 0, 2, 2, 1, 2, 1, 0, 2, 2, 1, 1, 0, 2, 1, 2 };
		sortColors(A);*/

	#pragma endregion

	#pragma region Max sum subarray
	vector<int> A = { 80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90 };
	int B = 99, C = 269;
	int cnt = numRange(A, B, C);
	#pragma endregion


	return 0;
}