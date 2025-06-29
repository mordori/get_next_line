# get_next_line

> Function that returns a line read from a file descriptor. Libft was not authorized for this project, but most of the utility functions are almost identical to the ones in the library.

> [!NOTE]
> This project was developed and tested using clang on Ubuntu. It will likely work on other Linux distributions and with compatible C/C++ compilers.

> [!TIP]
> ## How to use
 - To compile and run the program in your terminal with the command, using pre-defined buffer size and amount of file descriptors:
 ``` Makefile
 make
 ```
 - To modify the buffer size or amount of open file descriptors, replace `'value'` with desired amounts. Note that minimum values are BUFFER_SIZE=1 and FD_MAX=3. Compile in your terminal with the command:
 ``` Makefile
 make BUFFER_SIZE='value' FD_MAX='value'
 ```
 - To delete all of the compiled files, use:
 ``` Makefile
 make fclean
 ```
