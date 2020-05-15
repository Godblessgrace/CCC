#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int opt[2][2] = {1, 2, 3, 4};

	/*
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			printf("%d ", opt[row][col]);
		}
		printf("\n");
	}
	*/

 	string str;

 	getline(cin, str);
 	cout<<str<<endl;

 	int horizontal = 0, vertical = 0;
 	for (int i = 0; i < str.length(); i++) {
 		if (str[i] == 'H') {
 			horizontal++;
 		}
 		if (str[i] == 'V') {
 			vertical++;
 		}
 	}
 	horizontal %= 2; vertical %= 2;

 	if (horizontal == 1) {
 		swap(opt[0][0], opt[1][0]);
 		swap(opt[0][1], opt[1][1]);
 	}

 	if (vertical == 1) {
 		swap(opt[0][0], opt[0][1]);
 		swap(opt[1][0], opt[1][1]);
 	}

 	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			printf("%d ", opt[row][col]);
		}
		printf("\n");
	}
	return 0;
}
