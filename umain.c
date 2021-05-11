#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

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
void print_total(int total, int index)
{
  if (total == index - 1)
    printf("\e[32m TOTAL:%d/%d --- GOOD JOB!\e[0m\n\n", total, index - 1);
  else
    printf("\e[91m TOTAL:%d/%d --- TRY AGAIN\e[0m\n\n", total, index - 1);
}
// int print_result_one_star(cha *str, int j, unsigned long long i)
// {
//   int x, y;
//   printf("--- test %d ---\n", index);
//   printf("system -> ");
//   x = printf(str, j, i);
//   printf("\n");
//   write(1, "yours  -> ", 10);
//   y = ft_printf(str, j, i);
//   printf("\n");
//   return (print_OKKO(x, y));
// }
int main(void)
{
  int x, y, total, index;
  total = 0;
  index = 1;
  //1
  printf("--- test %d ---\n", index);
  x = printf("system   ->|%-7u|\n", 33);
  y = ft_printf("yours    ->|%-7u|\n", 33);
  total += print_OKKO(x, y); index++;
  //2
	printf("--- test %d ---\n", index);
  x = printf("system   ->|%05u|\n", 33);
  y = ft_printf("yours    ->|%05u|\n", 33);
  total += print_OKKO(x, y); index++;
  //3
	printf("--- test %d ---\n", index);
  x = printf("system   ->|%05d|\n", 33);
  y = ft_printf("yours    ->|%05d|\n", 33);
  total += print_OKKO(x, y); index++;
  //4
	printf("--- test %d ---\n", index);
  x = printf("system   ->|%03.3u|\n", 3333);
  y = ft_printf("yours    ->|%03.3u|\n", 3333);
  total += print_OKKO(x, y); index++;
  //5
	printf("--- test %d ---\n", index);
	// total += print_result_on_star("|%0045.*u|" , -127, 2553740548u); index++;
  x = printf("system   ->|%-100.98u|\n", 4198534266u);
  y = ft_printf("yours    ->|%-100.98u|\n", 4198534266u);
  total += print_OKKO(x, y); index++;
  //6
	printf("--- test %d ---\n", index);
  x = printf("|%-107.*u|\n", -168,2003619509u);
  y = ft_printf("|%-107.*u|\n", -168,2003619509u);
  total += print_OKKO(x, y); index++;
  //7
	printf("--- test %d ---\n", index);
  x = printf("|%093.12u|\n", 3566926644u);
  y = ft_printf("|%093.12u|\n", 3566926644u);
  total += print_OKKO(x, y); index++;
  //8
	printf("--- test %d ---\n", index);
  x = printf("|%.u|\n", 0);
  y = ft_printf("|%.u|\n", 0);
  total += print_OKKO(x, y); index++;
  //9
	printf("--- test %d ---\n", index);
  x = printf("|%.0u|\n", 0);
  y = ft_printf("|%.0u|\n", 0);
  total += print_OKKO(x, y); index++;
  //10
	printf("--- test %d ---\n", index);
  x = printf("|%0*.3u|\n", 4, 8);
  y = ft_printf("|%0*.3u|\n", 4, 8);
  total += print_OKKO(x, y); index++;
  //11
	printf("--- test %d ---\n", index);
  x = printf("|%0*.*u|\n", 4, 0, 8);
  y = ft_printf("|%0*.*u|\n", 4, 0, 8);
  total += print_OKKO(x, y); index++;
  //12
	printf("--- test %d ---\n", index);
  x = printf("|%*.*u|\n", 4, 0, 8);
  y = ft_printf("|%*.*u|\n", 4, 0, 8);
  total += print_OKKO(x, y); index++;
  //13
	printf("--- test %d ---\n", index);
  x = printf("|%5.0u|\n", 0);
  y = ft_printf("|%5.0u|\n", 0);
  total += print_OKKO(x, y); index++;
  //14
	printf("--- test %d ---\n", index);
  x = printf("|%5.u|\n", 0);
  y = ft_printf("|%5.u|\n", 0);
  total += print_OKKO(x, y); index++;
  //15
	printf("--- test %d ---\n", index);
  x = printf("|%-*.*u|\n", 4, 0, 8);
  y = ft_printf("|%-*.*u|\n", 4, 0, 8);
  total += print_OKKO(x, y); index++;
  //16
	printf("--- test %d ---\n", index);
  x = printf("|%-5.0u|\n", 0);
  y = ft_printf("|%-5.0u|\n", 0);
  total += print_OKKO(x, y); index++;
  //17
	printf("--- test %d ---\n", index);
  x = printf("|%0*.*u|\n", 4, 0, 0);
  y = ft_printf("|%0*.*u|\n", 4, 0, 0);
  total += print_OKKO(x, y); index++;
  //18
	printf("--- test %d ---\n", index);
  x = printf("|%*.*u|\n", 0, 2, 99999999);
  y = ft_printf("|%*.*u|\n", 0, 2, 99999999);
  total += print_OKKO(x, y); index++;
  //19
	printf("--- test %d ---\n", index);
  x = printf("|%*.*u|\n", 0, 0, 0);
  y = ft_printf("|%*.*u|\n", 0, 0, 0);
  total += print_OKKO(x, y); index++;
  //20
	printf("--- test %d ---\n", index);
  x = printf("|%-*u|\n", 0, 5, 8);
  y = ft_printf("|%-*u|\n", 0, 5, 8);
  total += print_OKKO(x, y); index++;
  //21
	printf("--- test %d ---\n", index);
  x = printf("|%u|\n", 0);
  y = ft_printf("|%u|\n", 0);
  total += print_OKKO(x, y); index++;
  //22
	printf("--- test %d ---\n", index);
  x = printf("|%0*u|\n", 0, 0);
  y = ft_printf("|%0*u|\n", 0, 0);
  total += print_OKKO(x, y); index++;
  //23
	printf("--- test %d ---\n", index);
  x = printf("|%0*.*u|\n", 0, -1, 8);
  y = ft_printf("|%0*.*u|\n", 0, -1, 8);
  total += print_OKKO(x, y); index++;
  //24
	printf("--- test %d ---\n", index);
  x = printf("|%-05%|\n");
  y = ft_printf("|%-05%|\n");
  total += print_OKKO(x, y); index++;
  //25
	printf("--- test %d ---\n", index);
  x = printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 0, 'a', 0, 'a', 0, 'a', 0, 'a');
  y = ft_printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 0, 'a', 0, 'a', 0, 'a', 0, 'a');
  total += print_OKKO(x, y); index++;
  //26
	printf("--- test %d ---\n", index);
  x = printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 5, 'a', 5, 'a', 5, 'a', 5, 'a');
  y = ft_printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 5, 'a', 5, 'a', 5, 'a', 5, 'a');
  total += print_OKKO(x, y); index++;
  //27
	printf("--- test %d ---\n", index);
  x = printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -5, 'a', -5, 'a', -5, 'a', -5, 'a');
  y = ft_printf("|%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %-*c, %-*c, %*c, %*c|\n", 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', -5, 'a', -5, 'a', -5, 'a', -5, 'a');
  total += print_OKKO(x, y); index++;
  //28
	printf("--- test %d ---\n", index);
  x = printf("|%-*c, %-*c|\n", 0, 'a', 0, 'a');
  y = ft_printf("|%-*c, %-*c|\n", 0, 'a', 0, 'a');
  total += print_OKKO(x, y); index++;
  //29
	printf("--- test %d ---\n", index);
  x = printf("|%0*.u|\n", 1, 4294967161);
  y = ft_printf("|%0*.u|\n", 1, 4294967161);
  total += print_OKKO(x, y); index++;
  //30
	printf("--- test %d ---\n", index);
  x = printf("|%.%|\n");
  y = ft_printf("|%.%|\n");
  total += print_OKKO(x, y); index++;
  //31
	printf("--- test %d ---\n", index);
  x = printf("|%-4.%|\n");
  y = ft_printf("|%-4.%|\n");
  total += print_OKKO(x, y); index++;
  //32
	printf("--- test %d ---\n", index);
  x = printf("|%-*%|\n", 0);
  y = ft_printf("|%-*%|\n", 0);
  total += print_OKKO(x, y); index++;
  //33
	printf("--- test %d ---\n", index);
  x = printf("|%-*.4%|\n", 0);
  y = ft_printf("|%-*.4%|\n", 0);
  total += print_OKKO(x, y); index++;
  //34
	printf("--- test %d ---\n", index);
  x = printf("|%-.3%|\n");
  y = ft_printf("|%-.3%|\n");
  total += print_OKKO(x, y); index++;
  //35
	printf("--- test %d ---\n", index);
  x = printf("|%-4%|\n");
  y = ft_printf("|%-4%|\n");
  total += print_OKKO(x, y); index++;
  //36
	printf("--- test %d ---\n", index);
  x = printf("|%-4.2%|\n");
  y = ft_printf("|%-4.2%|\n");
  total += print_OKKO(x, y); index++;
  //37
	printf("--- test %d ---\n", index);
  x = printf("|%-4.1%|\n");
  y = ft_printf("|%-4.1%|\n");
  total += print_OKKO(x, y); index++;
  //38
	printf("--- test %d ---\n", index);
  x = printf("|%-4.3%|\n");
  y = ft_printf("|%-4.3%|\n");
  total += print_OKKO(x, y); index++;
  //39
	printf("--- test %d ---\n", index);
  x = printf("|%00%|\n");
  y = ft_printf("|%00%|\n");
  total += print_OKKO(x, y); index++;
  //40
	printf("--- test %d ---\n", index);
  x = printf("|%01.%|\n");
  y = ft_printf("|%01.%|\n");
  total += print_OKKO(x, y); index++;
  //41
	printf("--- test %d ---\n", index);
  x = printf("|%01.*%|\n", -4);
  y = ft_printf("|%01.*%|\n", -4);
  total += print_OKKO(x, y); index++;
  //42
	printf("--- test %d ---\n", index);
  x = printf("|%00.3%|\n");
  y = ft_printf("|%00.3%|\n");
  total += print_OKKO(x, y); index++;
  //43
	printf("--- test %d ---\n", index);
  x = printf("|%00.4%|\n");
  y = ft_printf("|%00.4%|\n");
  total += print_OKKO(x, y); index++;
  //44
	printf("--- test %d ---\n", index);
  x = printf("|%4.*%|\n", -2);
  y = ft_printf("|%4.*%|\n", -2);
  total += print_OKKO(x, y); index++;
  print_total(total, index);
  return 0;
}