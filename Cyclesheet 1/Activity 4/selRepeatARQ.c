/**
 	Computer Networks - CSE323
 	CYCLE SHEET 1 
 	Question number 4B - Selective Repeat ARQ

 	BY: Anindit Karmakar

 	TESTED ON WINDOWS. WORKS NICE
 	
 	WORKS PERFECTLY ON LINUX (Ubuntu 14.04)
 	with gcc 4.8.2
 */

#include <stdio.h>
#include <stdlib.h>

#define CLEARBUF while(getchar()!='\n');


#ifdef __unix
	#include <unistd.h>
#elif __WIN32
	#include <windows.h>
#endif


int millisleep(unsigned ms)
{
#ifdef _WIN32
	SetLastError(0);
	Sleep(ms);
	return GetLastError() ?-1 :0;
#elif __unix
	return usleep(1000 * ms);
#else
	printf("error..");
	return -1;
#endif
}

int windowSize = 5;
int * sentArray;
int * killedArray;
int * receivedArray;
int sendWindowLow = 1;
int sendWindowHigh = 5;
int rcvWindowLow = 1;
int rcvWindowHigh = 5;
int numAck = 0;
int numRcvd = 0;
int numPacketsToSend = 0;

void makeWindow(int * array, int * low, int * high) {
	int i;
	// find the first packet not completely sent (with acknowledment) 
	// or not completely received. [array[i] == 2 means that packet is done]
	for(i=1;i<=numPacketsToSend;i++) {
		if(array[i] != 2) 
			break;
	}

	*low = i;
	*high = i + windowSize - 1;

	if(*high > numPacketsToSend)
		*high = numPacketsToSend;
}

void killPacket(int i) {
	char ch;
	printf("Kill packet %d? (y/n): ", i);
	scanf("%c", &ch);
	CLEARBUF

	if(ch == 'y' || ch == 'Y') // if packet should be killed 
	{
		killedArray[i] = 1; // packet killed
	}
}

void sendPackets() {
	// update the sender side window
	makeWindow(sentArray, &sendWindowLow, &sendWindowHigh);
	int i;
	static int killOccurred = 0; // whether any packet in current window was lost/killed

	// to check for killed packets
	for(i=sendWindowLow; i<=sendWindowHigh; i++) {
		if(killedArray[i] == 1) {
			killOccurred = 1;
		}
	}

	// if there are killed packets
	if(killOccurred == 1) {
		// simulate waiting for acknowledgement of killed packets.
		printf("Waiting for acknowledgement of remaining packets...\n");
		millisleep(3000);
		printf("No acknowledgement received. Sending killed packets again...\n");

		// send only the killed packets again. (Unlike Go Back N which sends all
		// packets in current window)
		for(i=sendWindowLow; i<=sendWindowHigh; i++) {
			// sentArray[i] == 1 means packets which are sent but no
			// acknowledgement received
			if(sentArray[i] == 1) { 
				killedArray[i] = 0;
				printf("Sending packet %d...\n", i);
				killPacket(i);
				sentArray[i] = 1;
			}
		}

		// reset the kill indicator;
		killOccurred = 0;
		return;
	}

	// if no kill has occured. Fresh window.
	// send the packets in the window
	for(i=sendWindowLow; i<=sendWindowHigh; i++) {
		printf("Sending packet %d...\n", i);
		killPacket(i);
		sentArray[i] = 1;
	}
}

void acknowledge(int i) {
	sentArray[i] = 2; // record the acknowledgement
	printf("Received Acknowledgement for packet %d!\n", i);
	numAck++;

	// update the sender side window
	makeWindow(sentArray, &sendWindowLow, &sendWindowHigh);
}

void receivePackets() {

	// update the receiver side window
	makeWindow(receivedArray, &rcvWindowLow, &rcvWindowHigh);
	int i;
	int killOccurred = 0;

	for(i=rcvWindowLow; i<=rcvWindowHigh; i++) {

		// if a packet has been killed, do not receive it.
		if(killedArray[i] == 1) {
			killOccurred = 1;
			continue;
		}

		// else, receive and send back acknowledgement
		if(receivedArray[i] == 0) {
			receivedArray[i] = 1;
			millisleep(500);
			printf("Received packet %d!\n", i);
			printf("Sending acknowledgement for packet %d...\n", i);
			acknowledge(i);
			receivedArray[i] = 2;
			numRcvd++;
		}
	}
}

int main(int argc, char * argv[]) {
	printf("Enter number of packets to send: ");
	scanf("%d", &numPacketsToSend);
	CLEARBUF

	printf("Enter window size: ");
	scanf("%d", &windowSize);
	CLEARBUF

	sentArray = (int*) calloc(numPacketsToSend+1, sizeof(int));
	killedArray = (int*) calloc(numPacketsToSend+1, sizeof(int));
	receivedArray = (int*) calloc(numPacketsToSend+1, sizeof(int));

	while(numAck != numPacketsToSend) {
		sendPackets();
		receivePackets();
	}
}