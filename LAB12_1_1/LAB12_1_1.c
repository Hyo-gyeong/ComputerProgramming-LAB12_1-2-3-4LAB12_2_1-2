#include <stdio.h> 
#include <conio.h>
int main(void) 
{ 
	int state; 
	FILE *fp; 
	char ch; 
 
	fp = fopen("hello.txt", "wt"); 
	if (fp == NULL) { 
		printf("file open error!\n");   
		return 1; 
	} 
 
	fprintf(fp, "Hello\n"); 
	fprintf(fp, "Wolrd\n"); 
 
	state = fclose(fp);  
	if (state != 0) { // 이 체크는 생략 가능   
		printf("file close error!\n");  
		return 1;  
	}
}