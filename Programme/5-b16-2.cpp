/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string id[10];
	string name[10];
	int score[10];
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩\n";
		cin >> id[i] >> name[i] >> score[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (score[i] > score[j]) {
				int temp = score[i];
				score[i] = score[j];
				score[j] = temp;
				string tmp1=id[i];
				id[i] = id[j];
				id[j] = tmp1;
				string tmp2 = name[i];
				name[i] = name[j];
				name[j] = tmp2;
			}
		}
	}
	cout << "\n不及格名单(成绩升序):\n";
	for (int i = 0; i < 10; i++) {
		if (score[i] < 60) {
			cout << name[i] << " " << id[i] << " " << score[i] << endl;
		}
	}
}
