static struct dquot **ext2_get_dquots(struct inode *inode)
{
    struct ext2_inode_info *ei = EXT2_I(inode);
    int num_dquots = ei->i_dquot_count; 
    struct dquot **dquots;

    if (num_dquots > 0) {
        dquots = kmalloc_array(num_dquots, sizeof(struct dquot *), GFP_KERNEL);
        if (!dquots) {
            return NULL; 
        }
        dquots[0] = ei->i_dquot; 
        struct dquot *curr = ei->i_dquot;
        for (int i = 1; i < num_dquots; i++) {
            dquots[i] = curr->dq_next; 
            curr = curr->dq_next;
        }
    } else {
        dquots = NULL;
    }

    return dquots;
}