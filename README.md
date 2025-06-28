# get_next_line

> Function that returns a line read from a file descriptor. Libft was not authorized for this project, but most of the utility functions are almost identical to the ones in the library.

> [!NOTE]
> This project was developed and compiled using clang on Ubuntu. It will likely work on other Linux distributions and with compatible C/C++ compilers, but clang on Ubuntu is the environment it was originally built and tested in.

> [!TIP]
> ## How to use
 - To compile and run the tests in your terminal with the command, using pre-defined buffer size and amount of file descriptors:
 ``` Makefile
 make
 ```
 - To modify the buffer size or amount of open file descriptors, replace `'value'` with desired amounts and compile in your terminal with the command:
 ``` Makefile
 cc -g -Wall -Wextra -Werror src/get_next_line_bonus.c src/get_next_line_utils_bonus.c main.c \
-D BUFFER_SIZE='value' -D FD_MAX='value' && ./a.out
 ```
 - To delete all of the compiled files, use:
 ``` Makefile
 make fclean
 ```
