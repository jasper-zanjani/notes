# Pester
Pester tests are organized in a hierarchy of blocks:
- `Describe` 
  - `Context` (optional)
    - `It`
      - `Should` assertion statements accept a value passed in via pipe and **must** be called within a `Describe` block

The typical Pester script contains a `Describe` block, which act as a logical grouping for one or more tests. <sup>[pester.dev](https://pester.dev/docs/quick-start)</sup>
```powershell
New-Fixture deploy Foo

function Foo {
  # ...
}
```
```powershell
Describe 'Foo' {
  $true | Should -Be $true }
```
The block in braces is actually an argument pass to the `-Fixture` parameter.
```powershell
Describe "Best airports in the USA" -Fixture {
  It -Name "RDU is one of the best airports" -Test {
    $Output = Get-Airport -City "Raleigh"
    $Output | Should -BeOfType System.Collections.Hashtable
  }
}
```
Pester is run with `Invoke-Pester` <sup>[src](https://www.red-gate.com/simple-talk/sysadmin/powershell/introduction-to-testing-your-powershell-code-with-pester/)</sup>
```powershell
Invoke-Pester $scriptfile
```
