#include <libbson/bson.h>
#include <stdlib.h>

test_bson_visit_unsupported_type_empty_key (void)
{
    bson_t *b = bson_new();
    bson_iter_t iter;
    unsupported_type_test_data_t context = {0};
    bson_visitor_t visitor = {0};

    visitor.visit_unsupported_type = visit_unsupported_type;

    const char *data = "\x0b\x00\x00\x00\x33\x00\x01\x00\x00\x00\x00";
    size_t data_len = strlen(data);

    uint8_t *bson_data = malloc(data_len + 1);
    memcpy(bson_data, data, data_len);
    bson_data[data_len] = '\0';

    BSON_ASSERT (bson_init(b, bson_data, data_len));
    BSON_ASSERT (bson_iter_init(&iter, b));
    BSON_ASSERT (!bson_iter_visit_all(&iter, &visitor, (void *)&context));
    BSON_ASSERT (!bson_iter_next(&iter));
    BSON_ASSERT (context.visited);
    BSON_ASSERT (!strcmp(context.key, ""));
    BSON_ASSERT (context.type_code == '\x33');

    free(bson_data);
    bson_free(b);
    return;
}