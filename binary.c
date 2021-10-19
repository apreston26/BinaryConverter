#include <stdio.h>
#define ON 1
#define OFF 0

int main(int argc, char *argv[])
{
  int c;
  int bits = OFF;
  int digits = OFF;
  int bitCase = 0;
  int errorCase = 0;
  
  while (--argc > 0 && (*++argv)[0] == '-')
    {
      while ((c = *++argv[0]))
	{
	  switch(c)
	    {
	    case 'd':
	      printf("D");
	      if (bits == OFF)
		{
		  digits = ON;
		}
	      break;
	    case '2':
	      printf("2");
	      break;
	    case 'b':
	      printf("B");
	      if (digits == OFF)
		{
		  bits = ON;
		}
	      break;
	    default:
	      printf("Err");
	      errorCase = 1;
	      break;
	    }
	}
    }
  
  while (argc == 2 && (*++argv)[0] == '-')
    {
      while ((c = *++argv[0]))
	{
	  switch (c)
	    {
	    case '8':
	      bitCase += 1;
	      break;
	    case '1':
	      bitCase += 1;
	      break;
	    case '6':
	      bitCase += 1;
	      break;
	    case '4':
	      bitCase += 3;
	      break;
	    case '3':
	      bitCase += 1;
	      break;
	    case '2':
	      bitCase += 2;
	      break;
	    default:
	      errorCase = 2;
	      break;
	    }
	}
    }
   if (argc != 1)
    {
      printf("Error test\n");
    }
   printf("%d", errorCase);
  return 0;
}
  
