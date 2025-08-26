# get_next_line
## ✨ Features
Function that returns a line read from a file descriptor. 

Libft was not authorized for this project, but most of the utility functions are almost identical to the ones in the library.

> [!TIP]
> ## 🚀 How to use
Run the following commands to clone the repository and run the program, using pre-defined buffer size and amount of file descriptors
``` git
git clone https://github.com/mordori/get_next_line.git get_next_line
cd get_next_line
make
```

To modify the buffer size or amount of open file descriptors, replace `value` with desired amounts. Note that minimum values are BUFFER_SIZE=1 and FD_MAX=3
``` Makefile
make BUFFER_SIZE=value FD_MAX=value
```

To delete all of the compiled files, use
``` Makefile
make fclean
```
