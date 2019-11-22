#include <stdio.h>
int main(void)
{
	FILE *fp;

	fp = fopen("hello.txt", "at");
	if (fp == NULL) {
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "Hi\n");
	fprintf(fp, "Everyone");

	fclose(fp);
}