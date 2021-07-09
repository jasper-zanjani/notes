```csharp
public class CaptainSelector
{
    public IOfficer Officer { get; set; }

    public CaptainSelector(IOfficer officer)
    {
        Officer = officer;
    }
    public bool Evaluate()
    {
        return Officer.Grade == 'A' ? true : false;
    }
}
```