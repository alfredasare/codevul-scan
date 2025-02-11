xps_sample_gradient_stops(fz_shade *shade, struct stop *stops, int count)
{
	float offset, d;
	int i, k;

	if (count <= 0 || stops == NULL) {
		return;
	}

	k = 0;
	for (i = 0; i < 256; i++)
	{
		offset = i / 255.0f;
		while (k + 1 < count && offset > stops[k+1].offset)
			k++;

		if (k >= count - 1) {
			break;
		}

		d = (offset - stops[k].offset) / (stops[k+1].offset - stops[k].offset);

		shade->function[i][0] = lerp(stops[k].r, stops[k+1].r, d);
		shade->function[i][1] = lerp(stops[k].g, stops[k+1].g, d);
		shade->function[i][2] = lerp(stops[k].b, stops[k+1].b, d);
		shade->function[i][3] = lerp(stops[k].a, stops[k+1].a, d);
	}
}