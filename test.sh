cp ./test/printf.c ./test/ft_printf.c
sed -i -e "s/printf/ft_printf/" ./test/ft_printf.c

gcc -fsanitize=address test/ft_printf.c your_code.c -o ft_printf -Wall -Wextra -Werror -lm
gcc -fsanitize=address test/printf.c -o original
./ft_printf > ft_printf.txt
./original > printf.txt
rm -f ./test/ft_printf.c-e
gcc -fsanitize=address Dont_touch/main.c Dont_touch/gnl.a -o lll -Wall -Werror -Wextra -lm
./lll
rm -f ft_printf original ft_printf.txt printf.txt lll test/ft_printf.c