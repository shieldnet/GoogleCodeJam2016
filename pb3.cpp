#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <fstream>
#include <cmath>

using namespace std;

//Declare Func.
void binaryString(int,string&);
bool isAllTrue(int);
bool isPrime(long long);
//Variable
string binary;
vector<bool> S;
vector<int> bin_code;
long long interpret[8] = { 0, };

int main() {
	//variable
	int T=1;
	int N = 0, J = 0;
	int number;
	int cnt = 0;
	int base, idx;
	long long input_num = 0;

	ifstream fin;
	ofstream fout;

	fin.open("test.in");
	fout.open("answer.out");

	fin >> T >> N >> J;

	//resize size of S
	S.resize(N);
	bin_code.resize(N);
	
	number = (int)(pow(2, N-1)) + 1;	//2^31 + 1

	while (!isAllTrue(number)) {
		//initialize S
		for (cnt = 0; cnt < S.size(); cnt++) {
				S[cnt] = false;
		}
		
		//binary code
		binaryString(number, binary);
		for (cnt = 0; cnt < binary.size(); cnt++) {
			if (binary[cnt] == '1') { bin_code[cnt] = 1; }
		}

		//each of them -> 2~8 based interpret
		for (base = 2; base < 8; base++) {
			for (idx = 0; idx < bin_code.size(); idx++) {

				input_num += (long long)(pow(base, idx) * bin_code[idx]);

			}
			
			interpret[base - 2] = input_num;
		}
		
		for (cnt = 0; cnt < 7; cnt++) {
			if (isPrime(interpret[cnt])) { break; }
		}


		number += 2;
		//initialization
		input_num = 0;

		
		
	}
	

	fin.close();
	fout.close();
	return 0;
}


void binaryString(int m_num,string& m_bin) {
	if (S.size() == 6) {
		m_bin = bitset<6>(m_num).to_string(); //to binary
	}
	if (S.size() == 16) {
		m_bin = bitset<16>(m_num).to_string(); //to binary
	}
	else if (S.size() == 32) {
		m_bin = bitset<32>(m_num).to_string(); //to binary
	}
}

bool isAllTrue(int m_num) {
	string bin;
	int cnt = 0;
	binaryString(m_num,bin);
	for (cnt = 0; cnt < S.size(); cnt++) {
		if (bin[cnt] == '1') {
			S[cnt] = true;
		}
	}

	if (all_of(S.begin(), S.end(), [](bool i) {return i; })) //if
	{
		return true;
	}
	return false;
}
// please use long long

bool isPrime(long long num) {
	int cnt;
	for (cnt = 2; cnt < (int)(pow(num, 0.5)); cnt++) {
		if (num%cnt == 0) {
			return false;
		}
	}
	return true;

}
