static void unregister\_pernet\_operations(struct pernet\_operations \*ops)
{
	struct ida\_bit\_record \*id\_record;

	__unregister\_pernet\_operations(ops);
	rcu\_barrier();
	read\_lock(&net\_generic\_ids.lock);
	if (ops->id) {
		id\_record = ida\_get(&net\_generic\_ids, \*ops->id);
		if (id\_record)
			ida\_remove(&net\_generic\_ids, \*ops->id);
	}
	read\_unlock(&net\_generic\_ids.lock);
}