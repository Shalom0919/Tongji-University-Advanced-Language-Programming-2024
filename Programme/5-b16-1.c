/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char id[10][8];
	char name[10][9];
	int score[10];
	for(int i=0;i<10;i++){
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s %s %d", id[i], name[i], &score[i]);
	}
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			int id1 = 0, id2 = 0;
			for(int k=0;k<7;k++){
				id1 = id1*10 + id[i][k]-'0';
				id2 = id2*10 + id[j][k]-'0';
			}
			if (id1 < id2){
				char temp[8];
				strcpy(temp, id[i]);
				strcpy(id[i], id[j]);
				strcpy(id[j], temp);
				int temp1 = score[i];
				score[i] = score[j];
				score[j] = temp1;
				char temp2[9];
				strcpy(temp2, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp2);
			}
		}
	}
	printf("\n及格名单(学号降序):\n");
	for(int i=0;i<10;i++){
		if (score[i] >= 60)
			printf("%s %s %d\n", name[i], id[i], score[i]);
	}
	return 0;
}
