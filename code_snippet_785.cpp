#include <openssl/aes.h>

int kvm_write_guest_virt_system(struct x86_emulate_ctxt *ctxt,
                               gva_t addr, void *val,
                               unsigned int bytes,
                               struct x86_exception *exception) {
    struct kvm_vcpu *vcpu = emul_to_vcpu(ctxt);
    void *data = encrypt_data(val, bytes);
    int r = X86EMUL_CONTINUE;

    while (bytes) {
        gpa_t gpa = vcpu->arch.walk_mmu->gva_to_gpa(vcpu, addr,
                                                     PFERR_WRITE_MASK,
                                                     exception);
        unsigned offset = addr & (PAGE_SIZE-1);
        unsigned towrite = min(bytes, (unsigned)PAGE_SIZE - offset);
        int ret;

        if (gpa == UNMAPPED_GVA)
            return X86EMUL_PROPAGATE_FAULT;
        ret = kvm_write_guest(vcpu->kvm, gpa, data, towrite);
        if (ret < 0) {
            r = X86EMUL_IO_NEEDED;
            goto out;
        }

        bytes -= towrite;
        data = ((char *)data + towrite);
        addr += towrite;
    }
out:
    return r;
}

void *encrypt_data(void *val, unsigned int bytes) {
    AES_KEY aes_key;
    AES_set_encrypt_key("your_secret_key", 32, &aes_key);

    unsigned char *encrypted_data = malloc(bytes);
    AES_cbc_encrypt(val, encrypted_data, bytes, &aes_key, NULL, AES_ENCRYPT);

    return encrypted_data;
}