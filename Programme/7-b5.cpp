/* 2452098 计算机 赵崇治 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
		if (name_len_1 < (int)strlen(list_round_1[i].name))
			name_len_1 = (int)strlen(list_round_1[i].name);

		for (int j = i + 1; j < list_num_1; j++) {
			if (list_round_1[i].no > list_round_1[j].no) {
				int t = list_round_1[i].no;
				list_round_1[i].no = list_round_1[j].no;
				list_round_1[j].no = t;

				char temp[MAX_NAME_LEN];
				strcpy(temp, list_round_1[i].name);
				strcpy(list_round_1[i].name, list_round_1[j].name);
				strcpy(list_round_1[j].name,temp);
			}
		}
	}

	for (int i = 0; i < list_num_2; i++) {
		if (name_len_2 < (int)strlen(list_round_2[i].name))
			name_len_2 = (int)strlen(list_round_2[i].name);

		for (int j = i + 1; j < list_num_2; j++) {
			if (list_round_2[i].no > list_round_2[j].no) {
				int t = list_round_2[i].no;
				list_round_2[i].no = list_round_2[j].no;
				list_round_2[j].no = t;
				char temp[MAX_NAME_LEN];
				strcpy(temp, list_round_2[i].name);
				strcpy(list_round_2[i].name, list_round_2[j].name);
				strcpy(list_round_2[j].name,temp);
			}
		}
	}
}

int stu_list::stu_union()
{
	int i = 0; // list_round_1 的下标
	int j = 0; // list_round_2 的下标
	int k = 0; // list_merge 的下标

	// 当两个列表都还有元素时，进行比较合并
	while (i < list_num_1 && j < list_num_2) {
		if (list_round_1[i].no < list_round_2[j].no) {
			// 将 list_1 的当前学生复制到 merge 列表
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			i++;
		}
		else if (list_round_2[j].no < list_round_1[i].no) {
			// 将 list_2 的当前学生复制到 merge 列表
			list_merge[k].stu_no = list_round_2[j].no;
			strcpy(list_merge[k].stu_name, list_round_2[j].name);
			j++;
		}
		else { // 学号相等，是同一学生，去重处理
			// 只复制一次，但两个列表的下标都要移动
			list_merge[k].stu_no = list_round_1[i].no;
			strcpy(list_merge[k].stu_name, list_round_1[i].name);
			i++;
			j++;
		}
		k++; // 移动合并后列表的下标
	}

	// 如果第一轮列表还有剩余，复制剩余部分
	while (i < list_num_1) {
		list_merge[k].stu_no = list_round_1[i].no;
		strcpy(list_merge[k].stu_name, list_round_1[i].name);
		i++;
		k++;
	}

	// 如果第二轮列表还有剩余，复制剩余部分
	while (j < list_num_2) {
		list_merge[k].stu_no = list_round_2[j].no;
		strcpy(list_merge[k].stu_name, list_round_2[j].name);
		j++;
		k++;
	}

	// 更新合并后的总人数
	this->list_merge_num = k;
	return this->list_merge_num;
}

/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list(int num1,int num2)
{
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
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


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;

	// 从合并后的列表中找到最长的姓名长度，用于对齐
	int max_name_len = 0;
	for (int i = 0; i < this->list_merge_num; i++) {
		int len = strlen(this->list_merge[i].stu_name);
		if (len > max_name_len) {
			max_name_len = len;
		}
	}

	// 打印表头
	cout << "=====================================";
	for (int i = 0; i < max_name_len; ++i) cout << "=";
	cout << "\n";

	cout << " 序号  学号     姓名";
	// 打印姓名列的填充空格
	for (int i = 0; i < max_name_len - 4; ++i) { // "姓名"占4个字节(2个汉字)
		cout << " ";
	}
	cout << "  第一轮  第二轮 \n";

	cout << "=====================================";
	for (int i = 0; i < max_name_len; ++i) cout << "=";
	cout << "\n";

	// 遍历最终名单并打印每一行
	for (int i = 0; i < this->list_merge_num; i++) {
		// 打印序号
		cout << " " << i + 1;
		if (i + 1 < 10) cout << "     ";
		else if (i + 1 < 100) cout << "    ";
		else cout << "   ";

		// 打印学号
		cout << this->list_merge[i].stu_no << "   ";

		// 打印姓名
		cout << this->list_merge[i].stu_name;

		// 打印姓名后的填充空格以对齐
		int current_name_len = strlen(this->list_merge[i].stu_name);
		for (int p = 0; p < max_name_len - current_name_len; ++p) {
			cout << " ";
		}
		cout << "     ";

		// 检查并打印第一轮选课情况
		bool in_round_1 = false;
		for (int r1 = 0; r1 < list_num_1; ++r1) {
			if (list_round_1[r1].no == this->list_merge[i].stu_no) {
				in_round_1 = true;
				break;
			}
		}
		cout << (in_round_1 ? "Y" : "N") << "       ";

		// 检查并打印第二轮选课情况
		bool in_round_2 = false;
		for (int r2 = 0; r2 < list_num_2; ++r2) {
			if (list_round_2[r2].no == this->list_merge[i].stu_no) {
				in_round_2 = true;
				break;
			}
		}
		cout << (in_round_2 ? "Y" : "N");

		cout << endl;
	}
	return 0;
}

int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */
	list.stu_sort();
	list.stu_union();

	/* 打印 */
	list.print("最终选课名单");

	return 0;
}