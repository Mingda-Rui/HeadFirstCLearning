#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    if (execlp("ipconfig-win", "ipconfig", NULL) == -1) {
        fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));

        // Use execl() because you have the path to the program file.
        if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
         {
            fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));
            return 1;
        }
    }

    return 0;
}