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
	char	*your_output;
	char	*real_output;
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
			real_output = strdup(line1);
			your_output = strdup(line2);
		}
		else if (count % 3 == 2)
		{
			int	flag = 0;
			if (strcmp(your_output, real_output) != 0)
				flag += 1;
			if (strcmp(line1, line2) != 0)
				flag += 2;
			if (flag > 0)
			{
				printf(YELLOW);
				printf("--------------------------------------------------------------------------------------------------------------------------\n");
				printf(RESET);
				printf(MAGENT);
				printf("%s\n", argument);
				printf(RESET);
				if (flag == 1)
				{
					printf("your_output : [%s]\n", your_output);
					printf("real_output : [%s]\n", real_output);
				}
				else if (flag == 2)
				{
					printf("your_return_value : %s\n", line2);
					printf("real_return_value : %s\n", line1);
				}
				else
				{
					printf("your_output : [%s]\n", your_output);
					printf("your_return_value : %s\n", line2);
					printf("real_output : [%s]\n", real_output);
					printf("real_return_value : %s\n", line1);
				}
				printf(YELLOW);
				printf("--------------------------------------------------------------------------------------------------------------------------\n");
				printf(RESET);
				clear_flag = 1;
			}
			free(argument);
			free(your_output);
			free(real_output);
		}
		free(line1);
		free(line2);
		count++;
	}
	if (count % 3 == 0)
		free(line1);
	puts("");
	if (clear_flag == 0)
	{
		printf(GREEN);
		printf("完璧！ちゃんと書けてえらい！！！！\n");
		printf("Examでもこの調子だよん！！\n");
		printf(RESET);
	}
	else
	{
		printf(RED);
		printf("復習してExam頑張ろう！！\n");
		printf(RESET);
	}
	puts("");
}
