#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<unistd.h>
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define ABS(x) (x > 0 ? x : -(x))
#define ll long long

typedef struct	s_flag
{
	int width;
	int dot;
	int dotval;
	int slen;
	int plen;
	char c;
}				t_flag;

static void		_bzero(void *s, size_t n)
{
	char *str = (char *)s;
	size_t i = 0;
	while (i < n)
		str[i++] = '\0';
}

static void		_putchar(char c, t_flag *f)
{
	write(1, &c, 1);
	f->plen++;
}

static void		_putnbr(long long n, t_flag *f)
{
	if (n == 0 && f->dot && !f->dotval) return ;
	int x = (f->c == 'd') ? 10 : 16;
	char *base = (f->c == 'd') ? "0123456789" : "0123456789abcdef";
	if (n >= x)
		_putnbr(n / x, f);
	_putchar(base[n % x], f);
}

static int		_nbrlen(long long n, t_flag *f)
{
	if (n == 0) return (1);
	int x = (f->c == 'd') ? 10 : 16;
	int i = 0;
	while (n != 0)
	{
		n /= x;
		i++;
	}
	return (i);
}

static int		_format(char *fmt, va_list ap, t_flag *f)
{
	int rc = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			while (*fmt >= '0' && *fmt <= '9')
			{
				f->width = f->width * 10 + (*fmt - '0');
				fmt++;
			}
			if (*fmt == '*')
			{
				f->width = va_arg(ap, int);
				fmt++;
			}
			while (*fmt == '.')
			{
				f->dot = 1;
				fmt++;
			}
			while (*fmt >= '0' && *fmt <= '9')
			{
				f->dotval = f->dotval * 10 + (*fmt - '0');
				fmt++;
			}
			if (*fmt == '*')
			{
				f->dotval = va_arg(ap, int);
				if (f->dotval < 0)
					f->dot = f->dotval = 0;
				fmt++;
			}
			if (*fmt == 'd' || *fmt == 'x')
			{
				long long dx;
				if (*fmt == 'd') dx = va_arg(ap, int);
				else dx = va_arg(ap, unsigned int);
				f->c = *fmt;
				f->slen = _nbrlen(dx, f);
				if (f->width >= f->dotval)
				{
					int len = f->slen;
					if (f->dot && f->dotval) len = MAX(f->dotval, len);
					else if (f->dot && !f->dotval && dx == 0) len = 0;
					if (dx < 0 && f->c == 'd') len++;
					int i = 0;
					while (i++ < f->width - len)
						_putchar(' ', f);
					if (dx < 0 && f->c == 'd')
						_putchar('-', f);
					i = 0;
					while (i++ < f->dotval - f->slen)
						_putchar ('0', f);
					_putnbr(ABS(dx), f);
				}
				else
				{
					int len = f->dotval - f->slen;
					if (dx < 0 && f->c == 'd')
						_putchar('-', f);
					int i = 0;
					while (i++ < len)
						_putchar('0', f);
					_putnbr(ABS(dx), f);
				}
			}
			else if (*fmt == 's')
			{
				char *s = va_arg(ap, char *);
				if (!s) s = "(null)";
				while (s[f->slen])
					f->slen++;
				int len = f->slen;
				if (f->dot) len = MIN(f->dotval, len);
				int i = 0;
				while (i++ < f->width - len)
					_putchar(' ', f);
				i = 0;
				while (i < len)
					_putchar(s[i++], f);
			}
			fmt++;
		}
		else
		{
			_putchar(*fmt, f);
			fmt++;
		}
		rc += f->plen;
		_bzero(f, sizeof(t_flag));
	}
	return (rc);
}

int				ft_printf(const char *fmt, ...)
{
	t_flag *f;
	va_list ap;

	if (!(f = malloc(sizeof(t_flag)))) return (-1);
	_bzero(f, sizeof(t_flag));
	va_start(ap, fmt);
	int rc = _format((char*)fmt, ap, f);
	va_end(ap);
	free(f);
	f = NULL;
	return (rc);
}

#ifdef TEST
int main()
{
	int rc = ft_printf("%.0s %.0s %.0s %.0s %.0s", "", "hoge", "12345678910", "42tokyo-tjinichi", NULL);
	int rc2 = printf("%.0s %.0s %.0s %.0s %.0s", "", "hoge", "12345678910", "42tokyo-tjinichi", NULL);
}
#endif
