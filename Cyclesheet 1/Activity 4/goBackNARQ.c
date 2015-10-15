/**
 	Computer Networks - CSE323
 	CYCLE SHEET 1 
 	Question number 4A - Go Back N ARQ

 	BY: Anindit Karmakar

 	TESTED ON WINDOWS. WORKS PERFECTLY.
 	
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
int numPacketsToSend = 0;
int * receivedArray;
int numAck = 0;

int windowLow = 0;
int windowHigh = 4;

void makeWindow() {
	if(numAck == 0) {
		windowLow = 1;
		windowHigh = windowLow + windowSize - 1;
		return;
	}

	windowLow = numAck+1;
	windowHigh = windowLow+ windowSize - 1;

	if (windowHigh > numPacketsToSend) {
		windowHigh = numPacketsToSend;
	}
}

void killPacket(i) {
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
	int i;
	static int killOccured = 0;
	if(killOccured == 1) {
		printf("\nWaiting for next packet acknowledgement...\n");
		millisleep(3000); //simulate wait
		printf("No acknowledgement received. Sending full window again...\n");

		printf("Window %d to %d:\n", windowLow, windowHigh);
		
		for(i=windowLow; i<=windowHigh; i++) {
			sentArray[i] = 0;
			killedArray[i] = 0;

			printf("\nSending packet %d...\n", i);
			sentArray[i] = 1; // packet sent from sender side
			killPacket(i); // ask to kill
		}
		killOccured = 0;
		return;
	}

	printf("Window %d to %d:\n", windowLow, windowHigh);

	for(i=windowLow; i<=windowHigh; i++) {
		if(killedArray[i] == 1) { // if killed packet encountered
			killOccured = 1;
		}

		// if i'th packet unsent, then send it.(Unsent = 0, Sent = 1, Ack = 2)
		if(sentArray[i] == 0) {
			printf("\nSending packet %d...\n", i);
			sentArray[i] = 1; // packet sent from sender side
			killPacket(i); // ask to kill
		}
	}

}

void sendAcknowlegdement(i) {
	sentArray[i] = 2; // record the acknowledgement
	printf("Received acknowledgement for packet %d!\n\n", i);
	millisleep(500); // simulate some delay
	numAck = i;	// Acknowledgement number
}

void receivePackets() {
	int i;
	int killOccured = 0;
	for(i=windowLow; i<=windowHigh; i++) {
		if(killedArray[i] == 1) {
			killOccured = 1;
			break;
		}
		receivedArray[i] = 1;
		printf("\nReceived packet %d!\n", i);
		printf("Sending acknowledgement for packet %d...\n", i);
		
		millisleep(1000);

		sendAcknowlegdement(i);
	}
}

int main(int argc, char * argv[]) {
	printf("Enter number of packets to send: ");
	scanf("%d", &numPacketsToSend);
	CLEARBUF

	sentArray = (int*) calloc(numPacketsToSend+1, sizeof(int));
	receivedArray = (int*) calloc(numPacketsToSend+1, sizeof(int));
	killedArray = (int*) calloc(numPacketsToSend+1, sizeof(int));

	printf("Enter window size: ");
	scanf("%d", &windowSize);
	CLEARBUF

	printf("\n");
	while(numAck != numPacketsToSend) {
		makeWindow();
		sendPackets();
		receivePackets();
	}

	printf("\nSUCCESS! Acknowledgements received: %d\n", numAck);
}