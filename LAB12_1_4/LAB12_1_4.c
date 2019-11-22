#include <stdio.h>
int main(void)
{
	FILE *fp1, *fp2;
	char str;

	fp1 = fopen("hello.txt", "wt");
	if (fp1 == NULL) {
		printf("file open error");
		return 1;
	}
	fprintf(fp1, "Hello\n");
	fprintf(fp1, "World\n");
	fclose(fp1);

	fp2 = fopen("hello.txt", "rt");
	if (fp2 == NULL) {
		printf("file open error");
		return 1;
	}
	
	str = getc(fp2);
	while (!feof(fp2)) {
		putc(str, stdout);
		str = getc(fp2);
	}

	fclose(fp2);
}