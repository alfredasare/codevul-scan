list[i] = (i < dpb->numRefFrames) ? &dpb->buffer[i] : NULL;
}

Adjust the value of `MAX_REF_FRAMES` according to your system's constraints.