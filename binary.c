/**********************************/
/* Austin Preston                 */
/* October 20 2021                */
/* CS-241 002                     */
/* This code converts binary to   */
/* decimal or vice versa          */
/**********************************/

#include <stdio.h>
#include <string.h>

#define ON 1
#define OFF 0
#define MAXSIZE 64

int atoi(const char* str);
void digitsToBits(int num, int numOfBits);
void bitsToDigits(int num, int numOfBits);
void errorHandler(int errorCase);

int main(int argc, char *argv[])
{
  int c;
  int bits = OFF;
  int digits = OFF;
  int bitCase = 0;
  int errorCase = 0;
  int num = 0;
  
  
  while (--argc > 0 && (*++argv)[0] == '-')
    {
      while ((c = *++argv[0]))
	{
	  switch(c)
	    {
	    case 'd':
	      if (bits == OFF)
		{
		  digits = ON;
		}
	      break;
	    case 'b':
	      if (digits == OFF)
		{
		  bits = ON;
		}
	      break;
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
	      if (bitCase != 0)
		{
		  bitCase += 2;
		}
              break;
	    default:
	      errorCase = 1;
	      errorHandler(errorCase);
	      break;
	    }
	}
    }
   
   if (argc != 1)
     {
       errorCase = 2;
       errorHandler(errorCase);
     }
   else
     {
       num = atoi(argv[0]);
       if (digits == ON)
	 { 
	       switch(bitCase)
		 {
		 case 1:
		   digitsToBits(num, 8);
		   break;
		 case 2:
		   digitsToBits(num, 16);
		   break;
		 case 3:
		   digitsToBits(num, 32);
		   break;
		 case 4:
		   digitsToBits(num, 64);
		   break;
		 }
	 }
        else if (bits == ON)
	 {
	   switch(bitCase)
	     {
	     case 1:
	       bitsToDigits(num, 8); 
	       break;
	     case 2:
	       bitsToDigits(num, 16);
	       break;
	     case 3:
	       bitsToDigits(num, 32);
	       break;
	     case 4:
	       bitsToDigits(num, 64);
	       break;
	     }
	 }
	   
     }
  return 0;
}

/*
BUG: Cannot handle invaild numbers 
 */
void digitsToBits(int num, int numOfBits)
{
  int binaryReturn[MAXSIZE] = {0};
  int i, j = 0;
  int bitCounter = 0;
  
  while (num != 0)
    {
      binaryReturn[i] = num  % 2;
      num = num / 2;
      i++;
    }
  for (j = numOfBits - 1; j >= 0; j--)
    {
      if (bitCounter == 4)
	{
	  printf(" ");
	  bitCounter = 0;
	}
      printf("%d", binaryReturn[j]);
      bitCounter++;
    }
  printf("\n");
}
/*
BUG: Cannot handle numbers with more than 10 bits
BUG: Cannot handle invalid numbers
 */
void bitsToDigits(int num, int numOfBits)
{
  int decimalReturn;
  int base = 1;
  int rem;
  int space = 0;
  int i = 0;
  
  while (num != 0 && i != numOfBits )
    {
      rem = num % 10;
      decimalReturn += rem * base;
      num = num / 10;
      base = base * 2;
      i++;
    }
  switch(numOfBits)
    {
    case 8:
      space = 3;
      break;
    case 16:
      space = 5;
      break;
    case 32:
      space = 10;
      break;
    case 64:
      space = 19;
      break;
    }
  printf("%*d\n",space,  decimalReturn);  
}

void errorHandler(int errorCase)
{
  switch (errorCase)
    {
    case 1:
      printf("ERROR: argument 1 must be -b2d | -d2b");
      printf("argument 2 must be -8 | -16 | -32 | 64\n");
      break;
    case 2:
      printf("ERROR: incorrect number of arguments\n");
      break;
    }
  printf("usage:\n");
  printf("binary OPTION SIZE NUMBER\n");
  printf("  OPTION:\n");
  printf("    -b2d  NUMBER is binary and output will be in decimal.\n");
  printf("    -d2b  NUMBER is decimal and output will be in binary.\n");
  printf("\n");
  printf("  SIZE:\n");
  printf("    -8    input is an unsigned 8-bit integer.\n");
  printf("    -16   input is an unsigned 16-bit integer.\n");
  printf("    -32   input is an unsigned 32-bit integer.\n");
  printf("    -64   input is an unsigned 64-bit integer.\n");
  printf("\n");
  printf("  NUMBER:\n");
  printf("    number to be converted.");
  printf("\n");
}
