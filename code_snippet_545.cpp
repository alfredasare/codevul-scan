#include <limits>

static void  Ins_ROUND( INS_ARG )
{
  if (std::numeric_limits<decltype(args[0])>::max() - CUR.metrics.compensations[CUR.opcode - 0x6