static void write\_ecryptfs\_marker(char \*page\_virt, size\_t \*written)
{
 u64 m\_1, m\_2;

 get\_random\_bytes(&m\_1, sizeof(m\_1));
 m\_2 = (m\_1 ^ MAGIC\_ECRYPTFS\_MARKER);
 put\_unaligned\_be64(m\_1, page\_virt);
 page\_virt += sizeof(m\_1);
 put\_unaligned\_be64(m\_2, page\_virt);
 (*written) = sizeof(m\_1) \* 2;
}