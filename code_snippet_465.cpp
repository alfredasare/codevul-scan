cleanup\_exit(int i)
{
	cleanup\_socket();
	exit(i);
}