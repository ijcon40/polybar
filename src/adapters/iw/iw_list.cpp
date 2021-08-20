//
// Created by ijcon on 8/19/2021.
//

#include "iw_list.h"

iw_list::iw_list(int init) {
    pipes = {&init};
    recv = {nullptr};
}

iw_list::iw_list() {
    pipes = nullptr;
    recv = nullptr;
}

void iw_list::close(int *fd_pointer) {
    //find the location in the pipes that matches the pointer
    for(int i = 0; i<size; i++){
        if(pipes[i]==*fd_pointer){
            int loc = i;
            for(int j = i+1; j<size; j++){
                pipes[loc]=pipes[j];
                recv[loc]=recv[j];
                loc=j;
            }
        }
    }
    pipes[size]= nullptr;
    recv[size]= nullptr;
    size--;
}

bool iw_list::append(int *connection) {
    realloc( pipes, sizeof(int)*size+1);
    realloc( recv, sizeof(int)*size+1)
    pipes[size+1]=connection;
    recv[size+1]=nullptr;
    size+=1;
}