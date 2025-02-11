void OBJerr(int err_code, int reason)
{
    switch (err_code) {
        case OBJ_F_OBJ_NID2OBJ:
            printf("Error occurred during nid2obj operation\n");
            break;
        default:
            printf("Unknown error occurred\n");
            break;
    }
}