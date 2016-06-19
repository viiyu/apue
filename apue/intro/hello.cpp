/*
 * Copyright 2015-2020. All rights reserved.
 * Created on: 2016-06-05
 * Author Name: 
 * Author Email:
 */


#include <apue.3e/include/apue.h>
#include "intro/hello.h"

int main() {
    usage();
    printf("hello world from process ID %ld\n", (long)getpid()); // NOLINT
    return 0;
}
