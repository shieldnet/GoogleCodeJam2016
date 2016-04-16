#include <iostream>
#include <fstream>
#include <cstring>

#define SIZE 50

int arr[SIZE][SIZE] = { 0, };
int input[SIZE][SIZE * 2 - 1] = { 0, };
int T = 0;
int N = 0;

void sort();
void make_base_row(int, int);
void make_base_col(int, int);

int calrow(int, int);
int calcol(int, int);

using namespace std;
// long long 을 사용할 것!
int main() {

	int row = 0, col = 0;
	int judge = 0;
	int found_row = -1;
	ifstream fin;
	ofstream fout;

	fin.open("B-small-attempt0.in");
	fout.open("result_large.out");
	fin >> T;

	while (T--) {

		fin >> N;
		//input
		for (row = 0; row < 2*N - 1; row++) {
			for (col = 0; col < N; col++) {

				fin >> input[row][col];

			}
		}
		//sort input
		sort();

		make_base_row(0, 0);
		make_base_col(0, 1);
		
		if (arr[0][N - 1] == input[2*(N - 1)][0]) {
			make_base_col(N - 1, 2*(N - 1));
			judge = 1;
		}
		else if (arr[N - 1][0] == input[2*(N - 1)][0]) {
			make_base_row(N - 1, 2*(N - 1));
			judge = 0;
		}

		//judge == 1 이면 ㅣㄱ 모양 judge == 0이면 ㄷ모양
		if (judge == 1) {

			for (row = 1; row < N; row++) {

				make_base_row(row,calrow(arr[row][0], arr[row][N - 1]));
				
			}

			

		}

		else if (judge == 0) {
			
			for (col = 1; col < N; col++) {

				make_base_col(col,calrow(arr[row][0], arr[row][N - 1]));

			}
		}


		cout << '1';


		//initialize
		memset(input, 0, sizeof(int) * SIZE * (2*SIZE - 1));
		memset(arr, 0, sizeof(int) * SIZE * (2 * SIZE - 1));
	}

	

	return 0;
}


void sort() {

	int x, y, z, w;
	int temp;

	for (x = 0; x < 2*N - 1; x++) {
		for (y = 0; y < 2*N - 1; y++) {
			if (input[x][0] < input[y][0]) {

				for (z = 0; z < N; z++) {
				
					temp = input[x][z];
					input[x][z] = input[y][z];
					input[y][z] = temp;
				
				}


			}
		}
	}

}

void make_base_row(int row,int input_row) {
	int col = 0;
	for (col = 0; col < N; col++) {
		arr[row][col] = input[input_row][col];
	}
}

void make_base_col(int col,int input_row){
	int row = 0;
	for (row = 0; row < N; row++) {
		arr[row][col] = input[input_row][row];
	}
}

int calrow(int first,int last) {

	int row = 0, col = 0;

	for (row = 0; row < 2*N - 1; row++) {
		if (input[row][0] == first && input[row][N - 1] == last) {
			return row;
		}
	}


}

int calcol(int first, int last) {

	int row = 0, col = 0;

	for (col = 0; col < 2 * N - 1; col++) {
		if (input[col][0] == first && input[col][N - 1] == last) {
			return col;
		}
	}

}
