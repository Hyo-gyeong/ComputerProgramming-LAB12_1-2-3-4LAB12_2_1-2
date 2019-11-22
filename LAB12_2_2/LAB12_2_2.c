#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2;
	char buf[30];
	int state1, state2;

	fp1 = fopen("hello.txt", "rt"); //��� ��Ȯ�� ����
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
	while (!feof(fp1)) { //������ ���� �ƴϸ� ��� �ݺ�
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	state1 = fclose(fp1);
	if (state1 != 0) // error üũ. fclose������ error üũ�� �ַ� �����Ѵ�. 
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