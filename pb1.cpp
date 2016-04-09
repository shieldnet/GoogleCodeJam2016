#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//wide variable
int T;
long long N;
bool isNumout[10] = { false, };


//function
bool isAlltrue(bool*);
void split_and_input_num(long long);

int main() {
	//variable
	int cnt = 1;
	int answer_cnt = 1;

	ifstream fin;
	ofstream fout;

	fin.open("A-large.in");
	fout.open("answer.out");

	//input T
	fin >> T;
	if (T < 1 || T>100) { return 0; }

	while (T--) {
		//input N
		fin >> N;

		

		while (true) {
			
			if (N == 0) {
				fout << "Case #" << answer_cnt << ": " << "INSOMNIA" << endl;
				answer_cnt++;
				break;
			}
			

			split_and_input_num(cnt*N);
			if (isAlltrue(isNumout)) {
				fout << "Case #" << answer_cnt << ": " << cnt*N << endl;
				answer_cnt++;
				break;
			}
			
			

			cnt++;

		}
		cnt = 1;
		memset(isNumout, false, sizeof(isNumout));


	}

	fin.close();
	fout.close();

	return 0;
}

bool isAlltrue(bool* arr) {

	return (isNumout[0] && isNumout[1] && isNumout[2] && isNumout[3] && isNumout[4] && isNumout[5] &&
		isNumout[6] && isNumout[7] && isNumout[8] && isNumout[9] && isNumout);


}

void split_and_input_num(long long m_N) {


	long long remainder;
		
	while (m_N)
	{
		
		remainder = m_N % 10;

		m_N /= 10;
		
					
		isNumout[remainder] = true;
			
	}
}
