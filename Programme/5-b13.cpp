/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	char board[11][27] = { ' ' };
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 50; i++)
	{
		int x = rand() % 10 + 1;
		int y = rand() % 26 + 1;
		if (board[x][y] == '*')
		{
			i--;
			continue;
		}
		board[x][y] = '*';
	}

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			if (board[i][j] != '*')
			{
				int count = 0;
				for (int k = -1; k <= 1; k++)
				{
					for (int l = -1; l <= 1; l++)
					{
						if (board[i + k][j + l] == '*')
						{
							count++;
						}
					}
				}
				board[i][j] = count + '0';
			}
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 27; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}