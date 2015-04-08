make -C libft/ fclean
make -C libft/
gcc -g -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
gcc -g -Wall -Wextra -Werror -I libft/includes/ -c main.c
gcc -Wall -Werror -Wextra -g -o test_gnl get_next_line.o main.o -L libft/ -lft
rm -rf *.o
