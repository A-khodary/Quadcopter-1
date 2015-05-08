//
// COMMS.H
//
// This file contains the implementation of the communication protcol MAVlink
//

#ifndef comms_h
#define comms_h

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "MAVLink/mavlink.h"

#define BUFFER_LENGTH 2041

class Comms {
	private:
	struct sockaddr_in mGcAddr; 
	struct sockaddr_in mLocAddr;
	
	float mPos[6];
	mavlink_message_t mMsg;
	uint16_t mLen;
	uint8_t mBuf[BUFFER_LENGTH];
	int mBytesSent;
	
	std::string mTargetIP;
	int mSocket;
	
	public:
	Comms();
	
	void init(std::string targetIP);
	void sendHeartbeat();
	void sendStatus();
	
	uint64_t microsSinceEpoch();
};

#endif