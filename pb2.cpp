#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//wide variable
int T;
vector<bool> S;
char str[100] = { 0, };

//Declare Func.
int isAllSame();
void operate_in_range(int);
void char_to_bool();
int get_idx();

int main() {
	//Variable
	int cnt;
	int answer_cnt = 1;
	int maneuver_cnt = 0;
	int idx = 0;
	int n_T = 0;
	//To file input,output
	ifstream fin;
	ofstream fout;

	fin.open("B-large.in");
	fout.open("answer.out");

	//Get T
	fin >> T;
	n_T = T;
	
	if (T < 1 || T>100) { return 0; }

	while (n_T--) {

		fin >> str;

		char_to_bool();
		while (true) {
			if (isAllSame() == 10) {
				fout << "Case #" << answer_cnt << ": " << maneuver_cnt << endl;
				answer_cnt++;

				//initialize
				maneuver_cnt = 0;
				S.clear();
				break;
			}
			else if (isAllSame() == 20) {
				maneuver_cnt++;
				fout << "Case #" << answer_cnt << ": " << maneuver_cnt << endl;
				answer_cnt++;

				//initialize
				maneuver_cnt = 0;
				S.clear();

				break;
			}

			operate_in_range(get_idx());
			maneuver_cnt++;
		}
		for (cnt = 0; cnt < 100; cnt++) {
			str[cnt] = 0;
		}
	}

	fin.close();
	fout.close();

	return 0;
}


int isAllSame() {

	if (all_of(S.begin(), S.end(), [](bool i) {return i; })) //if
	{
		return 10;
	}
	else if (all_of(S.begin(), S.end(), [](bool i) {return !i; })) //if
	{
		return 20;
	}


}
void operate_in_range(int m_idx) {

	int cnt = 0;
		
	//change - -> +, + -> -
	for (cnt = 0; cnt < m_idx; cnt++) {
		if (S[cnt] == true) {
			S[cnt] = false;
		}
		else if (S[cnt] == false) {
			S[cnt] = true;
		}
	}

	//Reverse in Range
	for (cnt = 0; cnt < m_idx / 2; cnt++) {
		S[cnt] = S[(m_idx - cnt) - 1];
	}
	


}
void char_to_bool() {
	int cnt = 0;

	for (cnt = 0; cnt < sizeof(str); cnt++) {

		if (str[cnt] == '+') {
			S.push_back(true);
		}

		else if(str[cnt] == '-') {
			S.push_back(false);
		}
	}


}
int get_idx(){
	int cnt=0;

	for (cnt = 1; cnt < S.size(); cnt++) {
	
		if (S[cnt] != S[0]) {
			return cnt;
		}
	
	}
	cout << "FUCK::get_idX()error";
}


