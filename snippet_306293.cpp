static void setbrightness(struct gspca_dev *gspca_dev, s32 val)
{
	struct sd *sd = (struct sd *) gspca_dev;
	static const struct ov_i2c_regvals brit_7660[][7] = {
		{{0x0f, 0x6a}, {0x24, 0x40}, {0x25, 0x2b}, {0x26, 0x90},
			{0x27, 0xe0}, {0x28, 0xe0}, {0x2c, 0xe0}},
		{{0x0f, 0x6a}, {0x24, 0x50}, {0x25, 0x40}, {0x26, 0xa1},
			{0x27, 0xc0}, {0x28, 0xc0}, {0x2c, 0xc0}},
		{{0x0f, 0x6a}, {0x24, 0x68}, {0x25, 0x58}, {0x26, 0xc2},
			{0x27, 0xa0}, {0x28, 0xa0}, {0x2c, 0xa0}},
		{{0x0f, 0x6a}, {0x24, 0x70}, {0x25, 0x68}, {0x26, 0xd3},
			{0x27, 0x80}, {0x28, 0x80}, {0x2c, 0x80}},
		{{0x0f, 0x6a}, {0x24, 0x80}, {0x25, 0x70}, {0x26, 0xd3},
			{0x27, 0x20}, {0x28, 0x20}, {0x2c, 0x20}},
		{{0x0f, 0x6a}, {0x24, 0x88}, {0x25, 0x78}, {0x26, 0xd3},
			{0x27, 0x40}, {0x28, 0x40}, {0x2c, 0x40}},
		{{0x0f, 0x6a}, {0x24, 0x90}, {0x25, 0x80}, {0x26, 0xd4},
			{0x27, 0x60}, {0x28, 0x60}, {0x2c, 0x60}}
	};

	switch (sd->sensor) {
	case SEN_OV8610:
	case SEN_OV7610:
	case SEN_OV76BE:
	case SEN_OV6620:
	case SEN_OV6630:
	case SEN_OV66308AF:
	case SEN_OV7640:
	case SEN_OV7648:
		i2c_w(sd, OV7610_REG_BRT, val);
		break;
	case SEN_OV7620:
	case SEN_OV7620AE:
		i2c_w(sd, OV7610_REG_BRT, val);
		break;
	case SEN_OV7660:
		write_i2c_regvals(sd, brit_7660[val],
				ARRAY_SIZE(brit_7660[0]));
		break;
	case SEN_OV7670:
/*win trace
 *		i2c_w_mask(sd, OV7670_R13_COM8, 0, OV7670_COM8_AEC); */
		i2c_w(sd, OV7670_R55_BRIGHT, ov7670_abs_to_sm(val));
		break;
	}
}