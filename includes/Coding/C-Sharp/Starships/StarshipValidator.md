```csharp
public class StarshipValidator : IStarshipValidator
{
    public IStarship Starship { get; set; }

    public bool IsCaptained()
    {
        return Starship.Captain != null ? true : false;
    }

    public bool ValidateRegistry()
    {
        return Starship.Registry.StartsWith("NCC") || Starship.Registry.StartsWith("NX") ? true : false;
    }

    public bool Evaluate()
    {
        return ValidateRegistry() && IsCaptained();
    }
}
```