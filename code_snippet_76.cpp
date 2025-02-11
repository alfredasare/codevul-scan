void CL_PacketEvent( netadr_t from, msg_t *msg ) {
    int headerBytes;

    clc.lastPacketTime = cls.realtime;

    if ( msg->cursize >= 4 && *(int *)msg->data == -1 ) {
        CL_ConnectionlessPacket( from, msg );
        return;
    }

    // Validate msg->cursize
    if ( msg->cursize < 0 || msg->cursize > MAX_PACKET_SIZE ) {
        Com_Printf ("%s: Invalid packet size\n", NET_AdrToStringwPort( from ));
        return;
    }

    // Validate msg->data
    if (!msg->data || msg->cursize > strlen(msg->data) ) {
        Com_Printf ("%s: Invalid packet data\n", NET_AdrToStringwPort( from ));
        return;
    }

    if ( clc.state < CA_CONNECTED ) {
        return;	// can't be a valid sequenced packet
    }

    if ( msg->cursize < 4 ) {
        Com_Printf ("%s: Runt packet\n", NET_AdrToStringwPort( from ));
        return;
    }

    if (!NET_CompareAdr( from, clc.netchan.remoteAddress ) ) {
        Com_DPrintf( "%s:sequenced packet without connection\n"
           , NET_AdrToStringwPort( from ) );
        return;
    }

    if (!CL_Netchan_Process( &clc.netchan, msg ) ) {
        return;	// out of order, duplicated, etc
    }

    headerBytes = msg->readcount;

    clc.serverMessageSequence = LittleLong( *(int *)msg->data );

    clc.lastPacketTime = cls.realtime;
    CL_ParseServerMessage( msg );

    if ( clc.demorecording &&!clc.demowaiting ) {
        CL_WriteDemoMessage( msg, headerBytes );
    }
}