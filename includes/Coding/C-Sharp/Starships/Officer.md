```csharp
public interface IOfficer
{
    string FirstName { get; set; }
    string LastName { get; set; }
    DateTime BirthDate { get; set; }
    char Grade { get; set; }
    string Name { get; }
}

public class Officer : IOfficer
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public DateTime BirthDate { get; set; }
    public string Name { get { return $"{FirstName} {LastName}"; } }
    public char Grade { get; set; }
}
```