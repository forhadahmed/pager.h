#include <stdio.h>
#include <signal.h>


#define INIT_PAGER        \
    int pgp__ = 0;        \
    void pgk__(int s) {   \
    if (pgp__)            \
    close(1);             \
    }


#define BEGIN_PAGER       \
signal(SIGCHLD,pgk__);    \
    int pager__;          \
    int pipes__[2];       \
    pipe(pipes__);        \
    pgp__ = 1;            \
    pager__ = fork();     \
    if (pager__==0) {     \
    dup2(pipes__[0], 0);  \
    close(pipes__[1]);    \
    char *args__[]=       \
    {"more",0};           \
    execvp(args__[0],     \
    args__);              \
    } else {              \
    int stdout__=dup(1);  \
    dup2(pipes__[1], 1);          
 
 
#define END_PAGER         \
    fflush(stdout);       \
    close(pipes__[0]);    \
    close(pipes__[1]);    \
    close(1);             \
    wait(&pager__);       \
    pgp__ = 0;            \
    dup2(stdout__, 1);    \
    }
 
