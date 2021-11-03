#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//generate_sequence mangle characters from both names
void generate_sequence(char *sg, const char *name1, const char *name2)
{
	int sel = 0;

	while(*name1 != '\0' || *name2 != '\0')	{
		if(!sel && *name1 != '\0')	{
			*sg++ = *name1++;
		} else if(sel && *name2 != '\0')	{
			*sg++ = *name2++;
		}
		sel = !sel;
	}

	//We add a null character to assure the format of a string
	*sg = '\0';
}

int main(int argc, char *argv[])
{
	if(argc != 3)	{
		printf("Usage : generate_sequence <NAME1> <NAME2>\n");
		return -1;
	}

	const char *name1 = argv[1];
	const char *name2 = argv[2];
	char *sg = (char *)malloc((strlen(name1) + strlen(name2)) * sizeof(char) + 1);

	generate_sequence(sg, name1, name2);

	//Display the sequence
	printf("SG  : ");
	for(int i = 0; i < strlen(sg); ++i)	{
		printf("%c  ", sg[i]);
	}
	printf("\n");
	printf("DSG : ");
	for(int i = 0; i < strlen(sg); ++i)	{
		printf("%d ", sg[i]);
	}
	printf("\n");

	//Calculating the parameters of the configuration
	int n0 = (int)sg[0] % 3;
	int N = 5 + n0;
	printf("The configuration has %d sites.\n", N);
	int n1 = (int)sg[1] % 2 + 3;
	printf("The first site has %d routers.\n", n1);
	int n2 = (int)sg[2] % 2 + 1;
	printf("%d sites have %d routers.\n", 3 - n0, n2);

	int already_used[100] = {0};
	int *A = (int *)malloc(N * sizeof(int));
	A[0] = (int)sg[3] % 100;
	printf("Site 1 has prefix %d.0.0.0\n", A[0]);
	already_used[A[0]] = 1;
	for(int i = 1; i < N; ++i)	{
		A[i] = (A[i - 1] + 10) % 100;
		while(already_used[A[i]])	{
			A[i] = (A[i] + 1) % 100;
		}
		printf("Site %d has prefix %d.0.0.0\n", i + 1, A[i]);
	}

	return 0;
}
