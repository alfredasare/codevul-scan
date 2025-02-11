void CL\_PacketEvent( netadr\_t from, msg\_t \*msg ) {
	int	headerBytes;

	clc.lastPacketTime = cls.realtime;

	if ( msg->cursize >= 4 && *(int *)msg->data == -1 ) {
		CL\_ConnectionlessPacket( from, msg );
		return;
	}

	if ( clc.state < CA\_CONNECTED ) {
		return;	// can't be a valid sequenced packet
	}

	if ( msg->cursize < 4 ) {
		Com\_Printf ("%s: Runt packet\n", NET\_AdrToStringwPort( from ));
		return;
	}

	if ( !NET\_CompareAdr( from, clc.netchan.remoteAddress ) ) {
		Com\_DPrintf( "%s:sequenced packet without connection\n"
			, NET\_AdrToStringwPort( from ) );
		return;
	}

	if ( !CL\_Netchan\_Process( &clc.netchan, msg ) ) {
		return;	// out of order, duplicated, etc
	}

	// Fix: Check for integer overflow before using the value
	if (msg->cursize - headerBytes > INT\_MAX || msg->cursize - headerBytes < 0) {
		Com_Printf("Error: Integer overflow detected in message data\n");
		return;
	}

	headerBytes = msg->readcount;

	clc.serverMessageSequence = LittleLong( *(int \*)msg->data );

	clc.lastPacketTime = cls.realtime;
	CL\_ParseServerMessage( msg );

	if ( clc.demorecording && !clc.demowaiting ) {
		CL\_WriteDemoMessage( msg, headerBytes );
	}
}