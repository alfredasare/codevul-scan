static void packet_mm_close(struct vm\_area\_struct \*vma)
{
 struct file \*file = vma->vm\_file;
 struct socket \*sock = file->private\_data;
 struct sock \*sk = sock->sk;

 if (sk && (atomic\_read(&pkt\_sk(sk)->mapped) > 0))
 atomic\_dec(&pkt\_sk(sk)->mapped);
}