void MojoVideoEncodeAcceleratorService::BitstreamBufferReady(
int32_t bitstream_buffer_id,
size_t payload_size,
bool key\_frame,
base::TimeDelta timestamp) {
if (bitstream\_buffer\_id < 0 || payload\_size > MAX\_PAYLOAD\_SIZE ||
!vea\_client\_) {
return;
}
DVLOG(2) << __func__ << " bitstream\_buffer\_id=" << bitstream\_buffer\_id
<< ", payload\_size=" << payload\_size
<< "B, key\_frame=" << key\_frame;
vea\_client-\>BitstreamBufferReady(bitstream\_buffer\_id, payload\_size,
key\_frame, timestamp);
}