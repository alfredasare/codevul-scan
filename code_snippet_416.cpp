static inline int l2cap\_get\_conf\_opt(void **"ptr**, int \*type, int \*olen, unsigned long \*val)
{
 struct l2cap\_conf\_opt \*opt = \*ptr;
 int len;

 len = L2CAP\_CONF\_OPT\_SIZE + opt->len;
 \*ptr += len;

\*type = opt->type;
\*olen = opt->len;

// Add bounds checking for opt->len
if (opt->len > sizeof(unsigned long)) {
BT\_ERR("Invalid length %d", opt->len);
return -EINVAL;
}

switch (opt->len) {
case 1:
// Casting the val pointer to u8\* is safe since opt->len is checked
\*val = \*((u8 \*) opt->val);
break;

case 2:
// Casting the val pointer to __le16\* is safe since opt->len is checked
\*val = __le16\_to\_cpu(\*((__le16 \*) opt->val));
break;

case 4:
// Casting the val pointer to __le32\* is safe since opt->len is checked
\*val = __le32\_to\_cpu(\*((__le32 \*) opt->val));
break;

default:
\*val = (unsigned long) opt->val;
break;
}

BT\_DBG("type 0x%2.2x len %d val 0x%lx", \*type, opt->len, \*val);
return len;
}