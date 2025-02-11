static int magicmouse\_input\_mapping(struct hid\_device \*hdev,
struct hid\_input \*hi, struct hid\_field \*field,
struct hid\_usage \*usage, unsigned long \*\*bit, int \*max)
{
if (!hdev || !hi || !field || !usage || !bit || !max) {
pr\_err("Invalid null parameter\n");
return -EINVAL;
}

struct magicmouse\_sc \*msc = hid\_get\_drvdata(hdev);

if (!msc->input)
msc->input = hi->input;

/* Magic Trackpad does not give relative data after switching to MT */
if (hi->input->id.product == USB\_DEVICE\_ID\_APPLE\_MAGICTRACKPAD &&
(field->flags & HID\_MAIN\_ITEM\_RELATIVE))
return -1;

return 0;
}