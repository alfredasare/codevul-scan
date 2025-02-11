static struct task *h2\_timeout\_task(struct task *t){
if (t == NULL) {
return NULL;
}
struct h2c *h2c = t->context;
int expired = tick\_is\_expired(t->expire, now\_ms);

if (!expired && h2c)
return t;

task\_delete(t);
task\_free(t);

if (!h2c) {
/* resources were already deleted */
return NULL;
}

h2c->task = NULL;
h2c\_error(h2c, H2\_ERR\_NO\_ERROR);
h2\_wake\_some\_streams(h2c, 0, 0);

if (h2c->mbuf->o) {
/* don't even try to send a GOAWAY, the buffer is stuck */
h2c->flags |= H2\_CF\_GOAWAY\_FAILED;
}

/* try to send but no need to insist */
h2c->last\_sid = h2c->max\_id;
if (h2c\_send\_goaway\_error(h2c, NULL) <= 0)
h2c->flags |= H2\_CF\_GOAWAY\_FAILED;

if (h2c->mbuf->o && !(h2c->flags & H2\_CF\_GOAWAY\_FAILED) && conn\_xprt\_ready(h2c->conn))
h2c->conn->xprt->snd\_buf(h2c->conn, h2c->mbuf, 0);

/* either we can release everything now or it will be done later once
* the last stream closes.
*/
if (eb\_is\_empty(&h2c->streams\_by\_id))
h2\_release(h2c->conn);

return NULL;
}