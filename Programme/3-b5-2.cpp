/* 2452098 计算机 赵崇治 */
#include <iostream>
using namespace std;

int main() {
    int year, month, day;
    int days = 0;

    cout << "请输入年，月，日\n";
    cin >> year >> month >> day;

    bool isLeapYear = false;
    bool isMonthValid = true;
    bool isDayValid = true;

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
        else {
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day < 1 || day > 30) {
                    isDayValid = false;
                }
            }
            else{
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
        }
    }

    if (!isMonthValid) {
        cout << "输入错误-月份不正确\n";
    }
    else if (!isDayValid) {
        cout << "输入错误-日与月的关系非法\n";
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

        cout << year << "-" << month << "-" << day << "是" << year << "年的第" << days << "天\n";
    }

    return 0;
}
