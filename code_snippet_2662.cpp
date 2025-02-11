int max\_iterations = MIN(4, sizeof(dev\_priv->ring[RCS].buffer) / sizeof(dev\_priv->ring[RCS].buffer[0]));
for (i = 0; i < max\_iterations; i++) {
        intel\_ring\_emit(ring, MI\_LOAD\_REGISTER\_IMM(1));
        intel\_ring\_emit(ring, GEN7\_SO\_WRITE\_OFFSET(i));
        intel\_ring\_emit(ring, 0);
}