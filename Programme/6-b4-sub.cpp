/* 2452098 计算机 赵崇治 */
#include <cstdio>   //NULL
//不再允许包含任何系统头文件
/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */
/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */

int tj_strlen(const char* str)
{
	if (str == NULL)
		return 0;
	const char* p = str;
	while (1) {
		if (*str == '\0')
			return str - p;
		else
			str++;
	}
	return 0;
}



char* tj_strcat(char* s1, const char* s2)
{
	if (s2 == NULL)
		return s1;
	else if (s1 == NULL)
		return NULL;
	int i = tj_strlen(s1);
	char* p1 = s1 + i;
	const char* p2 = s2;
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}



char* tj_strncat(char* s1, const char* s2, const int len)
{
	if (s2 == NULL)
		return s1;
	else if (s1 == NULL)
		return NULL;
	int i = tj_strlen(s1);
	int m = tj_strlen(s2);
	if (len < m)
		m = len;
	char* p1 = s1 + i;
	const char* p2 = s2;
	for (int j = 0; j < m; j++) {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}



char* tj_strcpy(char* s1, const char* s2)
{
	if (s1 == NULL)
		return NULL;
	else if (s2 == NULL) {
		char* p = s1;
		while (*p != '\0') {
			*p = '\0';
			p++;
		}
		return s1;
	}
	char* p1 = s1;
	const char* p2 = s2;
	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return s1;
}



char* tj_strncpy(char* s1, const char* s2, const int len)
{
	if (s2 == NULL) {
		return s1;
	}
	else if (s1 == NULL)
		return NULL;
	char* p1 = s1;
	const char* p2 = s2;
	int count = 0;
	if (len > tj_strlen(s2)) {
		while (*p2 != '\0') {
			*p1 = *p2;
			p1++;
			p2++;
		}
	}
	else {
		for (int j = 0; j < len; j++) {
			*p1 = *p2;
			p1++;
			p2++;
		}
	}
	return s1;
}



int tj_strcmp(const char* s1, const char* s2)
{
	if (s1 == s2) 
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;

	const char* p1 = s1;
	const char* p2 = s2;
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *(const unsigned char*)p1 - *(const unsigned char*)p2;
}



int tj_strcasecmp(const char* s1, const char* s2)
{
	if (s1 == s2)
		return 0;
	if (s1 == NULL) 
		return -1;
	if (s2 == NULL) 
		return 1;

	const char* p1 = s1;
	const char* p2 = s2;
	char char1_s1, char1_s2;
	char char2_s1_lower, char2_s2_lower;
	while (1) {
		char1_s1 = *p1;
		char1_s2 = *p2;

		if (char1_s1 >= 'A' && char1_s1 <= 'Z')
			char2_s1_lower = char1_s1 + ('a' - 'A');
		else
			char2_s1_lower = char1_s1;

		if (char1_s2 >= 'A' && char1_s2 <= 'Z')
			char2_s2_lower = char1_s2 + ('a' - 'A');
		else
			char2_s2_lower = char1_s2;

		if (char2_s1_lower != char2_s2_lower)
			return (unsigned char)char2_s1_lower - (unsigned char)char2_s2_lower;

		if (char2_s1_lower == '\0')
			return 0;
		p1++;
		p2++;
	}
}



int tj_strncmp(const char* s1, const char* s2, const int n)
{
	if (n <= 0) 
		return 0;

	if (s1 == s2)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;

	const char* p1 = s1;
	const char* p2 = s2;
	int i = 0;
	while (i < n) {
		if (*p1 != *p2) {
			return *(const unsigned char*)p1 - *(const unsigned char*)p2;
		}
		if (*p1 == '\0') {
			return 0;
		}
		p1++;
		p2++;
		i++;
	}
	return 0;
}



int tj_strcasencmp(const char* s1, const char* s2, const int n)
{
	if (n <= 0) 
		return 0;

	if (s1 == s2)
		return 0;
	if (s1 == NULL)
		return -1;
	if (s2 == NULL)
		return 1;

	const char* p1 = s1;
	const char* p2 = s2;
	int i = 0;
	char char1_s1, char1_s2;
	char char2_s1_lower, char2_s2_lower;

	while (i < n) {
		char1_s1 = *p1;
		char1_s2 = *p2;

		if (char1_s1 >= 'A' && char1_s1 <= 'Z')
			char2_s1_lower = char1_s1 + ('a' - 'A');
		else
			char2_s1_lower = char1_s1;

		if (char1_s2 >= 'A' && char1_s2 <= 'Z')
			char2_s2_lower = char1_s2 + ('a' - 'A');
		else
			char2_s2_lower = char1_s2;

		if (char2_s1_lower != char2_s2_lower) {
			return (unsigned char)char2_s1_lower - (unsigned char)char2_s2_lower;
		}

		if (char2_s1_lower == '\0') {
			return 0;
		}
		p1++;
		p2++;
		i++;
	}
	return 0;
}



char* tj_strupr(char* str)
{
	if (str == NULL) 
		return NULL;

	char* p = str;
	while (*p != '\0') {
		if (*p >= 'a' && *p <= 'z')
			*p = *p - ('a' - 'A');
		p++;
	}
	return str;
}



char* tj_strlwr(char* str)
{
	if (str == NULL) 
		return NULL;

	char* p = str;
	while (*p != '\0') {
		if (*p >= 'A' && *p <= 'Z')
			*p = *p + ('a' - 'A');
		p++;
	}
	return str;
}



int tj_strchr(const char* str, const char ch)
{
	if (str == NULL) 
		return 0;

	const char* p = str;
	while (*p != '\0') {
		if (*p == ch)
			return (p - str) + 1;
		p++;
	}
	if (ch == '\0') {
		return (p - str) + 1;
	}
	return 0; 
}



int tj_strstr(const char* str, const char* substr)
{
	if (str == NULL || substr == NULL) return 0;

	int str_len = 0;
	const char* temp_str = str;
	while (*temp_str != '\0') {
		str_len++;
		temp_str++;
	}

	int substr_len = 0;
	const char* temp_substr = substr;
	while (*temp_substr != '\0') {
		substr_len++;
		temp_substr++;
	}

	if (substr_len == 0) 
		return 1; 
	if (str_len < substr_len) 
		return 0;

	for (int i = 0; i <= str_len - substr_len; i++) {
		int match = 1;
		const char* p1 = str + i;
		const char* p2 = substr;
		for (int j = 0; j < substr_len; j++) {
			if (*p1 != *p2) {
				match = 0;
				break;
			}
			p1++;
			p2++;
		}
		if (match)
			return i + 1;
	}
	return 0;
}



int tj_strrchr(const char* str, const char ch)
{
	if (str == NULL)
		return 0;

	int last_pos = -1;
	const char* p = str;
	int current_idx = 0;
	while (*p != '\0') {
		if (*p == ch)
			last_pos = current_idx;
		p++;
		current_idx++;
	}

	if (ch == '\0') {
		return current_idx + 1;
	}

	if (last_pos != -1)
		return last_pos + 1; 

	return 0;
}



int tj_strrstr(const char* str, const char* substr)
{
	if (str == NULL || substr == NULL)
		return 0;

	int str_len = 0;
	const char* temp_str = str;
	while (*temp_str != '\0') {
		str_len++;
		temp_str++;
	}

	int substr_len = 0;
	const char* temp_substr = substr;
	while (*temp_substr != '\0') {
		substr_len++;
		temp_substr++;
	}
	if (substr_len == 0) {
		return str_len + 1;
	}

	if (str_len < substr_len) 
		return 0;

	int last_match_pos = -1; 
	for (int i = 0; i <= str_len - substr_len; i++) {
		int match = 1;
		const char* p1 = str + i;
		const char* p2 = substr;
		for (int j = 0; j < substr_len; j++) {
			if (*p1 != *p2) {
				match = 0;
				break;
			}
			p1++;
			p2++;
		}
		if (match)
			last_match_pos = i; 
	}

	if (last_match_pos != -1)
		return last_match_pos + 1;

	return 0;
}



char* tj_strrev(char* str)
{
	if (str == NULL)
		return NULL;
	if (*str == '\0') {
		return str;
	}

	int len = 0;
	char* p_len = str;
	while (*p_len != '\0') {
		len++;
		p_len++;
	}

	int i = 0;
	int j = len - 1;
	char temp_char;
	while (i < j) {
		char* p1 = str + i;
		char* p2 = str + j;
		temp_char = *p1;
		*p1 = *p2;
		*p2 = temp_char;
		i++;
		j--;
	}
	return str;
}