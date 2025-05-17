/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char id[10][8];
	char name[10][9];
	int score[10];
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s %s %d", id[i], name[i], &score[i]);
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (score[i] < score[j]) {
				int temp = score[i];
				score[i] = score[j];
				score[j] = temp;
				char temp1[8];
				strcpy(temp1, id[i]);
				strcpy(id[i], id[j]);
				strcpy(id[j], temp1);
				char temp2[9];
				strcpy(temp2, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp2);
			}
		}
	}

	printf("\n全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++) {
		printf("%s %s %d\n", name[i], id[i], score[i]);
	}
	return 0;
}
