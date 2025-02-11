gsf_infile_tar_finalize (GObject *obj)
{
	GsfInfileTar *tar = GSF_INFILE_TAR (obj);
	parent_class->finalize (obj); /* Call the parent class's finalize method first */
	g_array_free (tar->children, TRUE);
}