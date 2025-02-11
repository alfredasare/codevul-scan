void user_free_preparse(struct key_preparsed_payload *prep)
{
 if (prep && prep->payload.data[0]) {
 kzfree(prep->payload.data[0]);
 prep->payload.data[0] = NULL;
 }
}