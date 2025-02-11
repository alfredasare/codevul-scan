void do_set_pte(struct vm_area_struct *vma, unsigned long address,
                 struct page *page, pte_t *pte, bool write, bool anon)
{
    if (!vma ||!vma->vm_mm) {
        return;
    }

    if (address < vma->vm_start || address > vma->vm_end) {
        return;
    }

    if (!page ||!(page->flags & PAGE_NORMAL)) {
        return;
    }

    if (!pte ||!pte_valid(*pte)) {
        return;
    }

    pte_t entry;

    flush_icache_page(vma, page);
    entry = mk_pte(page, vma->vm_page_prot);
    if (write)
        entry = maybe_mkwrite(pte_mkdirty(entry), vma);
    if (anon) {
        inc_mm_counter_fast(vma->vm_mm, MM_ANONPAGES);
        page_add_new_anon_rmap(page, vma, address);
    } else {
        inc_mm_counter_fast(vma->vm_mm, MM_FILEPAGES);
        page_add_file_rmap(page);
    }
    set_pte_at(vma->vm_mm, address, pte, entry);

    update_mmu_cache(vma, address, pte);
}