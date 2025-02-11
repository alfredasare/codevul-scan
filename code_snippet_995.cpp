public class PendingFrame
{
    private byte[] _buffer;

    public PendingFrame(int size)
    {
        _buffer = new byte[size]; 
        using (var memoryStream = new MemoryStream(_buffer))
        {
            // Use the buffer
        }
    }
}