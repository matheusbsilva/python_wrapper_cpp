#include "hello.h"

const char * hello(const char * what) {
    return what;
}

char * hello_robot(const char *str, char * result, int buffersize) {
    snprintf(result, buffersize, "Hello Robot! Hello %s", str);

    return result;
}
