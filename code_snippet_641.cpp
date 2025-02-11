arcmsr\_Read\_iop\_rqbuffer\_in\_DWORD(struct AdapterControlBlock \*acb,
 struct QBUFFER \_\_iomem \*prbuffer)
{
 uint8\_t \*pQbuffer;
 uint8\_t \*buf1 = NULL;
 uint32\_t \_\_iomem \*iop\_data;
 uint32\_t iop\_len, data\_len, \*buf2 = NULL;

 iop\_data = (uint32\_t \_\_iomem \*)prbuffer->data;
 iop\_len = readl(&prbuffer->data\_len);
 if (iop\_len > 0) {
 buf1 = kmalloc(128, GFP\_ATOMIC);
 buf2 = (uint32\_t \*)buf1;
 if (buf1 == NULL)
 return 0;
 data\_len = iop\_len;
 while (data\_len >= 4 && acb->rqbuf\_putIndex < ARCMSR\_MAX\_QBUFFER) {
 \*buf2++ = readl(iop\_data);
 iop\_data++;
 data\_len -= 4;
 acb->rqbuf\_putIndex++;
 }
 if (data\_len)
 \*buf2 = readl(iop\_data);
 buf2 = (uint32\_t \*)buf1;
 }
 while (iop\_len > 0 && acb->rqbuf\_putIndex < ARCMSR\_MAX\_QBUFFER) {
 pQbuffer = &acb->rqbuffer[acb->rqbuf\_putIndex];
 \*pQbuffer = *buf1;
 acb->rqbuf\_putIndex++;
 /* if last, index number set it to 0 */
 acb->rqbuf\_putIndex %= ARCMSR\_MAX\_QBUFFER;
 buf1++;
 iop\_len--;
 }
 kfree(buf2);
 /* let IOP know data has been read */
 arcmsr\_iop\_message\_read(acb);
 return 1;
}