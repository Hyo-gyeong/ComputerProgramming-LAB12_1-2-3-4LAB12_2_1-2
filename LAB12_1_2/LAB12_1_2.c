#include <stdio.h> 
int main(void)
{ 
	int state;  
	FILE *fp; 
	char ch; 
 
	fp = fopen("hello.txt", "rt");  
	if (fp == NULL) {
		printf("���� ���� �����Դϴ�!!!\n"); 
		return 1; 
	} 
 
    ch = getc(fp);
	while (!feof(fp)) {
		putc(ch, stdout);
		ch = getc(fp);
	}

	state = fclose(fp);
	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}
} 