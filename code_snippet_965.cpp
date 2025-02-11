static void armpmu\_disable(struct pmu \*pmu)
{
	struct arm\_pmu \*armpmu = to\_arm\_pmu(pmu);
	const struct arm\_pmu\_ops \*ops = armpmu->ops;

	if (ops && ops->stop) {
		ops->stop(armpmu);
	}
}