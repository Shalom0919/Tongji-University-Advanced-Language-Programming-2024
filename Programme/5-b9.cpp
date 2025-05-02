/* 2452098 计算机 赵崇治 */
#include <iostream>
using namespace std;

bool isValidSudoku(int mat[10][10])
{
	for (int i = 1; i <= 9; i++) {
		bool used[10] = { false };
		for (int j = 1; j <= 9; j++) {
			if (used[mat[i][j]])
				return false;
			used[mat[i][j]] = true;
		}
	}

	for (int j = 1; j <= 9; j++) {
		bool used[10] = { false };
		for (int i = 1; i <= 9; i++) {
			if (used[mat[i][j]])
				return false;
			used[mat[i][j]] = true;
		}
	}

	for (int box_i = 0; box_i < 3; box_i++) {
		for (int box_j = 0; box_j < 3; box_j++) {
			bool used[10] = { false };
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int row = box_i * 3 + i + 1;
					int col = box_j * 3 + j + 1;
					if (used[mat[row][col]])
						return false;
					used[mat[row][col]] = true;
				}
			}
		}
	}
	return true;
}

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间\n";
	int mat[10][10] = { 0 };
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int num;
			while (true) {
				cin >> num;
				
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "输入错误，请重新输入第" << i << "行第" << j << "列的数字：";
					continue;
				}
				
				if (num < 1 || num > 9) {
					cout << "数字必须在1-9之间，请重新输入第" << i << "行第" << j << "列的数字：";
					continue;
				}
				
				mat[i][j] = num;
				break;
			}
		}
	}
	
	if (isValidSudoku(mat)) {
		cout << "是数独的解" << endl;
	} 
	else {
		cout << "不是数独的解" << endl;
	}
	
	return 0;
}