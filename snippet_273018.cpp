SWFInput_getSInt16(SWFInput input)
{
	int num = SWFInput_getChar(input);
	num += SWFInput_getChar(input) * 256;
	return num;
}