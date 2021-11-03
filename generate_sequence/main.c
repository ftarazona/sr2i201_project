#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	*sg = '\0';
}

int main(int argc, char *argv[])
{
	if(argc != 3)	{
		printf("Usage : generate_sequence <NAME1> <NAME2>\n");
		exit(EXIT_FAILURE);
	}

	const char *name1 = argv[1];
	const char *name2 = argv[2];
	char *sg = (char *)malloc((strlen(name1) + strlen(name2)) * sizeof(char) + 1);

	generate_sequence(sg, name1, name2);

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
}
