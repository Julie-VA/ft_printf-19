#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int print_result(int x, int y)
{
  if (x == y)
  {
    printf("\e[32m[YEAH] \e[0m\n\n");
    return (1);
  }
  else
  {
    printf("\e[91m[LOOSER] \e[0m \e[32m system: %d \e[0m \e[91m yours: %d \e[0m \n\n", x-15, y-15);
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
int main(void)
{
  int x, y, index, total;
  static char *s_hidden = "you fucked\0don't print me lol\0";
  index = 1;
  total = 0;
  //1
  printf("--- test %d ---\n", index);
  x = printf("system    ->start-%.5s\t%s\t%.*s!%6s.%-6s.-end\n", "salutdnjsd", "ca va ?", 3, "wééééééééé", "panda", "geant");
  y = ft_printf("yours     ->start-%.5s\t%s\t%.*s!%6s.%-6s.-end\n", "salutdnjsd", "ca va ?", 3, "wééééééééé", "panda", "geant");
  total += print_result(x, y); index++;//
  //2
  printf("--- test %d ---\n", index);
  x = printf("system    ->|hello, %s.|\n", "xav");
  y = ft_printf("yours     ->|hello, %s.|\n", "xav");
  total += print_result(x, y); index++;//
  //3
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%.7s|\n", "hello");
  y = ft_printf("yours     ->|%.7s|\n", "hello");
  total += print_result(x, y); index++;//
  //4
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%7.5s|\n", "yo");
  y = ft_printf("yours     ->|%7.5s|\n", "yo");
  total += print_result(x, y); index++;//
  //5
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%7.5s|\n", "hellocavav");
  y = ft_printf("yours     ->|%7.5s|\n", "hellocavav");
  total += print_result(x, y); index++;//
  //6
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%32s|\n", "abc");
  y = ft_printf("yours     ->|%32s|\n", "abc");
  total += print_result(x, y); index++;//
  //7
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-7.5s|\n", "yolo");
  y = ft_printf("yours     ->|%-7.5s|\n", "yolo");
  total += print_result(x, y); index++;//
  //8
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-7.5s|\n", "yolomdadame");
  y = ft_printf("yours     ->|%-7.5s|\n", "yolomdadame");
  total += print_result(x, y); index++;//
  //9
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%3.s|\n", NULL);
  y = ft_printf("yours     ->|%3.s|\n", NULL);
  total += print_result(x, y); index++;//
  //10
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%3.s|\n", s_hidden);
  y = ft_printf("yours     ->|%3.s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //11
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%3.s|\n", "testqdntest ");
  y = ft_printf("yours     ->|%3.s|\n", "testqdntest ");
  total += print_result(x, y); index++;//
  //12
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-3.s|\n", s_hidden);
  y = ft_printf("yours     ->|%-3.s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //13
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%00s|\n", s_hidden);
  y = ft_printf("yours     ->|%00s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //14
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%00-s|\n", s_hidden);
  y = ft_printf("yours     ->|%00-s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //15
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-.s|\n", s_hidden);
  y = ft_printf("yours     ->|%-.s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //16
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%020s|\n", s_hidden);
  y = ft_printf("yours     ->|%020s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //17
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-020s|\n", s_hidden);
  y = ft_printf("yours     ->|%-020s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //18
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%03s|\n", s_hidden);
  y = ft_printf("yours     ->|%03s|\n", s_hidden);
  total += print_result(x, y); index++;//
  //19
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*s|\n", -20, "abc");
  y = ft_printf("yours     ->|%*s|\n", -20, "abc");
  total += print_result(x, y); index++;//
  //20
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-20s|\n", "abc");
  y = ft_printf("yours     ->|%-20s|\n", "abc");
  total += print_result(x, y); index++;//
  //21
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*s|\n", -20, "abc");
  y = ft_printf("yours     ->|%-*s|\n", -20, "abc");
  total += print_result(x, y); index++;//
  //22
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%.*s|\n", -1, "hello");
  y = ft_printf("yours     ->|%.*s|\n", -1, "hello");
  total += print_result(x, y); index++;//
  //23
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%.-3s|\n", "hello");
  y = ft_printf("yours     ->|%.-3s|\n", "hello");
  total += print_result(x, y); index++;//
  //24
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*.*s|\n", -7, -3, "hello");
  y = ft_printf("yours     ->|%-*.*s|\n", -7, -3, "hello");
  total += print_result(x, y); index++;//
  //25
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*.*s|\n", 0, 0, "hello");
  y = ft_printf("yours     ->|%*.*s|\n", 0, 0, "hello");
  total += print_result(x, y); index++;
  //26
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*.*s|\n", 0, 50, "hello");
  y = ft_printf("yours     ->|%*.*s|\n", 0, 50, "hello");
  total += print_result(x, y); index++;
  //27
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*.*s|\n", 10, 0, "hello");
  y = ft_printf("yours     ->|%*.*s|\n", 10, 0, "hello");
  total += print_result(x, y); index++;
  //28
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%.00s|\n", s_hidden);
  y = ft_printf("yours     ->|%-.00s|\n", s_hidden);
  total += print_result(x, y); index++;
  //29
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%16.*s|\n", -64,",8/Jkn.tDZcE");
  y = ft_printf("yours     ->|%16.*s|\n", -64,",8/Jkn.tDZcE");
  total += print_result(x, y); index++;
  //30
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-00s|\n", s_hidden);
  y = ft_printf("yours     ->|%-00s|\n", s_hidden);
  total += print_result(x, y); index++;
  //31
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*.*s|\n", 0, 0, "abcdefghijklmnop");
  y = ft_printf("yours     ->|%-*.*s|\n", 0, 0, "abcdefghijklmnop");
  total += print_result(x, y); index++;
  //32
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%*.*s|\n", 0, 1, "abcdefghijklmnop");
  y = ft_printf("yours     ->|%*.*s|\n", 0, 1, "abcdefghijklmnop");
  total += print_result(x, y); index++;
  //33
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-*.*s|\n", 0, 1, "abcdefghijklmnop");
  y = ft_printf("yours     ->|%-*.*s|\n", 0, 1, "abcdefghijklmnop");
  total += print_result(x, y); index++;
  //34
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-020s|\n", s_hidden);
  y = ft_printf("yours     ->|%-020s|\n", s_hidden);
  total += print_result(x, y); index++;
  //35
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-05s|\n", "pd");
  y = ft_printf("yours     ->|%-05s|\n", "pd");
  total += print_result(x, y); index++;
  //36
  printf("--- test %d ---\n", index);
  x = printf("system    ->|%-0-0-0-0-0-0-0-0-0-0s|\n", "pd");
  y = ft_printf("yours     ->|%-0-0-0-0-0-0-0-0-0-0s|\n", "pd");
  total += print_result(x, y); index++;
  print_total(total, index);
  return 0;
}