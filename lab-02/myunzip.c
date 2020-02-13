#include <stdio.h>
#include <stdlib.h>
struct bundle{
	int amt;
	char symbol;
}__attribute__((packed));

int main(int argc, char *argv[]) 
{
  if (argc < 2) 
  {
    printf("Usage: %s FILENAME\n", argv[0]);
    exit(1);
  }
  else
  {
	FILE *fp = fopen(argv[1], "r");
	struct bundle code;
	fread(&code, sizeof(struct bundle), 1, fp);
	while(!feof(fp))
  {
		int i;
		for(i = 0; i < code.amt; i++)
    {			
			printf("%c", code.symbol);
		}
	   	fread(&code, sizeof(struct bundle), 1, fp);	
	}
 }
  return 0;
}