#include <iostream>
#include <fstream>

using namespace std;
// long long 을 사용할 것!
// A=65, Z=90

int num[26] = {0,};
char ch[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //맨마지막 NULL

int sum();
bool isAllZero();
bool isLeftTwo();
bool isAbsoluteMajor();



int main() {
	int T = 0,N = 0;
	int cnt = 0;
	int casenum = 1;
	ifstream fin;
	ofstream fout;

	fin.open("A-large-practice.in");
	fout.open("result_large.out");

	//input T
	fin >> T;

	while (T--){
		//Input Data
		fin>>N;

		for(cnt=0;cnt<N;cnt++){

			fin>>num[cnt];

		}
		//Print Case#n : 
		fout<<"Case #"<<casenum<<": ";


		//Case 1 : N==2
		if(N==2){
			while(!isAllZero()){
					num[0]--;
					num[1]--;
					fout<<"AB ";
			}
		}
		//Case 2 : N>2
		else{
			while(!isAllZero()){
				if(isLeftTwo()){
					for(cnt=0;cnt<N;cnt++){//
						if(num[cnt]==0) continue;

						else{
							fout<<ch[cnt];
							num[cnt]--;
						}
					}//
					fout<<' ';
				}//endof if

				for(cnt = 0; cnt<N;cnt++){//
					if(num[cnt]==0) continue;

					
					num[cnt]--;
					if(isAbsoluteMajor()){
						num[cnt]++;
						continue;
					}
					fout<<ch[cnt]<<' ';
				}//




			}//endof while
		}//endof else
		casenum++;
		fout<<endl;
	}




	fin.close();
	fout.close();
	return 0;

}

int sum(){
	int cnt=0;
	int ret = 0;
	for(cnt=0;cnt<26;cnt++){
		ret += num[cnt];
	}

	return ret;
}

bool isLeftTwo(){

	int judge = 0;
	int cnt = 0;

	for(cnt = 0; cnt<26;cnt++){
		if(num[cnt]!=0){
			judge++;
		}
	}

	if(judge == 2) return true;
	else return false;
}

bool isAllZero(){
	int cnt = 0;

	for(cnt=0;cnt<26;cnt++){
		if(num[cnt]!=0){
			return false;
		}
	}
	return true;
}

bool isAbsoluteMajor(){
	
	int cnt = 0;
	if (sum() == 1){
		return true;
	}

	for (cnt = 0; cnt < 26; cnt++){
		if (((double)num[cnt] / sum()) > 0.5){
			return true;
		}
	}
	return false;
}
