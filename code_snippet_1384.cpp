static void handle_binary_protocol_error(conn *c) {
if (c->binary_header.request.opcode > INT16_MAX) {
> write\_bin\_error(c, PROTOCOL\_BINARY\_RESPONSE\_EINVAL, NULL, 0);
> if (settings.verbose) {
> fprintf(stderr, "Invalid opcode (out of bounds), close connection %d\n", c->sfd);
> }
c->write\_and\_go = conn\_closing;
return;
}
write\_bin\_error(c, PROTOCOL\_BINARY\_RESPONSE\_EINVAL, NULL, 0);
if (settings.verbose) {
fprintf(stderr, "Protocol error (opcode %02x), close connection %d\n",
c->binary\_header.request.opcode, c->sfd);
}
c->write\_and\_go = conn\_closing;
}