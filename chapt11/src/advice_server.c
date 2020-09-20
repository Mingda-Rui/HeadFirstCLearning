#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void error(char *msg);

int main(int argc, char *argv[])
{
    char *advice[] ={
        "Take smaller bites\r\n",
        "Go for the tight jeans. No they do NOT make you look fat.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think\r\n",
        "You might want to rethink that haircut\r\n"
    };

    // listenre_d is a descriptor for the socket, it's an internet socket
    // This is a protocol number.  You can leave it as 0.
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    // if (listener_d == -1)
    //     error("Cann't open socket");

    // 1. bind to a port
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    // When you bind a socket to a port, the operating system will
    // prevent anything else from rebinding to it for the next 30
    // seconds or so, and that includes the program that bound the port
    // in the first place. To get around the problem, you just need to set
    // an potion on the socket before you bind it:
    // You need an int variable to store the option.
    // Setting it to 1 means "Yes, reuse the port."
    int reuse = 1;
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");

    if( bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1 )
        error("Can't bind the port");

    // 2. listen
    // if (listen(listener_d, 10) == -1
    //     error("Can't listen");
    // You'll use a queue with a length of 10.
    listen(listener_d, 10);
    puts("Waiting for connection");

    // You need to loop the accept/begin talking section.
    while(1) {
        // 3. accept a connection
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        // This new connection descriptor (connect_d) is the one that the server will use to...
        int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
        char *msg = advice[rand() % 5];

        // Begin talking to the client.
        send(connect_d, msg, strlen(msg), 0);
        close(connect_d);
    }
    return 0;
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}