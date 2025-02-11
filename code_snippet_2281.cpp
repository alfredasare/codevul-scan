static void m\_stop(struct seq\_file \*m, void \*v)
{
	struct proc\_maps\_private \*priv = m->private;
	struct vm\_area\_struct \*vma = v;
	
	vma\_stop(priv, vma);
	if (priv->task)
		put\_task\_struct(priv->task);
	
	// Fix: Use a constant format string
	seq\_printf(m, "Task stopped\n");
}