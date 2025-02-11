RList *r\_bin\_wasm\_get\_datas(RBinWasmObj *bin) {
	RBinWasmSection *data = NULL;
	RList *datas = NULL;
	RList *g\_datas = NULL;

	if (!bin) return NULL;
	if (!bin->g\_sections) return r\_list\_new();

	if (bin->g\_datas) return bin->g\_datas;

	datas = r\_bin\_wasm\_get\_sections\_by\_id(bin->g\_sections, R\_BIN\_WASM\_SECTION\_DATA);
	if (!datas) return r\_list\_new();

	data = (RBinWasmSection *)r\_list\_first(datas);
	if (!data) {
		r\_list\_free(datas);
		return r\_list\_new();
	}

	g\_datas = r\_bin\_wasm\_get\_data\_entries(bin, data);
	r\_list\_free(datas);

	bin->g\_datas = g\_datas;

	return bin->g\_datas;
}