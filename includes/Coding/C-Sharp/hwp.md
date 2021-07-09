```csharp
using System.CommandLine;
using System.CommandLine.Invocation;

static int Main(string[] args)
{
    var cmd = new RootCommand
    {
        new Argument<string>("name"),//, "Your name"),
        new Option<string?>(new[] {"--greeting", "-g" },"The greeting to use"),
    };

    cmd.Handler = CommandHandler.Create<string, string?>(HandleGreeting);

    return cmd.Invoke(args);
}

static void HandleGreeting(string? greeting, string name)
{
    Console.WriteLine($"{greeting}, {name}");
}
```