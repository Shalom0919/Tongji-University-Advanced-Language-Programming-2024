/* 2452098 计算机 赵崇治 */
#include<iostream>
using namespace std;

int main()
{
	int scores[1002];
	int bucket[101] = { 0 };
	int i = 0;

	for (int i = 0; i < 1000; i++) {
		scores[i] = -1;
	}

	printf("请输入成绩（最多1000个），负数结束输入\n");
	for (int i = 0; i < 1000; i++) {
		cin >> scores[i];
		if (scores[i] < 0)
			break;
		bucket[scores[i]]++;
	}

	if (scores[0] < 0) {
		cout << "无有效输入\n";
		return 0;
	}

	cout << "输入的数组为:\n";
	for (i = 0; i < 1000; ++i) {
		if (scores[i] >= 0) {
			cout << scores[i] << " ";
			if (i % 10 == 9) {
				cout << "\n";
			}
		}
	}
	cout << endl;

	static int ranks = 1;
	printf("分数与名次的对应关系为:\n");
	for (int i = 100; i >= 0; i--) {
		if (bucket[i] != 0) {
			for (int j = 0; j < bucket[i]; j++) {
				cout << i << " " << ranks << endl; //用桶排序呗，代码修改最小化了
			}
			ranks += bucket[i];
		}
	}

	return 0;
}