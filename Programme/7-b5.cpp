/* 2452098 计算机 赵崇治 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];    //姓名
	friend class stu_list;
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	int name_len_1;
	int name_len_2;
	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */

public:
	stu_list(int num1 = 0, int num2 = 0);
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单
	void stu_sort();
	int stu_union();
	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */
void stu_list::stu_sort()
{
	for (int i = 0; i < list_num_1; i++) {
		for (int j = i + 1; j < list_num_1; j++) {
			if (list_round_1[i].no > list_round_1[j].no) {
				student temp = list_round_1[i];
				list_round_1[i] = list_round_1[j];
				list_round_1[j] = temp;
			}
		}
	}

	if (list_num_1 > 0) {
		int k = 1;
		for (int i = 1; i < list_num_1; i++) {
			if (list_round_1[i].no != list_round_1[k - 1].no) {
				if (i != k) {
					list_round_1[k] = list_round_1[i];
				}
				k++;
			}
		}
		list_num_1 = k;
	}

	for (int i = 0; i < list_num_2; i++) {
		for (int j = i + 1; j < list_num_2; j++) {
			if (list_round_2[i].no > list_round_2[j].no) {
				student temp = list_round_2[i];
				list_round_2[i] = list_round_2[j];
				list_round_2[j] = temp;
			}
		}
	}

	if (list_num_2 > 0) {
		int k = 1;
		for (int i = 1; i < list_num_2; i++) {
			if (list_round_2[i].no != list_round_2[k - 1].no) {
				if (i != k) {
					list_round_2[k] = list_round_2[i];
				}
				k++;
			}
		}
		list_num_2 = k;
	}
}

int stu_list::stu_union()
{
	int i = 0; // list_round_1 的下标
	int j = 0; // list_round_2 的下标
	int k = 0; // list_merge 的下标

	while (i < list_num_1 && j < list_num_2) {
		if (list_round_1[i].no < list_round_2[j].no) {
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			i++;
		}
		else if (list_round_2[j].no < list_round_1[i].no) {
			list_merge[k].stu_no = list_round_2[j].no;
			strcpy(list_merge[k].stu_name, list_round_2[j].name);
			j++;
		}
		else {
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			i++;
			j++;
		}
		k++;
	}

	while (i < list_num_1) {
		list_merge[k].stu_no = list_round_1[i].no;
		strcpy(list_merge[k].stu_name, list_round_1[i].name);
		i++;
		k++;
	}

	while (j < list_num_2) {
		list_merge[k].stu_no = list_round_2[j].no;
		strcpy(list_merge[k].stu_name, list_round_2[j].name);
		j++;
		k++;
	}

	this->list_merge_num = k;
	return this->list_merge_num;
}

stu_list::stu_list(int num1, int num2){}

int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	switch (round) {
	case 1:
		this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
		if (this->list_num_1 > 0)
			print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
		else
			ret = -1;
		break;
	case 2:
		this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
		if (this->list_num_2 > 0)
			print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
		else
			ret = -1;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}

int stu_list::print(const char* prompt)
{
	if (prompt) {
		cout << prompt << endl;
	}

	int max_name_len = 0;
	for (int i = 0; i < this->list_merge_num; i++) {
		int len = strlen(this->list_merge[i].stu_name);
		if (len > max_name_len) {
			max_name_len = len;
		}
	}
    if (max_name_len < 4) {
        max_name_len = 4;
    }

	cout << "=================================================" << endl;
	cout << " 序号  学号     姓名";
	for (int i = 0; i < max_name_len - 4; i++)
		cout << " ";
	cout << "  第一轮  第二轮" << endl;
	cout << "=================================================" << endl;

	for (int i = 0; i < this->list_merge_num; i++) {
		bool in_round_1 = false;
		for (int r1 = 0; r1 < list_num_1; ++r1) {
			if (list_round_1[r1].no == this->list_merge[i].stu_no) {
				in_round_1 = true;
				break;
			}
		}

		bool in_round_2 = false;
		for (int r2 = 0; r2 < list_num_2; ++r2) {
			if (list_round_2[r2].no == this->list_merge[i].stu_no) {
				in_round_2 = true;
				break;
			}
		}
		
		cout << " " << left << setw(6) << i + 1;
		cout << left << setw(8) << this->list_merge[i].stu_no << " ";
		cout << left << setw(max_name_len) << this->list_merge[i].stu_name;

        const char* status1 = "";
        const char* status2 = "";

        if (in_round_1 && in_round_2) {
            status1 = "Y";
            status2 = "Y";
        } else if (in_round_1 && !in_round_2) {
            status1 = "Y";
            status2 = "退课";
        } else if (!in_round_1 && in_round_2) {
            status1 = "/";
            status2 = "补选";
        }
        
        cout << "  " << left << setw(8) << status1 << status2 << endl;
	}
    cout << "=================================================" << endl;
	return 0;
}

int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1, MAX_FILENAME_LEN);
	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2, MAX_FILENAME_LEN);

	stu_list list;

	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	list.stu_sort();
	list.stu_union();

	list.print("最终选课名单");

	return 0;
}
