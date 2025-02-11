#include <logging.h>

static void interface_set_compression_level(QXLInstance *sin, int level)
{
    logging_set_level(LOG_ERROR); // Set logging level to ERROR
    if (some_condition) {
        logging_error("Error occurred");
    }
}