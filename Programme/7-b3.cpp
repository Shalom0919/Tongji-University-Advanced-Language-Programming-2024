/* 2452098 计算机 赵崇治 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */    
public:
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
    Days(int y, int m, int d) :year(y), month(m), day(d)
    {
    };
};

/* --- 此处给出类成员函数的体外实现 --- */
int Days::calc_days()
{
    bool isLeapYear = false;
    bool isMonthValid = true;
    bool isDayValid = true;
    int days = 0;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = true;
    }

    if (month < 1 || month > 12) {
        isMonthValid = false;
    }

    if (isMonthValid) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day < 1 || day > 31) {
                isDayValid = false;
            }
        }
        else
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day < 1 || day > 30) {
                    isDayValid = false;
                }
            }
            else
                if (month == 2) {
                    if (isLeapYear) {
                        if (day < 1 || day > 29) {
                            isDayValid = false;
                        }
                    }
                    else {
                        if (day < 1 || day > 28) {
                            isDayValid = false;
                        }
                    }
                }
    }

    if (!isMonthValid) {
        return -2;
    }
    else if (!isDayValid) {
        return -1;
    }
    else {
        if (month == 1) {
            days = day;
        }
        else if (month == 2) {
            days = 31 + day;
        }
        else if (month == 3) {
            if (isLeapYear) {
                days = 31 + 29 + day;
            }
            else {
                days = 31 + 28 + day;
            }
        }
        else if (month == 4) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + day;
            }
            else {
                days = 31 + 28 + 31 + day;
            }
        }
        else if (month == 5) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + day;
            }
        }
        else if (month == 6) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + day;
            }
        }
        else if (month == 7) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + day;
            }
        }
        else if (month == 8) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
            }
        }
        else if (month == 9) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
            }
        }
        else if (month == 10) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
            }
        }
        else if (month == 11) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
            }
        }
        else if (month == 12) {
            if (isLeapYear) {
                days = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
            }
            else {
                days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
            }
        }

    }

    return days;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
    if (1) {
        Days d1(2024, 3, 18);
        cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
    }

    if (1) {
        Days d1(2023, 3, 18);
        cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
    }

    if (1) {
        Days d1(2024, 12, 31);
        cout << "应该输出366，实际是：" << d1.calc_days() << endl;
    }

    if (1) {
        Days d1(2023, 12, 31);
        cout << "应该输出365，实际是：" << d1.calc_days() << endl;
    }

    if (1) {
        Days d1(2024, 2, 29);
        cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
    }

    if (1) {
        Days d1(2023, 2, 29);
        cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
    }

    return 0;
}