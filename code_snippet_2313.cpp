static int logi_dj_recv_send_report(struct dj_receiver_dev *djrcv_dev,
				   struct dj_report *dj_report)
{
    ...
    size_t i;
    ...
    for (i = 0; i < DJREPORT_SHORT_LENGTH - 1 && i < sizeof(report->field[0]->value) / sizeof(report->field[0]->value[0]); i++) {
        report->field[0]->value[i] = data[i];
    }
    ...
}