/* 2452098 计算机 赵崇治 */
//2h 
#include <iostream>
#include <iomanip>
using namespace std;

/* 判断是否为闰年 */
bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* 获取某月的天数 */
int days_in_month(int year, int month)
{
    const int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap_year(year))
        return 29;
    return days[month];
}

/* 蔡勒公式计算某年某月1日是星期几 (0-星期日, 1-星期一, ..., 6-星期六) */
int day_of_week(int year, int month, int day = 1) 
{
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    int century = year / 100;
    year = year % 100;
    int week = (day + 26 * (month + 1) / 10 + year + year / 4 + century / 4 + 5 * century) % 7;
    return (week + 7 - 1) % 7;
}

/* 打印月历的标题行 */
void print_month_title(int year, int month)
{
    char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
    };
    cout << right << setw(15) << month_names[month] << " " << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
}

/* 打印单个月的月历 */
void print_month(int year, int month)
{
    print_month_title(year, month);

    int start_day = day_of_week(year, month);
    int days = days_in_month(year, month);

    // 打印前导空格
    for (int i = 0; i < start_day; i++)
        cout << "    ";

    // 打印日期
    for (int i = 1; i <= days; i++) {
        cout << left << setw(3) << i << " ";
        if ((i + start_day) % 7 == 0 || i == days)
            cout << endl;
    }

    // 确保月历至少有4行
    int rows = (days + start_day + 6) / 7;
    for (int i = rows; i < 4; i++)
        cout << endl;
}

/* 打印每行1个月的年历 */
void print_calendar_1(int year)
{
    for (int month = 1; month <= 12; month++) {
        print_month(year, month);
        cout << endl;
    }
}

/* 打印每行2个月的年历 */
void print_calendar_2(int year)
{
    for (int month = 1; month <= 12; month += 2) {
        // 打印月份标题
        char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
        };

        cout << setw(15) << month_names[month] << " " ;
        cout << setw(31) << month_names[month + 1] << " " << endl;

        cout << "Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat" << endl;

        // 获取两个月的信息
        int start_day1 = day_of_week(year, month);
        int days1 = days_in_month(year, month);
        int start_day2 = day_of_week(year, month + 1);
        int days2 = days_in_month(year, month + 1);

        // 计算行数
        int rows1 = (days1 + start_day1 + 6) / 7;
        int rows2 = (days2 + start_day2 + 6) / 7;
        int rows = max(rows1, rows2);
        rows = max(rows, 4); // 确保至少4行

        // 打印日期
        for (int i = 0; i < rows; i++) {
            // 第一个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day1;
                if (day > 0 && day <= days1)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第二个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day2;
                if (day > 0 && day <= days2)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << endl;
        }

        cout << endl;
    }
}

/* 打印每行3个月的年历 */
void print_calendar_3(int year)
{
    for (int month = 1; month <= 12; month += 3) {
        // 打印月份标题
        char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
        };

        cout << setw(15) << month_names[month] << " " ;
        cout << setw(31) << month_names[month + 1] << " " ;
        cout << setw(31) << month_names[month + 2] << " " << endl;

        cout << "Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat" << endl;

        // 获取三个月的信息
        int start_day1 = day_of_week(year, month);
        int days1 = days_in_month(year, month);
        int start_day2 = day_of_week(year, month + 1);
        int days2 = days_in_month(year, month + 1);
        int start_day3 = day_of_week(year, month + 2);
        int days3 = days_in_month(year, month + 2);

        // 计算行数
        int rows1 = (days1 + start_day1 + 6) / 7;
        int rows2 = (days2 + start_day2 + 6) / 7;
        int rows3 = (days3 + start_day3 + 6) / 7;
        int rows = max(max(rows1, rows2), rows3);
        rows = max(rows, 4); // 确保至少4行

        // 打印日期
        for (int i = 0; i < rows; i++) {
            // 第一个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day1;
                if (day > 0 && day <= days1)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << right << "    "; // 月份之间的间隔

            // 第二个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day2;
                if (day > 0 && day <= days2)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << right << "    "; // 月份之间的间隔

            // 第三个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day3;
                if (day > 0 && day <= days3)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << endl;
        }

        cout << endl;
    }
}

/* 打印每行4个月的年历 */
void print_calendar_4(int year)
{
    for (int month = 1; month <= 12; month += 4) {
        // 打印月份标题
        char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
        };

        cout << setw(15) << month_names[month] << " " ;
        cout << setw(31) << month_names[month + 1] << " " ;
        cout << setw(31) << month_names[month + 2] << " " ;
        cout << setw(31) << month_names[month + 3] << " " << endl;

        cout << "Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat" << endl;

        // 获取四个月的信息
        int start_day1 = day_of_week(year, month);
        int days1 = days_in_month(year, month);
        int start_day2 = day_of_week(year, month + 1);
        int days2 = days_in_month(year, month + 1);
        int start_day3 = day_of_week(year, month + 2);
        int days3 = days_in_month(year, month + 2);
        int start_day4 = day_of_week(year, month + 3);
        int days4 = days_in_month(year, month + 3);

        // 计算行数
        int rows1 = (days1 + start_day1 + 6) / 7;
        int rows2 = (days2 + start_day2 + 6) / 7;
        int rows3 = (days3 + start_day3 + 6) / 7;
        int rows4 = (days4 + start_day4 + 6) / 7;
        int rows = max(max(max(rows1, rows2), rows3), rows4);
        rows = max(rows, 4); // 确保至少4行

        // 打印日期
        for (int i = 0; i < rows; i++) {
            // 第一个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day1;
                if (day > 0 && day <= days1)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第二个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day2;
                if (day > 0 && day <= days2)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第三个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day3;
                if (day > 0 && day <= days3)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第四个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day4;
                if (day > 0 && day <= days4)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << endl;
        }

        cout << endl;
    }
}

/* 打印每行6个月的年历 */
void print_calendar_6(int year)
{
    for (int month = 1; month <= 12; month += 6) {
        // 打印月份标题
        char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
        };

        cout << setw(15) << month_names[month] << " " ;
        cout << setw(31) << month_names[month + 1] << " " ;
        cout << setw(31) << month_names[month + 2] << " ";
        cout << setw(31) << month_names[month + 3] << " ";
        cout << setw(31) << month_names[month + 4] << " ";
        cout << setw(31) << month_names[month + 5] << " " << endl;

        cout << "Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
        cout << "     Sun Mon Tue Wed Thu Fri Sat" << endl;

        int start_day1 = day_of_week(year, month);
        int days1 = days_in_month(year, month);
        int start_day2 = day_of_week(year, month + 1);
        int days2 = days_in_month(year, month + 1);
        int start_day3 = day_of_week(year, month + 2);
        int days3 = days_in_month(year, month + 2);

        int rows1 = (days1 + start_day1 + 6) / 7;
        int rows2 = (days2 + start_day2 + 6) / 7;
        int rows3 = (days3 + start_day3 + 6) / 7;

        int start_day4 = day_of_week(year, month + 3);
        int days4 = days_in_month(year, month + 3);
        int start_day5 = day_of_week(year, month + 4);
        int days5 = days_in_month(year, month + 4);
        int start_day6 = day_of_week(year, month + 5);
        int days6 = days_in_month(year, month + 5);

        int rows4 = (days4 + start_day4 + 6) / 7;
        int rows5 = (days5 + start_day5 + 6) / 7;
        int rows6 = (days6 + start_day6 + 6) / 7;

        int rows_first = max(max(rows1, rows2), rows3);
        rows_first = max(rows_first, 4); // 确保至少4行

        

        for (int i = 0; i < rows_first; i++) {
            // 第一个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day1;
                if (day > 0 && day <= days1)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第二个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day2;
                if (day > 0 && day <= days2)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }

            cout << "    "; // 月份之间的间隔

            // 第三个月
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_day3;
                if (day > 0 && day <= days3)
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }
            cout << "    "; // 月份之间的间隔

                // 第四个月
                for (int j = 0; j < 7; j++) {
                    int day = i * 7 + j + 1 - start_day4;
                    if (day > 0 && day <= days4)
                        cout << left << setw(3) << day << " ";
                    else
                        cout << right << "    ";
                }

                cout << "    "; // 月份之间的间隔

                // 第五个月
                for (int j = 0; j < 7; j++) {
                    int day = i * 7 + j + 1 - start_day5;
                    if (day > 0 && day <= days5)
                        cout << left << setw(3) << day << " ";
                    else
                        cout << right << "    ";
                }

                cout << "    "; // 月份之间的间隔

                // 第六个月
                for (int j = 0; j < 7; j++) {
                    int day = i * 7 + j + 1 - start_day6;
                    if (day > 0 && day <= days6)
                        cout << left << setw(3) << day << " ";
                    else
                        cout << right << "    ";
                }
            cout << endl;
        }

        cout << endl;
    }
}

/* 打印每行12个月的年历 */
void print_calendar_12(int year)
{
    // 打印月份标题（第一行6个月）
    char month_names[13][6] = {
    "", "1月", "2月", "3月", "4月", "5月", "6月",
    "7月", "8月", "9月", "10月", "11月", "12月"
    };

    cout << setw(15) << month_names[1] << " ";
    for (int month = 2; month <= 12; month++) {
        cout << setw(31) << month_names[month] << " ";
    }
    cout << endl;

    cout << "Sun Mon Tue Wed Thu Fri Sat";
    for (int month = 2; month <= 12; month++) {
        cout << "     Sun Mon Tue Wed Thu Fri Sat";
    }
    cout << endl;

    int start_days[13], days_in_months[13]/*, rows[13]*/;
    for (int month = 1; month <= 12; month++) {
        start_days[month] = day_of_week(year, month);
        days_in_months[month] = days_in_month(year, month);
    }

    // 打印
    for (int i = 0; i < 6; i++) {
        for (int month = 1; month <= 12; month++, cout << "    ") {
            for (int j = 0; j < 7; j++) {
                int day = i * 7 + j + 1 - start_days[month];
                if (day > 0 && day <= days_in_months[month])
                    cout << left << setw(3) << day << " ";
                else
                    cout << right << "    ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int year, format;

    cout << "请输入年份[1900-2100]\n";
    cin >> year;

    cout << "请输入每行打印的月份数[1/2/3/4/6/12]\n";
    cin >> format;

    cout << year << "年的日历:\n";
    cout << endl;

    switch (format) {
        case 1: 
            print_calendar_1(year); 
            break;
        case 2: 
            print_calendar_2(year); 
            break;
        case 3: 
            print_calendar_3(year); 
            break;
        case 4: 
            print_calendar_4(year); 
            break;
        case 6:
            print_calendar_6(year);
            break;
        case 12:
            print_calendar_12(year);
            break;
    }
    cout << endl;

    return 0;
}
