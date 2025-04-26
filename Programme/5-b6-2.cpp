/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
using namespace std;

int stk[3][11];
int ptr[3];
int steps = 0;

void init(int n, char from)
{
	cout << "初始:               ";
	for (int i = 0; i < n; i++) {
		int k = from - 'A';
		stk[k][i] = n - i;
		ptr[k] = n;
	}

	printf(" A:");
	for (int i = 0; i < 10; i++) {
		if (stk[0][i]) {
			cout << setw(2) << stk[0][i];
		}
		else cout << "  ";
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (stk[1][i]) {
			cout << setw(2) << stk[1][i];
		}
		else cout << "  ";
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (stk[2][i]) {
			cout << setw(2) << stk[2][i];
		}
		else cout << "  ";
	}
	cout << endl;
}

void move(char from, char to) {
	int k = from - 'A';
	int t = to - 'A';
	int val = stk[k][ptr[k] - 1];

	stk[k][--ptr[k]] = 0;
	stk[t][ptr[t]++] = val;
}

void outputDuring()
{
	printf(" A:");
	for (int i = 0; i < 10; i++) {
		if (stk[0][i]) {
			cout << setw(2) << stk[0][i];
		}
		else cout << "  ";
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (stk[1][i]) {
			cout << setw(2) << stk[1][i];
		}
		else cout << "  ";
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (stk[2][i]) {
			cout << setw(2) << stk[2][i];
		}
		else cout << "  ";
	}
	cout << endl;
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		steps++;
		cout << "第" << setw(4) << steps << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);//第%4d 步(%2d): %c-->%c
		outputDuring();
		return;
	}

	hanoi(n - 1, src, dst, tmp);

	steps++;
	cout << "第" << setw(4) << steps << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
	move(src, dst);
	outputDuring();

	hanoi(n - 1, tmp, src, dst);
	return;
}

int main()
{
	int n;
	char from, tmp, to;
	bool valid = false;
	while (!valid) {
		cout << "请输入汉诺塔的层数(1-10)\n";
		if (cin >> n) {
			if (n >= 1 && n <= 10) {
				valid = true;
			}
		}
		if (!valid) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "请输入起始柱(A-C)\n";
	while (cin >> from) {
		if (from - 'A' >= 0 && from - 'A' <= 2) {
			break;
		}
		else if (from - 'a' >= 0 && from - 'a' <= 2) {
			from = char(from - 32);
			break;
		}
		else {
			cout << "请输入起始柱(A-C)\n";
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "请输入目标柱(A-C)\n";
	while (cin >> to) {
		if (to - 'A' >= 0 && to != from && to - 'A' <= 2) {
			break;
		}
		else if (to - 'a' >= 0 && to - 'a' <= 2) {
			to = char(to - 32);
			if (to != from) {
				break;
			}
			else {
				cout << "目标柱(" << to << ")不能与起始柱(" << from << ")相同\n";
			}
		}
		else {
			if (to == from) {
				cout << "目标柱(" << to << ")不能与起始柱(" << from << ")相同\n";
			}
			cout << "请输入目标柱(A-C)\n";
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}

	tmp = 'A' + 'B' + 'C' - to - from;
	init(n, from);
	hanoi(n, from, tmp, to);

	return 0;
}