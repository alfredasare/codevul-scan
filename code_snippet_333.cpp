#include <stdatomic.h>

// Modify the definition of TT_ExecContext
typedef struct TT_ExecContext_tag
{
  // ...
  _Atomic boolean auto_flip;
  // ...
} TT_ExecContext;

void Ins_FLIPOFF(TT_ExecContext* exc)
{
  boolean expected = FALSE;

  // Use atomic compare and exchange to ensure the value is not changed between the check and the update.
  while (!atomic_compare_exchange_weak(&exc->GS.auto_flip, &expected, FALSE))
  {
    // If the value was changed by another thread, try again.
    expected = FALSE;
  }
}