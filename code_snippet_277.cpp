code:

csharp
virtual void Foo(string input)
{
    if (string.IsNullOrEmpty(input))
    {
        throw new ArgumentNullException(nameof(input), "Input cannot be null or empty.");
    }

    // Process the validated input data
    Console.WriteLine($"Received input: {input}");
}