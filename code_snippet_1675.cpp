static gboolean validate_and_sanitize_init_arguments(const gpointer init_args) {
    // Perform validation and sanitization logic here
    // Return TRUE if input is valid, FALSE otherwise
}

static gboolean validate_and_sanitize_transfer_arguments(const gpointer transfer_args) {
    // Perform validation and sanitization logic here
    // Return TRUE if input is valid, FALSE otherwise
}

static void ssi_sd_class_init(ObjectClass *klass, void *data)
{
    SSISlaveClass *k = SSI_SLAVE_CLASS(klass);

    if (validate_and_sanitize_init_arguments(k->init_args)) {
        k->init = ssi_sd_init;
    } else {
        g_critical("Invalid init arguments");
        return;
    }

    if (validate_and_sanitize_transfer_arguments(k->transfer_args)) {
        k->transfer = ssi_sd_transfer;
    } else {
        g_critical("Invalid transfer arguments");
        return;
    }

    k->cs_polarity = SSI_CS_LOW;
}