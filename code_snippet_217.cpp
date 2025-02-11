static int check_map_func_compatibility(struct bpf_map *map, int func_id)
{
	if (!map)
		return 0;

	if (map->map_type == MAP_TYPE_1 && func_id == FUNC_ID_1)
		return 0;

	if (map->map_type == MAP_TYPE_2 && func_id == FUNC_ID_2)
		return 0;

	return -EINVAL;
}