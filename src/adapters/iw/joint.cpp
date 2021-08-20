#include <net/net_io.hpp>
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */

class joint{
private:
    int fd_one;
    int fd_two;
public:
    joint(int _fd_one, int _fd_two):fd_one(_fd_one), fd_two(_fd_two){}

    int either(){
        return net_read(fd_one)|| net_read(fd_two);
    }
};