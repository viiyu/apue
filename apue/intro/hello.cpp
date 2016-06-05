/*
 * Copyright 2015-2020. All rights reserved.
 * Created on: 2016-06-05
 * Author Name: ViYu
 * Author Email: cyan.yui@gmail.com
 */


#include <apue.3e/include/apue.h>

#include "hello.h"

int main() {
    usage();
    printf("hello world from process ID %ld\n", (long)getpid());
    return 0;
}
