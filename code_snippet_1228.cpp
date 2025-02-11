static int __verify_planes_array(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
	if (!V4L2_TYPE_IS_MULTIPLANAR(b->type))
		return 0;

	/* Is memory for copying plane information present? */
	if (b->m.planes == NULL) {
		dprintk(1, "multi-planar buffer passed but "
			   "planes array not provided\n");
		return -EINVAL;
	}

	for (int i = 0; i < b->length; ++i) {
		if (b->m.planes[i] == NULL) {
			dprintk(1, "Null pointer in planes array\n");
			return -EINVAL;