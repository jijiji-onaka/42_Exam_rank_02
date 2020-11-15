#include <stdio.h>
#include <string.h>
#include "../includes/get_next_line.h"
#include "../includes/color.h"

int ft_printf(char *str, ...);

int main()
{
	int		fd1; // printf
	int		fd2; // ft_printf

	fd1 = open("printf.txt", O_RDONLY);
	fd2 = open("ft_printf.txt", O_RDONLY);

	int		rc;
	char	*line1;
	char	*line2;
	char	*argument;
	char	*your_value;
	char	*real_value;
	int		count = 0;
	int		clear_flag = 0;

	while ((rc = get_next_line(fd1, &line1)) > 0)
	{
		get_next_line(fd2, &line2);
		if (count % 3 == 0)
		{
			argument = strdup(line1);
		}
		else if (count % 3 == 1)
		{
			real_value = strdup(line1);
			your_value = strdup(line2);
		}
		else if (count % 3 == 2)
		{
			int	flag = 0;
			if (strcmp(your_value, real_value) != 0)
				flag += 1;
			if (strcmp(line1, line2) != 0)
				flag += 2;
			if (flag > 0)
			{
				printf(MAGENT);
				printf("%s\n", argument);
				printf(RESET);
				if (flag == 1)
				{
					printf("your_value : [%s]\n", your_value);
					printf("real_value : [%s]\n", real_value);
				}
				else if (flag == 2)
				{
					printf("your_return : [%s]\n", line2);
					printf("real_return : [%s]\n", line1);
				}
				else
				{
					printf("your_value : [%s]\n", your_value);
					printf("your_return : [%s]\n", line2);
					printf("real_value : [%s]\n", real_value);
					printf("real_return : [%s]\n", line1);
				}
				clear_flag = 1;
			}
			free(argument);
			free(your_value);
			free(real_value);
		}
		free(line1);
		free(line2);
		count++;
	}
	if (count % 3 == 0)
		free(line1);
	if (clear_flag == 0)
	{
		printf(GREEN);
		printf("完璧！ちゃんと書けてえらい！！！！\n");
		printf("Examでもこの調子だよん！！");
		printf(RESET);
	}
	else
	{
		printf(RED);
		printf("復習してExam頑張ろう！！");
		printf(RESET);
	}
}
