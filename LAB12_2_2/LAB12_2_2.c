#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2;
	char buf[30];
	int state1, state2;

	fp1 = fopen("hello.txt", "rt"); //모드 정확히 기입
	if (fp1 == NULL) {
		printf("file1 open error\n");
		return 1;
	}

	fp2 = fopen("hello2.txt", "wt");
	if (fp2 == NULL) {
		printf("file2 open error\n");
		return 1;
	}

	fgets(buf, sizeof(buf), fp1);
	while (!feof(fp1)) { //파일의 끝이 아니면 계속 반복
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	state1 = fclose(fp1);
	if (state1 != 0) // error 체크. fclose에서의 error 체크는 주로 생략한다. 
	{  
		printf("file1 close error!\n");  
		return 1; 
	}
	state2 = fclose(fp2); 
	if (state2 != 0) 
	{  
		printf("file2 close error!\n"); 
		return 1; 
	}
}