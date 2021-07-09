```csharp
public interface IStarship
{
    string Name { get; set; }
    string Registry { get; set; }
    int Crew { get; set; }
    StarshipClass StarshipClass { get; set; }
    IOfficer Captain { get; set; }
}

public class Starship : IStarship
{
    public string Name { get; set; }
    public string Registry { get; set; }
    public int Crew { get; set; }
    public StarshipClass StarshipClass { get; set; }
    public IOfficer Captain { get; set; }

}
```