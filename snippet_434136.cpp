BOOL autodetect_send_connecttime_bandwidth_measure_start(rdpContext* context, UINT16 sequenceNumber)
{
	return autodetect_send_bandwidth_measure_start(context, sequenceNumber,
	                                               RDP_BW_START_REQUEST_TYPE_CONNECTTIME);
}