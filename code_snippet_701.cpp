#include <linux/random.h>

static int ptype_seq_open(struct inode *inode, struct file *file)
{
    struct seq_net_private *private;

    private = kmalloc(sizeof(struct seq_net_private), GFP_KERNEL);
    if (!private)
        return -ENOMEM;

    // Initialize private structure with randomness
    get_random_bytes(&private->seq, sizeof(private->seq));

    return seq_open_net(inode, file, &ptype_seq_ops, sizeof(struct seq_net_private));
}