spnego_gss_set_name_attribute(OM_uint32 *minor_status,
			      gss_name_t name,
			      int complete,
			      gss_buffer_t attr,
			      gss_buffer_t value)
{
	OM_uint32 ret;
	ret = gss_set_name_attribute(minor_status,
				     name,
				     complete,
				     attr,
				     value);
	return (ret);
}