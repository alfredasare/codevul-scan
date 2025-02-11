static void packet_mm_close(struct vm_area_struct *vma)
{
    struct file *file = vma->vm_file;
    struct socket *sock = file->private_data;
    struct sock *sk = sock->sk;

    if (sk) {
        if (!validate_vma(vma)) {
            return;
        }
        atomic_dec(&pkt_sk(sk)->mapped);
    }
}

bool validate_vma(struct vm_area_struct *vma)
{
    return vma &&!(vma->vm_flags & VM_SHARED);
}