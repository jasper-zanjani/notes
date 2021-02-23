## Testing

### Parameterized test cases

=== "C#"

    ```csharp
    using System;
    using Xunit;
    using Starships;

    public class StarshipTests
    {
        [Theory]
        [InlineData("USS Enterprise","NCC-1701",203)]
        [InlineData("USS Constitution","NCC-1700",204)]
        [InlineData("USS Voyager","NCC-74656",141)]
        [InlineData("USS Defiant","NX-74205",50)]
        [InlineData("USS Enterprise","NCC-1701-D",1000)]

        public void StarshipsAreValid(string name, string registry, int crew)
        {
            var starship = new Starship{Name=name,Registry=registry,Crew=crew};
            Assert.Equal(starship.Name,name);
            Assert.Equal(starship.Registry,registry);
            Assert.Equal(starship.Crew,crew);
        }
    }
    ```