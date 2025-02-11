void open_init(int count)
{
    // Check if the input is within acceptable bounds
    if (count >= 0) {
        open_count = count;
        open_unlimited = (count == -1) ? 0 : 1;
    } else {
        // Handle error condition
        // ...
    }
}