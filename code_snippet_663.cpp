void echoCommand(client *c) {
    addReplyLen(c, c->argv[1]->len, c->argv[1]->ptr);
}