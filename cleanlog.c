#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char **argv) {
	char *base_dir;
	DIR *dir;
	struct dirent *dp;
	char *c;
	base_dir = "C:�_�_Users�_�_[xxxx]�_�_Softimage�_�_XSI_7.01";
	if(NULL == (dir = opendir(base_dir))) {
		printf("Can not open directory.�_n->%s�_n", base_dir);
		scanf("%c", &c);
		exit(1);
	}
	char tmp_str[256] = {0};
	strcpy(tmp_str, base_dir);
	char *d = "�_�_";
	char *b_dir;
	b_dir = strcat(tmp_str, d);
	//printf("%s�_n", b_dir);
	char *r1;
	char *r2;
	for(int i = 0; NULL != (dp = readdir(dir)); ++i) {
		r1 = strstr(dp->d_name, ".ScriptLog.txt");
		if(r1 != NULL) {
			char tmp[256] = {0};
			strcpy(tmp, b_dir);
			strcat(tmp, dp->d_name);
#ifdef DEVELOPMENT
			if(tmp != 0) printf("remove success�F%s�_n", tmp);
			else printf("remove failed�F%s�_n", i, tmp);
#else
			if(remove(tmp) == 0) printf("remove success�F%s�_n", tmp);
			else printf("remove failed�F%s�_n", i, tmp);
#endif
		}
		r2 = strstr(dp->d_name, ".dmp");
		if(r2 != NULL) {
			char tmp2[256] = {0};
			strcpy(tmp2, b_dir);
			strcat(tmp2, dp->d_name);
#ifdef DEVELOPMENT
			if(tmp2 != 0) printf("remove success:%s�_n", tmp2);
			else printf("remove failed:%s�_n", i, tmp2);
#else
			if(remove(tmp2) == 0) printf("remove success:%s�_n", tmp2);
			else printf("remove failed:%s�_n", i, tmp2);
#endif
		}
	}
	closedir(dir);
	scanf("%c", &c);
	return 1;
}
