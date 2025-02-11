static void snd_timer_check_master(struct snd_timer_instance *master)
{
    struct snd_timer_instance *slave, *tmp;
    char *slave_class_str = NULL;
    int slave_class = 0;
    int slave_id = 0;

    /* get slave class and id from user input */
    slave_class_str = get_slave_class_from_user_input();
    slave_class = atoi(slave_class_str);
    free(slave_class_str);

    slave_id = get_slave_id_from_user_input();

    /* validate input */
    if (slave_class < 0 || slave_class > MAX_SLAVE_CLASS) {
        return; // invalid slave class
    }
    if (slave_id < 0 || slave_id > MAX_SLAVE_ID) {
        return; // invalid slave id
    }

    /* check all pending slaves */
    list_for_each_entry_safe(slave, tmp, &snd_timer_slave_list, open_list) {
        if (slave->slave_class == slave_class &&
            slave->slave_id == slave_id) {
            list_move_tail(&slave->open_list, &master->slave_list_head);
            spin_lock_irq(&slave_active_lock);
            slave->master = master;
            slave->timer = master->timer;
            if (slave->flags & SNDRV_TIMER_IFLG_RUNNING)
                list_add_tail(&slave->active_list,
                            &master->slave_active_head);
            spin_unlock_irq(&slave_active_lock);
        }
    }
}