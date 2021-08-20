//
//

#ifndef POLYBAR_IW_LIST_H
#define POLYBAR_IW_LIST_H


class iw_list {
private:
    int * recv;
    int * pipes;
    int size = 0;
    joint * joints;
    int j_size = 0;


public:
    iw_list(int)
    iw_list():recv(nullptr),pipes(nullptr){}

    void list(int * fd_pointer)

    void close(int * fd_pointer)

    void open(int * connection)

    bool append(int * connection)

    void merge(int * fd_one, int * fd_two, int * joint)
};


#endif //POLYBAR_IW_LIST_H
