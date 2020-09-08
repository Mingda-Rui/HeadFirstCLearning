#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
    FILE *f = fopen("./src/stories.txt", "w");
    if (!f) {
        error("Can't open stories.txt");
    }
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    if (!pid) {
        // This points descriptor #1 to the stories.txt file.
        if(dup2(fileno(f),1) == -1) {
            error("Can't redirect Standard Output");
        }
        if(dup2(fileno(f),2) == -1) {
            error("Can't redirect Standard Output");
        }
        if (execle("/usr/bin/python", "python", "./rssgossip.py", phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }

    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("Error waiting for child process");
    }
    return 0;
}