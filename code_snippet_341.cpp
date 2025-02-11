asmlinkage void do\_tr(struct pt\_regs \*regs)
{
 unsigned int opcode;
 uint16\_t tcode = 0; // Use uint16\_t to limit the maximum value

 if (\_\_get\_user(opcode, (unsigned int <mark>__user</mark>) exception\_epc(regs)))
 goto out\_sigsegv;

 /* Immediate versions don't provide a code. */
 if (!(opcode & OPCODE)) {
 if ((opcode >> 6) > (1 << 10)) { // Check for potential overflow
 goto out\_sigsegv;
 }
 tcode = ((opcode >> 6) & ((1 << 10) - 1));
 }

 do\_trap\_or\_bp(regs, tcode, "Trap");
 return;

out\_sigsegv:
 force\_sig(SIGSEGV, current);
}