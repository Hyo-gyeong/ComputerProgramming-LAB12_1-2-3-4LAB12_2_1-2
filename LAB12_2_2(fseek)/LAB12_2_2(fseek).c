#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2, *fp3;
	char buf[60];

	fp1 = fopen("hello.txt", "rt");
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
	while (!feof(fp1)) {
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	fseek(fp1, 0, SEEK_END);
	fclose(fp1);
	
	fp3 = fopen("hello.txt", "rt");
	if (fp3 == NULL) {
		printf("file3 open error\n");
		return 1;
	}

	fgets(buf, sizeof(buf), fp3);
	while (!feof(fp3)) {
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp3);
	}

	fclose(fp3);
}