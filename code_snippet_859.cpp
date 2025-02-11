void onig_region_init(OnigRegion* region)
{
  region->num_regs = 0;
  region->allocated = 0;
  region->beg = NULL;
  region->end = NULL;
  region->history_root = NULL;
}