static int php_snmp_has_property(zval *object, zval *member, int has_set_exists, void **cache_slot)
{
    zval rv;
    php_snmp_prop_handler *hnd;
    int ret = 0;

    // Validate member parameter against a whitelist of allowed property names
    if (!property_whitelist_check(Z_STR_P(member))) {
        return 0;
    }

    if ((hnd = zend_hash_find_ptr(&php_snmp_properties, Z_STR_P(member))) != NULL) {
        switch (has_set_exists) {
            case 2:
                ret = 1;
                break;
            case 0: {
                zval *value = php_snmp_read_property(object, member, BP_VAR_IS, cache_slot, &rv);
                if (value != &EG(uninitialized_zval)) {
                    ret = Z_TYPE_P(value) != IS_NULL? 1 : 0;
                    zval_ptr_dtor(value);
                }
                break;
            }
            default: {
                zval *value = php_snmp_read_property(object, member, BP_VAR_IS, cache_slot, &rv);
                if (value != &EG(uninitialized_zval)) {
                    convert_to_boolean(value);
                    ret = Z_TYPE_P(value) == IS_TRUE? 1:0;
                }
                break;
            }
        }
    } else {
        zend_object_handlers *std_hnd = zend_get_std_object_handlers();
        ret = std_hnd->has_property(object, member, has_set_exists, cache_slot);
    }
    return ret;
}

// Function to check if the provided property name is in the whitelist
int property_whitelist_check(const char *property_name) {
    HashTable *whitelist = zend_hash_init(0, 0);

    // Add allowed property names to the whitelist hash table
    add_allowed_property("property1", whitelist);
    add_allowed_property("property2", whitelist);
    add_allowed_property("property3", whitelist);

    // Check if the provided property name exists in the whitelist
    return zend_hash_exists(whitelist, property_name, strlen(property_name) + 1);
}

void add_allowed_property(const char *property_name, HashTable *whitelist) {
    zval property_zval;
    ZVAL_STRING(&property_zval, property_name);
    zend_hash_add(whitelist, property_name, strlen(property_name), &property_zval, sizeof(zval*), NULL);
}