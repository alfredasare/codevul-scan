bool btif\_get\_device\_type(const BD\_ADDR bd\_addr, int \*p\_device\_type, bdstr\_t bd\_addr\_str, size\_t bd\_addr\_str\_size)
{
if (p\_device\_type == NULL || bd\_addr\_str\_size < BDADDR\_STR\_SIZE)
return FALSE;

bt\_bdaddr\_t bda;
bdcpy(bda.address, bd\_addr);

if (!btif\_config\_get\_int(&bda, "DevType", p\_device\_type))
return FALSE;

if (bdaddr\_to\_string(&bda, bd\_addr\_str, bd\_addr\_str\_size) < 0)
return FALSE;

LOG\_DEBUG(LOG\_TAG, "*s: Device [%s] type %d", __FUNCTION__, bd\_addr\_str, *p\_device\_type);
return TRUE;
}