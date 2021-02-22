## Syntax
### Classes
### Interfaces

Interfaces can be used to break up dependencies and implement the **dependency inversion principle**.
This principle holds that components should be dependent on abstractions, and not on implementations. ([src](https://app.pluralsight.com/course-player?clipId=77bf1e15-99ef-432e-b6c1-62c192414edb))


## Testing

Visual Studio has a built-in test-runner, but the `dotnet` CLI utility also allows the entire test suite to be executed from the command-line.

```sh
dotnet test
```

### xUnit 

In **xUnit**, tests are organized into public classes, and **test cases** are composed by individual methods on this class, decorated with the `Fact` attribute.
Test assertions are made with static `Assert` method calls.

```csharp
public class TestCases
{
    [Fact]
    public void TestCase()
    {
        Assert.Equal(2 + 2, 4);
    }
}
```

Assertions that an exception must be thrown are generic method calls typed to the specific exception.

```csharp
[Fact]
public void ShouldThrowExceptionIfRequestIsNull()
{
    Assert.Throws<ArgumentNullException>(() => processor.BookDesk(null));
}
```

**Test fixtures** can be formed on properties of the main test class.
They must be initialized with the test class's constructor.

```csharp
public class DeskBookerRequestProcessorTests
{
    public DeskBookerRequestProcessor processor { get; set; }

    public DeskBookerRequestProcessorTests()
    {
        processor = new DeskBookerRequestProcessor();
    }

    [Fact]
    public void ShouldReturnDeskBookerResultWithRequestValues()
    {
        var request = new DeskBookerRequest
        {
            FirstName = "Thomas",
            LastName = "Huber",
            Email = "thomas@huber.com",
            Date = new DateTime(2020, 1, 28)

        };
        var result = processor.BookDesk(request);

        Assert.NotNull(result);
        Assert.Equal(request.FirstName, result.FirstName);
        Assert.Equal(request.LastName, result.LastName);
        Assert.Equal(request.Email, result.Email);
        Assert.Equal(request.Date, result.Date);

    }

    [Fact]
    public void ShouldThrowExceptionIfRequestIsNull()
    {
        var exception = Assert.Throws<ArgumentNullException>(() => processor.BookDesk(null));
        Assert.Equal("request",exception.ParamName);
    }
}
```

### Moq

The **Moq** NuGet package ("mawk-yu") facilitates mocking.





## Project files

References to other projects can be made using the `ProjectReference` element, which are collected in `ItemGroup`.
NuGet package dependencies are specified using `PackageReference` element, also in `ItemGroup`

=== "ProjectReference"

    ```xml
    <ItemGroup>
        <ProjectReference Include="/path/to/OtherProject.csproj"/>
    </ItemGroup>
    ```

=== "PackageReference"

    ```xml
    <ItemGroup>
        <PackageReference Include="xunit" Version="2.4.0"/>
    </ItemGroup>
    ```


## .NET
### dotnet

Create a new [xUnit](#xunit) project named tests
```sh
dotnet new xunit -n tests
```
Add a [project file](#project-files) to a solution
```sh
dotnet sln add ./Project/Project.csproj
```
Add a [project reference](https://docs.microsoft.com/en-us/dotnet/core/tools/dotnet-add-reference) to a project
```sh
dotnet add reference ./path/to/Project.csproj
```
Install the Moq NuGet package
```sh
dotnet add package moq
```