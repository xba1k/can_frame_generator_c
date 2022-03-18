#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include "canbus_util.h"

// Target IP
#define TARGET_IP "192.168.1.255"
// UDP port
#define TARGET_PORT 1080

#define NAME "PacketGen"

int main(int argc, char** argv) {

    struct sockaddr_in si_dest;
    int sock;
    int broadcast = 1;

    struct {
        unsigned int frameId;
        uint8_t frameData[64];
    } __attribute__((packed)) canFrame;

    assert((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) != -1);
    
    // Ideally this shouldn't be a broadcast
    setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof (broadcast));

    memset(&si_dest, 0, sizeof (si_dest));

    si_dest.sin_family = AF_INET;

    // Very optimistic about args being good... 
    if (argc > 1) {
        si_dest.sin_addr.s_addr = inet_addr(argv[1]);
    } else {
        si_dest.sin_addr.s_addr = inet_addr(TARGET_IP);
    }

    if (argc > 2) {
        si_dest.sin_port = htons(atoi(argv[2]));
    } else {
        si_dest.sin_port = htons(TARGET_PORT);
    }

    printf("Starting generator...\n");

    while (1) {

        time_t t = time(NULL);

        // Shuffle the values a bit based on time
        uint8_t *voltageData = make_voltage_frame((48 + t % 2)*10, 100 / (t % 2 + 1), 20 + t % 10);

        canFrame.frameId = SI_VOLTAGE_FRAME;
        memcpy(canFrame.frameData, voltageData, 6);
        free(voltageData);

        if (sendto(sock, &canFrame, 4 + 6, 0, (const struct sockaddr *) &si_dest, sizeof (si_dest)) < 0) {
            perror("sendto");
        }

        canFrame.frameId = SI_NAME_FRAME;
        memcpy(canFrame.frameData, NAME, strlen(NAME));
        if (sendto(sock, &canFrame, 4 + MIN(strlen(NAME), 8), 0, (const struct sockaddr *) &si_dest, sizeof (si_dest)) < 0) {
            perror("sendto");
        }

        printf("%u\n", (int) t);
        sleep(10);

    }

    return (EXIT_SUCCESS);

}
