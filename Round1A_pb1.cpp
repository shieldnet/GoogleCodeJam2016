#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;
// long long 을 사용할 것!
int main() {
	string bigger = "";
	string smaller = "";
	string str = "";
	string answer = "";

	int T = 0;
	int cnt = 0;
	int answer_num = 1;
	char first_letter = 0;
	char biggest = 0;
	ifstream fin;
	ofstream fout;

	fin.open("A-large.in");
	fout.open("result_large.out");
	
	fin >> T;

	while (T--) {
		
		fin >> str;
		
		answer += str[0];

		for (cnt = 1; cnt < str.length(); cnt++) {

			if (str[cnt] >= answer[0]) {
				answer = str[cnt] + answer;
			}
			else {
				answer = answer + str[cnt];
			}


		}
		



		
		fout << "Case #" << answer_num << ": " << answer << endl;
		
		str.clear();
		answer.clear();
		answer_num++;


	}



	return 0;
}
