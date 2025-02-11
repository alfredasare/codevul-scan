#include <string.h>

struct nfsd4_free_stateid *
nfsd4_decode_free_stateid(struct nfsd4_compoundargs *argp,
			  struct nfsd4_free_stateid *free_stateid)
{
	DECODE_HEAD;

	READ_BUF(sizeof(stateid_t));
	if (buf_left < sizeof(free_stateid->fr_stateid.si_generation)) {
		/* Insufficient data, handle error */
		goto out_free;
	}
	free_stateid->fr_stateid.si_generation = be32_to_cpup(p++);

	if (buf_left < sizeof(stateid_opaque_t)) {
		/* Insufficient data, handle error */
		goto out_free;
	}
	memcpy(&free_stateid->fr_stateid.si_opaque, p, sizeof(stateid_opaque_t));
	p += sizeof(stateid_opaque_t);

out_free:
	DECODE_TAIL;
	return free_stateid;
}