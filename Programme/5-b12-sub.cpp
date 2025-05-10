/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
int tj_strlen(const char str[])
{
    int i = 0;
    while (1) {
        if (str[i] == '\0')
            return i;
        else
            i++;
    }
    return 0; 
}



int tj_strcat(char s1[], const char s2[])
{
    int i = tj_strlen(s1); 
    for (int j = 0; j < tj_strlen(s2); j++)
        s1[i + j] = s2[j];
    s1[i + tj_strlen(s2)] = '\0'; 
    return 0;
}



int tj_strncat(char s1[], const char s2[], const int len)
{
    int i = tj_strlen(s1);
    int m = tj_strlen(s2);
    if (len < m)
        m = len;
    for (int j = 0; j < m; j++)
        s1[i + j] = s2[j];
    s1[i + tj_strlen(s2)] = '\0';
    return 0;
}



int tj_strcpy(char s1[], const char s2[])
{
    for (int j = 0; j < tj_strlen(s2); j++)
        s1[j] = s2[j];  
    s1[tj_strlen(s2)] = '\0';
    return 0;
}



int tj_strncpy(char s1[], const char s2[], const int len)
{
    if (len > tj_strlen(s2)) 
        for (int j = 0; j < tj_strlen(s2); j++)
            s1[j] = s2[j];
    else 
        for (int j = 0; j < len; j++) 
            s1[j] = s2[j];
    return 0;
}



int tj_strcmp(const char s1[], const char s2[]) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return 0;
        i++;
    }
    return s1[i]-s2[i];
}



int tj_strcasecmp(const char s1[], const char s2[])
{
    int i = 0;
    char char1_s1, char1_s2;
    char char2_s1_lower, char2_s2_lower;
    while (1) {
        char1_s1 = s1[i], char1_s2 = s2[i];
        if (char1_s1 >= 'A' && char1_s1 <= 'Z') 
            char2_s1_lower = char1_s1 + ('a' - 'A');
        else
            char2_s1_lower = char1_s1;
        if (char1_s2 >= 'A' && char1_s2 <= 'Z') 
            char2_s2_lower = char1_s2 + ('a' - 'A');
        else 
            char2_s2_lower = char1_s2;
        if (char2_s1_lower != char2_s2_lower) 
            return char2_s1_lower - char2_s2_lower;
        if (char2_s1_lower == '\0') 
            return 0;
        i++;
    }
}



int tj_strncmp(const char s1[], const char s2[], const int len)
{
    int i = 0;
    while (s1[i] == s2[i]) {
        if (i >= len - 1)
            break;
        if (s1[i] == '\0')
            return 0;
        i++;
    }
    return s1[i] - s2[i];
}



int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    int i = 0;
    char char1_s1, char1_s2;
    char char2_s1_lower, char2_s2_lower;
    while (1) {
        char1_s1 = s1[i], char1_s2 = s2[i];
        if (char1_s1 >= 'A' && char1_s1 <= 'Z')
            char2_s1_lower = char1_s1 + ('a' - 'A');
        else
            char2_s1_lower = char1_s1;
        if (char1_s2 >= 'A' && char1_s2 <= 'Z')
            char2_s2_lower = char1_s2 + ('a' - 'A');
        else
            char2_s2_lower = char1_s2;
        if (i >= len - 1)
            return char2_s1_lower - char2_s2_lower;
        if (char2_s1_lower != char2_s2_lower)
            return char2_s1_lower - char2_s2_lower;
        if (char2_s1_lower == '\0')
            return 0;
        i++;
    }
}



int tj_strupr(char str[])
{
    for (int i = 0; i < tj_strlen(str); i++)
        if(str[i]>='a'&& str[i]<='z')
            str[i] = str[i] - 32;
    return 0;
}



int tj_strlwr(char str[])
{
    for (int i = 0; i < tj_strlen(str); i++)
        if(str[i]>='A'&& str[i]<='Z')
            str[i] = str[i] + 32;
    return 0;
}



int tj_strchr(const char str[], char ch) 
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch)
            return i + 1;
        i++;
    }
    return 0; 
}



int tj_strstr(const char str[], const char substr[])
{
    int i = 0, j = 0;
    int str_len = tj_strlen(str);
    int substr_len = tj_strlen(substr);
    if (substr_len == 0) return 1;
    if (str_len < substr_len) return 0;
    for (i = 0; i <= str_len - substr_len; i++) {
        int match = 1; 
        for (j = 0; j < substr_len; j++)
            if (str[i + j] != substr[j]) {
                match = 0; 
                break;
            }
        if (match)
            return i + 1; 
    }
    return 0; 
}



int tj_strrchr(const char str[], char ch) 
{
    int last_pos = -1;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch)
            last_pos = i;
        i++;
    }
    if (last_pos != -1)
        return last_pos + 1;
    return 0; 
}



int tj_strrstr(const char str[], const char substr[])
{
    int last_match_pos = -1; 
    int str_len = tj_strlen(str);
    int substr_len = tj_strlen(substr);
    int i = 0, j = 0;
    if (substr_len == 0) { 
        if (str_len == 0) return 1; 
        return str_len + 1;
        return 1; 
    }
    if (str_len < substr_len) return 0;
    for (i = 0; i <= str_len - substr_len; i++) {
        int match = 1;
        for (j = 0; j < substr_len; j++)
            if (str[i + j] != substr[j]) {
                match = 0;
                break;
            }
        if (match)
            last_match_pos = i;
    }
    if (last_match_pos != -1)
        return last_match_pos + 1; 
    return 0;
}



int tj_strrev(char str[])
{
    int len = tj_strlen(str);
    if (len == 0)
        return 0; 
    int i = 0;
    int j = len - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return 0;
}