opt->seq_sent > ULONG_MAX ||
opt->seq_recv < ULONG_MAX - 1 ||
opt->seq_recv > ULONG_MAX ||
opt->ack_recv < 0 ||
opt->ack_recv > ULONG_MAX ||
opt->ack_sent < 0 ||
opt->ack_sent > ULONG_MAX) {
goto out_free_sk;
}

opt->seq_sent = 0; opt->seq_recv = ULONG_MAX - 1;
opt->ack_recv = 0; opt->ack_sent = ULONG_MAX;

error = 0;
out:
return error;

out_free_sk:
sk_free(sk);
goto out;
}