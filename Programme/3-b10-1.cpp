/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int cnt = 0;
	const int c = 1953;
	//189
	for (int a2 = 2; a2 <= 7; a2++) {
		for (int a3 = 2; a3 <= 7; a3++) {
			if (a3 == a2)
				continue;
			for (int a5 = 2; a5 <= 7; a5++) {
				if (a5 == a3 || a5 == a2)
					continue;
				for (int a6 = 2; a6 <= 7; a6++) {
					if (a6 == a5 || a6 == a3 || a6 == a2)
						continue;
					for (int a8 = 2; a8 <= 7; a8++) {
						if (a8 == a6 || a8 == a5 || a8 == a3 || a8 == a2)
							continue;
						for (int a9 = 2; a9 <= 7; a9++) {
							if (a9 == a8 || a9 == a6 || a9 == a5 || a9 == a3 || a9 == a2)
								continue;
							int sumshi = a2 + a5 + a8;
							int sumge = a3 + a6 + a9;
							if (sumshi * 10 + sumge == 153) {
								int n1 = 100, n2 = 800, n3 = 900;
								n1 += a2 * 10 + a3;
								n2 += a5 * 10 + a6;
								n3 += a8 * 10 + a9;
								cnt++;
								cout << "No." << setw(3) << right << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=" << c << endl;
							}
						}
					}
				}
			}
		}
	}
	//279
	for (int a2 = 1; a2 <= 8; a2++) {
		if (a2 == 2 || a2 == 7)
			continue;
		for (int a3 = 1; a3 <= 8; a3++) {
			if (a3 == 2 || a3 == 7 || a3 == a2)
				continue;
			for (int a5 = 1; a5 <= 8; a5++) {
				if (a5 == 2 || a5 == 7 || a5 == a3 || a5 == a2)
					continue;
				for (int a6 = 1; a6 <= 8; a6++) {
					if (a6 == 2 || a6 == 7 || a6 == a5 || a6 == a3 || a6 == a2)
						continue;
					for (int a8 = 1; a8 <= 8; a8++) {
						if (a8 == 2 || a8 == 7 || a8 == a6 || a8 == a5 || a8 == a3 || a8 == a2)
							continue;
						for (int a9 = 1; a9 <= 8; a9++) {
							if (a9 == 2 || a9 == 7 || a9 == a8 || a9 == a6 || a9 == a5 || a9 == a3 || a9 == a2)
								continue;
							int sumshi = a2 + a5 + a8;
							int sumge = a3 + a6 + a9;
							if (sumshi * 10 + sumge == 153) {
								int n1 = 200, n2 = 700, n3 = 900;
								n1 += a2 * 10 + a3;
								n2 += a5 * 10 + a6;
								n3 += a8 * 10 + a9;
								cnt++;
								cout << "No." << setw(3) << right << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=" << c << endl;
							}
						}
					}
				}
			}
		}
	}
	//3
	for (int a2 = 1; a2 <= 9; a2++) {
		if (a2 == 3)
			continue;
		for (int a3 = 1; a3 <= 9; a3++) {
			if (a3 == 3 || a3 == a2)
				continue;
			for (int a4 = 6; a4 <= 7; a4++) {
				if (a4 == a2 || a4 == a3)
					continue;
				for (int a5 = 1; a5 <= 9; a5++) {
					if (a5 == 3 || a5 == a4 || a5 == a3 || a5 == a2)
						continue;
					for (int a6 = 1; a6 <= 9; a6++) {
						if (a6 == 3 || a6 == a5 || a5 == a4 || a5 == a3 || a5 == a2)
							continue;
						for (int a7 = 8; a7 <= 9; a7++) {
							if (a7 ==  a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2)
								continue;
							for (int a8 = 1; a8 <= 9; a8++) {
								if (a8 == a7 || a8 == a6 || a8 == a5 || a8 == a4 || a8 == a3 || a8 == a2 || a8 == 3)
									continue;
								for (int a9 = 1; a9 <= 9; a9++) {
									if (a9 == a8 || a9 == a7 || a9 == a6 || a9 == a5 || a9 == a4 || a9 == a3 || a9 == a2 || a9 == 3)
										continue;
									int sumbai = a4 + a7;
									int sumshi = a2 + a5 + a8;
									int sumge = a3 + a6 + a9;
									if (sumshi * 10 + sumge + sumbai * 100 == 1653) {
										int n1 = 300, n2 = 0, n3 = 0;
										n1 += a2 * 10 + a3;
										n2 += a4 * 100 + a5 * 10 + a6;
										n3 += a7 * 100 + a8 * 10 + a9;
										cnt++;
										cout << "No." << setw(3) << right << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=" << c << endl;
									}
								}
							}
							
						}
					}
				}
			}
		}
	}
	//4
	for (int a2 = 1; a2 <= 9; a2++) {
		if (a2 == 4)
			continue;
		for (int a3 = 1; a3 <= 9; a3++) {
			if (a3 == 4 || a3 == a2)
				continue;
			for (int a4 = 5; a4 <= 6; a4++) {
				if (a4 == a2 || a4 == a3)
					continue;
				for (int a5 = 1; a5 <= 9; a5++) {
					if (a5 == 4 || a5 == a4 || a5 == a3 || a5 == a2)
						continue;
					for (int a6 = 1; a6 <= 9; a6++) {
						if (a6 == 4 || a6 == a5 || a5 == a4 || a5 == a3 || a5 == a2)
							continue;
						for (int a7 = 8; a7 <= 9; a7++) {
							if (a7 == a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2)
								continue;
							for (int a8 = 1; a8 <= 9; a8++) {
								if (a8 == a7 || a8 == a6 || a8 == a5 || a8 == a4 || a8 == a3 || a8 == a2 || a8 == 4)
									continue;
								for (int a9 = 1; a9 <= 9; a9++) {
									if (a9 == a8 || a9 == a7 || a9 == a6 || a9 == a5 || a9 == a4 || a9 == a3 || a9 == a2 || a9 == 4)
										continue;
									int sumbai = a4 + a7;
									int sumshi = a2 + a5 + a8;
									int sumge = a3 + a6 + a9;
									if (sumshi * 10 + sumge + sumbai * 100 == 1553) {
										int n1 = 400, n2 = 0, n3 = 0;
										n1 += a2 * 10 + a3;
										n2 += a4 * 100 + a5 * 10 + a6;
										n3 += a7 * 100 + a8 * 10 + a9;
										cnt++;
										cout << "No." << setw(3) << right << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=" << c << endl;
									}
								}
							}

						}
					}
				}
			}
		}
	}
	//567
	for (int a2 = 1; a2 <= 9; a2++) {
		if (a2 == 5 || a2 == 6 || a2 == 7)
			continue;
		for (int a3 = 1; a3 <= 9; a3++) {
			if (a3 == 5 || a3 == 6 || a3 == 7 || a3 == a2)
				continue;
			for (int a5 = 1; a5 <= 9; a5++) {
				if (a5 == 5 || a5 == 6 || a5 == 7 || a5 == a3 || a5 == a2)
					continue;
				for (int a6 = 1; a6 <= 9; a6++) {
					if (a6 == 5 || a6 == 6 || a6 == 7 || a6 == a5 || a6 == a3 || a6 == a2)
						continue;
					for (int a8 = 1; a8 <= 9; a8++) {
						if (a8 == 5 || a8 == 6 || a8 == 7 || a8 == a6 || a8 == a5 || a8 == a3 || a8 == a2)
							continue;
						for (int a9 = 1; a9 <= 9; a9++) {
							if (a9 == 5 || a9 == 6 || a9 == 7 || a9 == a8 || a9 == a6 || a9 == a5 || a9 == a3 || a9 == a2)
								continue;
							int sumshi = a2 + a5 + a8;
							int sumge = a3 + a6 + a9;
							if (sumshi * 10 + sumge == 153) {
								int n1 = 500, n2 = 600, n3 = 700;
								n1 += a2 * 10 + a3;
								n2 += a5 * 10 + a6;
								n3 += a8 * 10 + a9;
								cnt++;
								cout << "No." << setw(3) << right << cnt << " : " << n1 << "+" << n2 << "+" << n3 << "=" << c << endl;
							}
						}
					}
				}
			}
		}
	}

	cout << "total=" << cnt << endl; //掐表：2h30min
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}