#include <string.h>

write_or_buffer(struct reqelem * req, const unsigned char * data, int len)
{
	if(write_buffer(req) < 0)
		return -1;
	if(req->output_buffer && req->output_buffer_len > 0) {
		return add_to_buffer(req, data, len);
	} else {
		int remaining_space = req->output_buffer_size - req->output_buffer_len;
		int n = write(req->socket, data, len < remaining_space ? len : remaining_space);
		if(n == len)
			return len;
		if(n < 0) {
			if(errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN) {
				n = add_to_buffer(req, data, len < remaining_space ? len : remaining_space);
				if(n < 0) return n;
			} else {
				return n;
			}
		} else {
			int leftover_len = len - n;
			n = add_to_buffer(req, data + n, leftover_len < remaining_space ? leftover_len : remaining_space);
			if(n < 0) return n;
		}
	}
	return len;
}