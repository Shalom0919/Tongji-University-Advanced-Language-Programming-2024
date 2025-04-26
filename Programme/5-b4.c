/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
		scanf("%d", &scores[i]);
		if (scores[i] < 0)
			break;
		bucket[scores[i]]++;
	}


	if (scores[0] < 0) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (i = 0; i < 1000; ++i) {
		if (scores[i] >= 0) {
			printf("%d ", scores[i]);
			if (i % 10 == 9) {
				printf("\n");
			}
		}
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");
	for (int i = 100; i >= 0; i--) {
		if (bucket[i] != 0) {
			printf("%d %d\n", i, bucket[i]);
		}
	}

	return 0;
}