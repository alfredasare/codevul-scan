void open_init(int count)
{
    if (count < 0 || count > 100) {
        return;
    }

    open_count = (int) (((uint32_t)count) & 0xFFFFFFFF);
    open_unlimited = count == -1;
}