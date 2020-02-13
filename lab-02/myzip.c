#include <stdio.h>
#include <stdlib.h>

struct pkg
{
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
    //pppoopoo
	FILE *fp = fopen(argv[1], "r");	
	int c = fgetc(fp);	
	struct pkg code;
	code.amt = 1;
	code.symbol = c;
	
	while(code.symbol != EOF)
  {
		c = fgetc(fp);
		if(c == code.symbol)
    {
			code.amt++;
		} 
		else
    {
			fwrite(&code, sizeof(struct pkg), 1, stdout);
			code.amt = 1;
			code.symbol = c;
		}	
	}

	fclose(fp);
  }
  exit(0);
  return 0;
}
