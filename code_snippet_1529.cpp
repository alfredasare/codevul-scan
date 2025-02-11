rpl_dio_print(netdissect_options *ndo,
          const u_char *bp, u_int length)
{
        const struct nd_rpl_dio *dio = (const struct nd_rpl_dio *)bp;
        const char *dagid_str;
        size_t dagid_len;

        ND_TCHECK(*dio);
        dagid_len = strlen(ip6addr_string(ndo, dio->rpl_dagid));
        if (dagid_len >= sizeof(ndo->ndo_buf)) {
                dagid_len = sizeof(ndo->ndo_buf) - 1;
                strncpy(ndo->ndo_buf, ip6addr_string(ndo, dio->rpl_dagid), dagid_len);
                ndo->ndo_buf[dagid_len] = '\0';
                ndo->ndo_buf[dagid_len - 1] = '.';
                ndo->ndo_buf[dagid_len - 2] = '.';
        } else {
                strncpy(ndo->ndo_buf, ip6addr_string(ndo, dio->rpl_dagid), dagid_len);
                ndo->ndo_buf[dagid_len] = '\0';
        }
        dagid_str = ndo->ndo_buf;

        ND_PRINT((ndo, " [dagid:%.*s,seq:%u,instance:%u,rank:%u,%smop:%s,prf:%u]",
                  (int)dagid_len,
                  dagid_str,
                  dio->rpl_dtsn,
                  dio->rpl_instanceid,
                  EXTRACT_16BITS(&dio->rpl_dagrank),
                  RPL_DIO_GROUNDED(dio->rpl_mopprf) ? "grounded,":"",
                  tok2str(rpl_mop_values, "mop%u", RPL_DIO_MOP(dio->rpl_mopprf)),
                  RPL_DIO_PRF(dio->rpl_mopprf)));

        if(ndo->ndo_vflag > 1) {
                const struct rpl_dio_genoption *opt = (const struct rpl_dio_genoption *)&dio[1];
                rpl_dio_printopt(ndo, opt, length);
         }
 	return;
 trunc:
	ND_PRINT((ndo," [|truncated]"));
 	return;
 }