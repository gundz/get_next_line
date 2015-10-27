make -C libft/
rm -rf ./a.out
gcc -g -Wall -Wextra -Werror -I./ -I libft/includes/ -c get_next_line.c
gcc -g -Wall -Wextra -Werror -I./ -I libft/includes/ -c main.c
gcc -Wall -Werror -Wextra -g get_next_line.o main.o -L libft/ -lft
rm -rf *.o
