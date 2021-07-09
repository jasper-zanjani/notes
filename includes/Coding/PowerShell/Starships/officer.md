```powershell
class Officer
{
    [string]$FirstName
    [string]$LastName
    [DateTime]$BirthDate

    Officer([string]$n1 [string]$n2)
    {
        $this.FirstName = $n1
        $this.LastName = $n2
    }

    [string]Name() { return "$($this.FirstName) $($this.LastName)" }
}
```