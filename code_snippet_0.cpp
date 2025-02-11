static void trace\_iterator\_increment(struct trace\_iterator \*iter)
{
	struct ring\_buffer\_iter \*buf\_iter = trace\_buffer\_iter(iter, iter->cpu);

	if (iter->idx < iter->end) {
		iter->idx++;
		if (buf\_iter)
			ring\_buffer\_read(buf\_iter, NULL);
	}
}