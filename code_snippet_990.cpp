bool asn1_read_BOOLEAN_context(struct asn1_data *data, bool *v, int context)
{
 uint8_t tmp = 0;
 asn1_start_tag(data, ASN1_CONTEXT_SIMPLE(context));

 if (data->length > 1) { // Add length check
 asn1_read_uint8(data, &tmp);
 } else {
 // Handle error case for incorrect length
 data->has_error = true;
 return data->has_error;
 }

 if (tmp == 0xFF) {
 *v = true;
 } else {
 *v = false;
 }
 asn1_end_tag(data);
 return !data->has_error;
}