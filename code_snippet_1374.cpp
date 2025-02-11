static int qcow2_get_info(BlockDriverState *bs, BlockDriverInfo *bdi)
{
    BDRVQcowState *s = bs->opaque;
    bdi->unallocated_blocks_are_zero = true;
    uint32_t qcow_version = (uint32_t)s->qcow_version; // Cast to 32-bit integer
    bdi->can_write_zeroes_with_unmap = (qcow_version >= 3);
    bdi->cluster_size = s->cluster_size;
    bdi->vm_state_offset = qcow2_vm_state_offset(s);
    return 0;
}