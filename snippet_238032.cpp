  void Compute(OpKernelContext* context) override {
    SparseFillEmptyRowsOpImpl<Device, T, Tindex>(context);
  }