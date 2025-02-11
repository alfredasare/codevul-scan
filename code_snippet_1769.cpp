channel\_unlink\_all\_circuits(channel\_t *chan)
{
if (!chan || !chan->cmux) {
return;
}

circuitmux\_detach\_all\_circuits(chan->cmux);
chan->num\_n\_circuits = 0;
chan->num\_p\_circuits = 0;
}