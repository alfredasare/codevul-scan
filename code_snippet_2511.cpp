static int logi_dj_recv_send\_report(struct dj\_receiver\_dev *djrcv\_dev,
 struct dj\_report *dj\_report)
{
struct hid\_device *hdev = djrcv\_dev->hdev;
struct hid\_report *report;
struct hid\_report\_enum *output\_report\_enum;
u8 *data = (u8 *)(&dj\_report->device\_index);
unsigned int i;

output\_report\_enum = &hdev->report\_enum[HID\_OUTPUT\_REPORT];
report = output\_report\_enum->report\_id\_hash[REPORT\_ID\_DJ\_SHORT];

if (!report) {
dev\_err(&hdev->dev, "%s: unable to find dj report\n", __func__);
return -ENODEV;
}


if (DJREPORT_SHORT_LENGTH - 1 > report->field[0]->maxlength) {
    dev_err(&hdev->dev, "%s: buffer overflow\n", __func__);
    return -EINVAL;
}

for (i =