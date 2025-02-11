static struct sock *udp_get_idx(struct seq_file *seq, loff_t pos)
{
    struct sock *sk = udp_get_first(seq, 0);

    if (sk) {
        if (pos <= 0)
            return sk;
        while (pos > 1 && (sk = udp_get_next(seq, sk))!= NULL)
            --pos;
    }
    return pos == 0? sk : NULL;
}