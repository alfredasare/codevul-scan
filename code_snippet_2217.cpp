static void print_maps(struct pid_info_t* info)
{
    FILE *maps;
    size_t offset;
    char device[10];
    long int inode;
    char file[PATH_MAX];
    char safe_format[100];

    snprintf(info->path, sizeof(info->path), "%s%s", info->path, "maps");

    maps = fopen(info->path, "r");

    if (!maps)
        goto out;

    while (fscanf(maps, "%*x-%*x %*s %zx %s %ld %s\n", &offset, device, &inode,
            file) == 4) {
        if (inode == 0 || !strcmp(device, "00:00"))
            continue;

        snprintf(safe_format, sizeof(safe_format), "%%-9s %%5d %%10s %%4s %%9s %%18s %%9zd %%10ld %s\n", file);
        printf(safe_format, info->cmdline, info->pid, info->user, "mem", "???", device, offset, inode);
    }

    fclose(maps);

out:
    info->path[info->parent_length] = '\0';
}