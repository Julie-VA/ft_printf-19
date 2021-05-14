#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_OKKO(int x, int y)
{
  if (x == y)
  {
    printf("\e[32m[YEAH] \e[0m\n\n");
    return (1);
  }
  else
  {
    printf("\e[91m[LOOSER] \e[0m \e[32m system: %d \e[0m \e[91m yours: %d \e[0m \n\n", x-2, y-2);
    return (0);
  }
}
int print_result(char *str, unsigned long long i, int index)
{
  int x, y;
  y = 0;
  printf("--- test %d ---\n", index);
  printf("system -> ");
  x = printf(str, i);
  printf("\n");
  write(1, "yours  -> ", 10);
  y = ft_printf(str, i);
  printf("\n");
  return (print_OKKO(x, y));
}
void print_total(int total, int index)
{
  if (total == index - 1)
    printf("\e[32m TOTAL:%d/%d --- GOOD JOB!\e[0m\n\n", total, index - 1);
  else
    printf("\e[91m TOTAL:%d/%d --- TRY AGAIN\e[0m\n\n", total, index - 1);
}
int main(void)
{
  int total, index, x, y;
  total = 0;
  index = 1;
  char *test = malloc(1);
  static char	a01;
  char	a011;
  static unsigned char a02;
  static short a03;
  static unsigned short a04;
  static int a05;
  static unsigned int a06;
  static long a07;
  static unsigned long a08;
  static long long a09;
  static unsigned long long a10;
  static char *a11;
  static void *a12;
  //1
  total += print_result("|%p|", NULL, index++);
  //2
  total += print_result("|%5p|", NULL, index++);
  //3
  total += print_result("|%.p|", NULL, index++);
  //4
  total += print_result("|%5.p|", NULL, index++);
  //5
  total += print_result("|%9.2p|", 1234, index++);
  //6
  total += print_result("|%2.9p|", 1234, index++);
  //7
  total += print_result("|%.5p|", 0, index++);
  //8
  total += print_result("|%.5p|", test, index++);
  //9
  total += print_result("|%5p|", test, index++);
  //10
  total += print_result("|%8.20p|", test, index++);
  //11
  total += print_result("|%30.20p|", test, index++);
  //12
  total += print_result("|%-30.20p|", test, index++);
  //13
  total += print_result("|%-20p|", test, index++);
  //14
  total += print_result("|%018p|", test, index++);
  //15
  total += print_result("|%-28.15p|", test, index++);
  //16
  total += print_result("|%p|", &a01, index++);
  //17
  total += print_result("|%-16.p|", NULL, index++);
  //18
  total += print_result("|%-15p|", NULL, index++);
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p|\n", &a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
  y = ft_printf("yours     ->|%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p|\n", &a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
  total += print_OKKO(x, y); index++;
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*.p|\n", 0, test);
  y = ft_printf("yours     ->|%*.p|\n", 0, test);
  total += print_OKKO(x, y); index++;
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*p|\n", 0, test);
  y = ft_printf("yours     ->|%-*p|\n", 0, test);
  total += print_OKKO(x, y); index++;
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*p|\n", 0, NULL);
  y = ft_printf("yours     ->|%-*p|\n", 0, NULL);
  total += print_OKKO(x, y); index++;
  print_total(total, index);
  free(test);
}