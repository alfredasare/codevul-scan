static void vmsvga\_init(DeviceState \*dev, struct vmsvga\_state\_s \*s,
MemoryRegion \*address\_space, MemoryRegion \*io)
{
s->scratch\_size = SVGA\_SCRATCH\_SIZE;
s->scratch = g\_new0(uint32\_t, s->scratch\_size);

s->vga.con = graphic\_console\_init(dev, 0, &vmsvga\_ops, s);

s->fifo\_size = SVGA\_FIFO\_SIZE;
memory\_region\_init\_ram(&s->fifo\_ram, NULL, "vmsvga.fifo", s->fifo\_size,
&error\_fatal);
vmstate\_register\_ram\_global(&s->fifo\_ram);
s->fifo\_ptr = memory\_region\_get\_ram\_ptr(&s->fifo\_ram);

vga\_common\_init(&s->vga, OBJECT(dev), true);
vga\_init(&s->vga, OBJECT(dev), address\_space, io, true);
vmstate\_register(NULL, 0, &vmstate\_vga\_common, &s->vga);
s->new\_depth = 32;
}