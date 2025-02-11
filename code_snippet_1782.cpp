init\_cell\_pool(void)
{
  tor\_assert(!cell\_pool);
  cell\_pool = mp\_pool\_new(sizeof(packed\_cell\_t), DEFAULT\_CELL\_POOL\_SIZE);
}

// Define DEFAULT\_CELL\_POOL\_SIZE in a configuration header or build system.