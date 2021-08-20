//
//
#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include "iw_list.h"
#include "joint.cpp"

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

void iw_list::merge(int *fd_one, int *fd_two, int *joint) {
    //here we check if either of the file descriptors referred to by the join are used
    //one tricky thing we can do is assign negative numbers that correspond to the index of the joint in the joint array
    //file descriptors are unilaterally positive, so we need not worry about that
    joint j = new joint(*fd_one, *fd_two);
    //will need to add one to the negative index for 0
    for(int i = 0; i<size; i++){
        if(pipes[i]==*fd_one||pipes[i]==*fd_two){
            pipes[i]=-1*(j_size+1);
        }
    }
    realloc(joints, sizeof(joint)*j_size+1);
    joints[j_size]=j;
}

void iw_list::open(int *connection) {
    realloc(recv, sizeof(int)*(size+1))
    realloc(pipes, sizeof(int)*(size+1))
    pipes[size]=*connection;
    recv[size]= nullptr
    size++;
}