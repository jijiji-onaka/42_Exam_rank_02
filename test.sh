cp ./Main/printf.c ./Main/ft_printf.c
sed -i -e "s/printf/ft_printf/" ./Main/ft_printf.c

gcc -fsanitize=address Main/ft_printf.c ft_printf.c -o ft_printf -Wall -Wextra -Werror -lm
gcc -fsanitize=address Main/printf.c -o original
./ft_printf > ft_printf.txt
./original > printf.txt
rm -f ./Main/ft_printf.c-e
gcc -fsanitize=address Dont_touch/main.c Dont_touch/gnl.a -o test -Wall -Werror -Wextra -lm
./test
rm -f ft_printf original ft_printf.txt printf.txt test Main/ft_printf.c