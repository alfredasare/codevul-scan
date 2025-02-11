int is_file_shm_hugepages(struct file *file)
{
    struct file_operations *allowed_ops[] = {
        &shm_file_operations_huge,
        // Add more allowed operations here
    };

    int i;
    for (i = 0; i < ARRAY_SIZE(allowed_ops); i++) {
        if (file->f_op == allowed_ops[i]) {
            return 1;
        }
    }

    return 0; // File operation is not allowed
}