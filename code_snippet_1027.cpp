void kvm\_free\_lapic(struct kvm\_vcpu \*vcpu)
{
 struct kvm\_lapic *apic = vcpu->arch.apic;

 if (!vcpu->arch.apic)
 return;

 hrtimer\_cancel(&apic->lapic\_timer.timer);

 mutex\_lock(&vcpu->arch.apic\_mutex);

 if (!(vcpu->arch.apic\_base & MSR\_IA32\_APICBASE\_ENABLE))
 static\_key\_slow\_dec\_deferred(&apic\_hw\_disabled);

 if (!(kvm\_apic\_get\_reg(apic, APIC\_SPIV) & APIC\_SPIV\_APIC\_ENABLED))
 static\_key\_slow\_dec\_deferred(&apic\_sw\_disabled);

 if (apic->regs)
 free\_page((unsigned long)apic->regs);

 kfree(apic);
 vcpu->arch.apic = NULL;
 mutex\_unlock(&vcpu->arch.apic\_mutex);
}