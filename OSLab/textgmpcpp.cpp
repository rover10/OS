#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
 
int main(void)
{
 mpz_t x;
 mpz_t y;
mpz_init(x);
mpz_init(y);

x=128827483748738478;
y=x+45878475847875487;
printf("%d",y)
;}
