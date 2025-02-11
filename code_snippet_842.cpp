void radeon_restore_bios_scratch_regs(struct radeon_device *rdev)
{
    uint32_t scratch_reg;
    int i;
    size_t scratch_len = sizeof(rdev->bios_scratch) / sizeof(rdev->bios_scratch[0]);

    if (rdev->family >= CHIP_R600)
        scratch_reg = R600_BIOS_0_SCRATCH;
    else
        scratch_reg = RADEON_BIOS_0_SCRATCH;

    for (i = 0; i < scratch_len; i++) {
        if (i * 4 + sizeof(rdev->bios_scratch[0]) > sizeof(rdev->bios_scratch)) {
            // Handle error or truncation
        }
        memcpy((void *) (scratch_reg + (i * 4)), &rdev->bios_scratch[i], sizeof(rdev->bios_scratch[0]));
    }
}