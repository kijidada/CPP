/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

vector<string> split(string s, char del) {
	stringstream ss(s);
	string item;
	vector<string> result;
	while (getline(ss, item, del)) {
		result.push_back(item);
	}
	return result;
}

int main4() {
	int num;
	char ws;
	cin >> num;										// Reading input from STDIN
	ws = cin.get();
	//cout << "Input number is " << num << endl;		// Writing output to STDOUT
	vector<int> foodStack(num, -1);
	int q, flag = 0;
	for (int i = 0; i < num; i++) {
		string S;
		getline(cin, S);

		//cout<< "Input: "<< S << endl;
		//stringstream X(S);
		vector<string> a = split(S, ' ');
		//while(){
		q = stoi(a[0]);
		/*if(flag == 1){
			foodStack.push_back(q);
			continue;
		}*/
		if (q == 1)
		{
			flag = 0;
			int res = foodStack.back();
			foodStack.pop_back();
			if (res == -1) {
				cout << "No Food" << endl;
			}
			else {
				cout << res << endl;
			}

		}
		else if (q == 2)
		{
			//flag = 1;
			foodStack.push_back(stoi(a[1]));
		}
		//}
	}
}
