smb_ofile_t* smb_ofile_close_and_next(smb_ofile_t* of)
{
    smb_ofile_t* next_of = NULL;
    smb_tree_t* tree;

    if (of == NULL || of->f_magic!= SMB_OFILE_MAGIC) {
        return NULL; // or some error code
    }

    mutex_enter(&of->f_mutex);
    switch (of->f_state) {
        case SMB_OFILE_STATE_OPEN:
            //...
            break;
        case SMB_OFILE_STATE_CLOSING:
        case SMB_OFILE_STATE_CLOSED:
            next_of = smb_llist_next(&of->f_tree->t_ofile_list, of);
            if (next_of == NULL) {
                return NULL; // or some error code
            }
            break;
        default:
            ASSERT(0);
            //...
            break;
    }
    mutex_exit(&of->f_mutex);
    return next_of;
}