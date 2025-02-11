#include <stdatomic.h>

static void lsi_stop_script(LSIState *s)
{
    atomic_fetch_and(&s->istat1, ~LSI_ISTAT1_SRUN);
}