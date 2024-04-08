#include <stdio.h>
#include <stdlib.h>

void factorize(int n)
{
	int i, j;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			j = n / i;
			printf("%d=%d*%d\n", n, i, j);
			return;
		}
	}
	printf("%d=%d*%d\n", n, n, 1); /* Prime number */
}

int main(int argc, char *argv[])
{
	FILE *file;
	int num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}


