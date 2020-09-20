#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
    int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));

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