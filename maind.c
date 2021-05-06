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
int print_result(char *str, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int index)
{
  int x, y;
  printf("--- test %d ---\n", index);
  printf("system -> ");
  x = printf(str, i, j, k, l, m, n, o, p, q, r);
  printf("\n");
  write(1, "yours  -> ", 10);
  y = ft_printf(str, i, j, k, l, m, n, o, p, q, r);
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
  int total, index;
  total = 0;
  index = 1;
  /*1*/ total += print_result("|start%-10.7dtest\t%-*.*i!\t%0*d?%0d.%*i.%3d.end|", -42, 5, 3, -5, 3, 1, 3, 2, -3, -3, index++);
  /*2*/ total += print_result("|%*d|", -14, 4242, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*3*/ total += print_result("|%0*d|", -7, -42, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*4*/ total += print_result("|%*d|", 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*5*/ total += print_result("|%-*.*d|", 5, 3, -5, 0, 0, 0, 0, 0, 0, 0, index++);
  /*6*/ total += print_result("|%0*d|", 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*7*/ total += print_result("|%20.5d|", -4242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*8*/ total += print_result("|%0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*9*/ total += print_result("|%0-7d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*10*/ total += print_result("|%0d.|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*11*/ total += print_result("|%08.5d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*12*/ total += print_result("|%07d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*13*/ total += print_result("|%.5d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*14*/ total += print_result("|%-7d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*15*/ total += print_result("|%-7d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*16*/ total += print_result("|%.3d|", 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*17*/ total += print_result("|%0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*18*/ total += print_result("|%05d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*19*/ total += print_result("|%8.3d|", -4242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*20*/ total += print_result("|%05d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*21*/ total += print_result("|%8.5d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*22*/ total += print_result("|%7d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*23*/ total += print_result("|%5.3d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*24*/ total += print_result("|%8.5d|", -42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*25*/ total += print_result("|%.0d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*26*/ total += print_result("|%0-8.5d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*27*/ total += print_result("|%5.0d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*28*/ total += print_result("|%-5.0d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*29*/ total += print_result("|%0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*30*/ total += print_result("|t3 %50.3d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*31*/ total += print_result("|%0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*32*/ total += print_result("|%.0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*33*/ total += print_result("|%-5.d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*34*/ total += print_result("|%.d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*35*/ total += print_result("|%50.0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*36*/ total += print_result("|%10.0d|", 4242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*37*/ total += print_result("|%20.0d|", 4242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*38*/ total += print_result("|t3 %50.0d|", 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*39*/ total += print_result("|%-8.5d|", -424242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*40*/ total += print_result("|%-10.5d|", -4242, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*41*/ total += print_result("|st3 %*.*d|", 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, index++);
  /*41*/ total += print_result("|st3 %0.0d|", 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*42*/ total += print_result("|%5.0d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*43*/ total += print_result("|%5.d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*44*/ total += print_result("|%08.5d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*45*/ total += print_result("|%05d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*47*/ total += print_result("|%3d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*48*/ total += print_result("|%-3d|", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*49*/ total += print_result("|%--140.*d|", -176, 2043379162, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*50*/ total += print_result("|%2.2d|", -10, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*51*/ total += print_result("|%03d|", -2147483648, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*52*/ total += print_result("|%-0d|", 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*54*/ total += print_result("|%-0000000-------*d|", 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*53*/ total += print_result("|%0*d|", 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*55*/ total += print_result("|%-82.43d|", -1945174241, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*56*/ total += print_result("|%-*.82%|", -26, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  /*57*/ total += print_result("|%*.*d|", 1, -2, -12, 0, 0, 0, 0, 0, 0, 0, index++);
  /*58*/ total += print_result("|%020d|", -2147483648, 0, 0, 0, 0, 0, 0, 0, 0, 0, index++);
  print_total(total, index);
}