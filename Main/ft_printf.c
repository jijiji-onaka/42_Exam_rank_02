#include <stdio.h>
#include "../includes/color.h"

void	argument(char *str)
{
	ft_printf("argument[printf(\"%s\")]\n", str);
}
void	argument_s(char *str)
{
	if (str == NULL)
		str = "NULL";
	ft_printf("argument[printf(\"%%s\", \"%s\")]\n", str);
}
void	argument_d(char *str)
{
	ft_printf("argument[printf(\"%%d\",\"%s\")]\n", str);
}
void	argument_x(char *str)
{
	ft_printf("argument[printf(\"%%x\",\"%s\")]\n", str);
}

# define ARG(x) argument(x)
# define ARG_S(x) argument_s(x)
# define ARG_D(x) argument_d(x)
# define ARG_X(x) argument_x(x)

int			main(void)
{
	int rc = 0;

	ARG("Simple_test");
	rc = ft_printf("Simple_test");
	ft_printf("\n%d\n", rc);

	ARG("");
	rc = ft_printf("");
	ft_printf("\n%d\n", rc);

	ARG_D("0");
	rc = ft_printf("%d", 0);
	ft_printf("\n%d\n", rc);

	ARG_D("42");
	rc = ft_printf("%d", 42);
	ft_printf("\n%d\n", rc);

	ARG_D("1");
	rc = ft_printf("%d", 1);
	ft_printf("\n%d\n", rc);

	ARG_D("5454");
	rc = ft_printf("%d", 5454);
	ft_printf("\n%d\n", rc);

	ARG_D("(int)2147483647");
	rc = ft_printf("%d", (int)2147483647);
	ft_printf("\n%d\n", rc);

	ARG_D("(int)2147483648");
	rc = ft_printf("%d", (int)2147483648);
	ft_printf("\n%d\n", rc);

	ARG_D("(int)-2147483648");
	rc = ft_printf("%d", (int)-2147483648);
	ft_printf("\n%d\n", rc);

	ARG_D("(int)-2147483649");
	rc = ft_printf("%d", (int)-2147483649);
	ft_printf("\n%d\n", rc);
//---------------------------------------
	ARG_X("0");
	rc = ft_printf("%x", 0);
	ft_printf("\n%d\n", rc);

	ARG_X("42");
	rc = ft_printf("%x", 42);
	ft_printf("\n%d\n", rc);

	ARG_X("1");
	rc = ft_printf("%x", 1);
	ft_printf("\n%d\n", rc);

	ARG_X("5454");
	rc = ft_printf("%x", 5454);
	ft_printf("\n%d\n", rc);

	ARG_X("(int)2147483647");
	rc = ft_printf("%x", (int)2147483647);
	ft_printf("\n%d\n", rc);

	ARG_X("(int)2147483648");
	rc = ft_printf("%x", (int)2147483648);
	ft_printf("\n%d\n", rc);

	ARG_X("(int)-2147483648");
	rc = ft_printf("%x", (int)-2147483648);
	ft_printf("\n%d\n", rc);

	ARG_X("(int)-2147483649");
	rc = ft_printf("%x", (int)-2147483649);
	ft_printf("\n%d\n", rc);
//-----------------------------------------
	ARG_S("");
	rc = ft_printf("%s", "");
	ft_printf("\n%d\n", rc);

	ARG_S("hoge");
	rc = ft_printf("%s", "hoge");
	ft_printf("\n%d\n", rc);

	ARG_S("42tokyo-tjinichi");
	rc = ft_printf("%s", "42tokyo-tjinichi");
	ft_printf("\n%d\n", rc);

	ARG_S(NULL);
	rc = ft_printf("%s", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%s-%%s-%%s-%%s\", \"\", \"hoge\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%s-%s-%s-%s", "", "hoge", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);


	ft_printf("argument[printf(\"%%d%%x%%d%%x%%d%%x%%d%%x\", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648)]\n");
	rc = ft_printf("%d%x%d%x%d%x%d%x", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(-\"%%d-%%x-%%d-%%x-%%d-%%x-%%d-%%x\", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648)]\n");
	rc = ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%s%%s%%s%%s\", \"\", \"hoge\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%s%s%s%s", "", "hoge", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%0d %%0d %%0d %%0d %%0d %%0d %%0d %%0d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%0d %0d %0d %0d %0d %0d %0d %0d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4d %%4d %%4d %%4d %%4d %%4d %%4d %%4d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4d %4d %4d %4d %4d %4d %4d %4d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10d %%10d %%10d %%10d %%10d %%10d %%10d %%10d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10d %10d %10d %10d %10d %10d %10d %10d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.0d %%.0d %%.0d %%.0d %%.0d %%.0d %%.0d %%.0d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.0d %.0d %.0d %.0d %.0d %.0d %.0d %.0d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.4d %%.4d %%.4d %%.4d %%.4d %%.4d %%.4d %%.4d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.10d %%.10d %%.10d %%.10d %%.10d %%.10d %%.10d %%.10d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.10d %.10d %.10d %.10d %.10d %.10d %.10d %.10d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);
//------------------------------------------
	ft_printf("argument[printf(\"%%0x %%0x %%0x %%0x %%0x %%0x %%0x %%0x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%0x %0x %0x %0x %0x %0x %0x %0x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4x %%4x %%4x %%4x %%4x %%4x %%4x %%4x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4x %4x %4x %4x %4x %4x %4x %4x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10x %%10x %%10x %%10x %%10x %%10x %%10x %%10x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10x %10x %10x %10x %10x %10x %10x %10x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.0x %%.0x %%.0x %%.0x %%.0x %%.0x %%.0x %%.0x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.0x %.0x %.0x %.0x %.0x %.0x %.0x %.0x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.4x %%.4x %%.4x %%.4x %%.4x %%.4x %%.4x %%.4x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.4x %.4x %.4x %.4x %.4x %.4x %.4x %.4x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.10x %%.10x %%.10x %%.10x %%.10x %%.10x %%.10x %%.10x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%.10x %.10x %.10x %.10x %.10x %.10x %.10x %.10x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);
//----------------------------------------------------

	ft_printf("argument[printf(\"%%4s %%4s %%4s %%4s %%4s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%4s %4s %4s %4s %4s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10s %%10s %%10s %%10s %%10s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%10s %10s %10s %10s %10s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.0s %%.0s %%.0s %%.0s %%.0s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%.0s %.0s %.0s %.0s %.0s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.4s %%.4s %%.4s %%.4s %%.4s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%.4s %.4s %.4s %.4s %.4s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%.10s %%.10s %%.10s %%.10s %%.10s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%.10s %.10s %.10s %.10s %.10s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\" %%0.0d %%0.0d %%0.0d %%0.0d %%0.0d %%0.0d %%0.0d %%0.0d\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\" %%0.0x %%0.0x %%0.0x %%0.0x %%0.0x %%0.0x %%0.0x %%0.0x\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%0.4d %%0.4d %%0.4d %%0.4d %%0.4d %%0.4d %%0.4d %%0.4d\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%0.10d %%0.10d %%0.10d %%0.10d %%0.10d %%0.10d %%0.10d %%0.10d\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%0.4x %%0.4x %%0.4x %%0.4x %%0.4x %%0.4x %%0.4x %%0.4x\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%0.10x %%0.10x %%0.10x %%0.10x %%0.10x %%0.10x %%0.10x %%0.10x\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.0d %%4.0d %%4.0d %%4.0d %%4.0d %%4.0d %%4.0d %%4.0d\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.0d %%10.0d %%10.0d %%10.0d %%10.0d %%10.0d %%10.0d %%10.0d\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.0x %%4.0x %%4.0x %%4.0x %%4.0x %%4.0x %%4.0x %%4.0x\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.0x %%10.0x %%10.0x %%10.0x %%10.0x %%10.0x %%10.0x %%10.0x\", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf(" %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"-%%4.s-%%4.s-%%4.s-%%4.s-%%4.s\", \"\", \"hoge\", \"01234567910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("-%4.s-%4.s-%4.s-%4.s-%4.s", "", "hoge", "01234567910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"-%%10.s-%%10.s-%%10.s-%%10.s-%%10.s\", \"\", \"hoge\", \"01234567910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("-%10.s-%10.s-%10.s-%10.s-%10.s", "", "hoge", "01234567910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.4d %%10.4d %%10.4d %%10.4d %%10.4d %%10.4d %%10.4d %%10.4d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.10d %%10.10d %%10.10d %%10.10d %%10.10d %%10.10d %%10.10d %%10.10d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.4d %%4.4d %%4.4d %%4.4d %%4.4d %%4.4d %%4.4d %%4.4d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.10d %%4.10d %%4.10d %%4.10d %%4.10d %%4.10d %%4.10d %%4.10d\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);
//----------------------
	ft_printf("argument[printf(\"%%10.4x %%10.4x %%10.4x %%10.4x %%10.4x %%10.4x %%10.4x %%10.4x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.10x %%10.10x %%10.10x %%10.10x %%10.10x %%10.10x %%10.10x %%10.10x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.4x %%4.4x %%4.4x %%4.4x %%4.4x %%4.4x %%4.4x %%4.4x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.10x %%4.10x %%4.10x %%4.10x %%4.10x %%4.10x %%4.10x %%4.10x\", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649)]\n");
	rc = ft_printf("%4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x", 0, 42, 1, 5454, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	ft_printf("\n%d\n", rc);
//----------------------------

	ft_printf("argument[printf(\"%%10.4s %%10.4s %%10.4s %%10.4s %%10.4s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%10.4s %10.4s %10.4s %10.4s %10.4s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.10s %%10.10s %%10.10s %%10.10s %%10.10s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%10.10s %10.10s %10.10s %10.10s %10.10s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%10.10s %%10.10s %%10.10s %%10.10s %%10.10s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%10.10s %10.10s %10.10s %10.10s %10.10s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

	ft_printf("argument[printf(\"%%4.4s %%4.4s %%4.4s %%4.4s %%4.4s\", \"\", \"hoge\", \"12345678910\", \"42tokyo-tjinichi\", NULL)]\n");
	rc = ft_printf("%4.4s %4.4s %4.4s %4.4s %4.4s", "", "hoge", "122345678910", "42tokyo-tjinichi", NULL);
	ft_printf("\n%d\n", rc);

}
