#define MAX_FS_TYPES 16

static int __init init_vfat_fs(void)
{
	struct file_system_type *fs_types[MAX_FS_TYPES];
	int num_fs_types = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(fs_types); i++) {
		struct file_system_type *fs_type = file_system_type_by_name["vfat"];
		if (!fs_type)
			break;