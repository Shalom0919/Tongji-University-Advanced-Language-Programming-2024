/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ptrA = 0;
int ptrB = 0;
int ptrC = 0;
int a[11];
int b[11];
int c[11];
int steps = 0;

void init(int n, char from)
{
	printf("初始:               ");
	for (int i = 0; i < n; i++) {
		if (from == 'A') {
			a[i] = n - i;
			ptrA = n;
		}
		else if (from == 'B') {
			b[i] = n - i;
			ptrB = n;
		}
		else {
			c[i] = n - i;
			ptrC = n;
		}
	}

	printf(" A:");
	for (int i = 0; i < 10; i++) {
		if (a[i]) {
			printf("%2d", a[i]);
		}
		else printf("  ");
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (b[i]) {
			printf("%2d", b[i]);
		}
		else printf("  ");
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (c[i]) {
			printf("%2d", c[i]);
		}
		else printf("  ");
	}
	printf("\n");
}

void move(char from, char to) {
	int val;
	switch (from) {
		case('A'):
			val = a[ptrA - 1];
			a[--ptrA] = 0;
			if (to == 'B')
				b[ptrB++] = val;
			else
				c[ptrC++] = val;
			break;
		case('B'):
			val = b[ptrB - 1];
			b[--ptrB] = 0;
			if (to == 'A')
				a[ptrA++] = val;
			else
				c[ptrC++] = val;
			break;
		case('C'):
			val = c[ptrC - 1];
			c[--ptrC] = 0;
			if (to == 'A')
				a[ptrA++] = val;
			else
				b[ptrB++] = val;
			break;
	}
}

void outputDuring()
{
	printf(" A:");
	for (int i = 0; i < 10; i++) {
		if (a[i]) {
			printf("%2d", a[i]);
		}
		else printf("  ");
	}

	printf(" B:");
	for (int i = 0; i < 10; i++) {
		if (b[i]) {
			printf("%2d", b[i]);
		}
		else printf("  ");
	}

	printf(" C:");
	for (int i = 0; i < 10; i++) {
		if (c[i]) {
			printf("%2d", c[i]);
		}
		else printf("  ");
	}
	printf("\n");
}

void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		steps++;
		printf("第%4d 步(%2d): %c-->%c", steps, n, src, dst);
		move(src, dst);
		outputDuring();
		return;
	}

	hanoi(n - 1, src, dst, tmp);

	steps++;
	printf("第%4d 步(%2d): %c-->%c", steps, n, src, dst);
	move(src, dst); //死亡回放：此处传参瞎几把传导致错了，上面本来还多move了一次，还好发现每一次move应该和output一一对应(昏头了
	outputDuring();

	hanoi(n - 1, tmp, src, dst);
	return;
}

int main()
{
	int n, ret;
	char from, tmp, to;
	while (1) {
		printf("请输入汉诺塔的层数(1-10)\n");
		ret = scanf("%d", &n);
		if (ret != 1 || n > 10 || n < 1) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			while (getchar() != '\n')
				;
			break;
		}
	}

	while (1) {
		printf("请输入起始柱(A-C)\n");
		ret = scanf("%c", &from);
		if (ret != 1 || from - 'c' > 0 || from - 'A' < 0 || from - 'a' < 0 && from - 'C' > 0) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (from - 'a' >= 0)
				from -= 32;
			while (getchar() != '\n')
				;
			break;
		}
	}

	while (1) {
		printf("请输入目标柱(A-C)\n");
		ret = scanf("%c", &to);
		if (ret != 1 || to - 'c' > 0 || to - 'A' < 0 || to - 'a' < 0 && to - 'C' > 0) {
			while (getchar() != '\n')
				;
			continue;
		}
		else {
			if (to - 'a' >= 0)
				to -= 32;
			if (from == to) {
				printf("目标柱(%c)不能与起始柱(%c)相同\n", from, to);
				while (getchar() != '\n')
					;
				continue;
			}
			while (getchar() != '\n')
				;
			break;
		}
	}

	tmp = 'A' + 'B' + 'C' - to - from;
	init(n, from);
	hanoi(n, from, tmp, to);

	return 0;
}