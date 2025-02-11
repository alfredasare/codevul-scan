void S\_AL\_ClearLoopingSounds(qboolean killall)
{
	if (srcCount < MAX\_SrcList) {
		int i;
		for (i = 0; i < srcCount; i++) {
			if ((srcList[i].isLooping) && (srcList[i].entity != -1) && (i < MAX\_SrcList))
				entityList[srcList[i].entity].loopAddedThisFrame = qfalse;
		}
	}
}