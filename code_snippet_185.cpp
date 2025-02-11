static void pmcraid_internal_done(struct pmcraid_cmd *cmd)
{
    u32 cdb_len = sizeof(cmd->ioa_cb->ioarcb.cdb) / sizeof(cmd->ioa_cb->ioarcb.cdb[0]);

    pmcraid_info("response internal cmd CDB[0] = %x ioasc = %x\n",
                 (cdb_len > 0)? cmd->ioa_cb->ioarcb.cdb[0] : 0,
                 le32_to_cpu(cmd->ioa_cb->ioasa.ioasc));
   ...
}