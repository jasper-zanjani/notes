# Testing

There has been a push toward adoption of unit-testing over the past decades, so much so that the amount of test code can exceed production code by up to 10 times.

Testing can help to forestall **software entropy**, the phenomenon whereby a software project becomes progressively more complex and disorganized.

There are two popular **coverage metrics** that quantitatively measure the quality of a test suite:

- **Test coverage**: the portion of total production code lines executed by any test
- **Branch coverage**: the portion of total number of branches traversed by any test

## Unit testing

A **unit test** quickly tests a small piece of code (or "unit") in isolation of others.

There are two schools of unit testing which differ in their intepretation of how isolation should be achieved:

- **London** (also "mockist") approach emphasizes segregation of the **system under test** from its **collaborators** (dependencies) using [**test doubles**][test double], in particular [**mocks**][mock].
- **Classical** (also "Detroit") approach emphasizes segregation of unit tests themselves from each other, allowing them to be run independently. In classical testing, there is less emphasis on using test doubles, which are used strictly for **shared dependencies**

### AAA

Conventionally, tests have a three-part structure summarized in the acronym **AAA** (also **3A** or **Given-When-Then**):

- **Arrange**: SUT and dependencies are brought to a desired state
- **Act**: methods on the SUT are called and output is captured
- **Assert**: outcome is verified

Several recommendations when using this framework:

- Every unit test should have a single Action
- Avoid conditional logic in unit tests
- The Arrange section should be largest, but if it is too large then it should be extracted into a private method or a separate factory class.
- Unit tests should be loosely coupled. Placing reusable [**test fixtures**][test fixture] in the test class's constructor is an anti-pattern, unless every single test method uses the fixture.
- Test methods should have expressive, easily understood names.


## 🛠&#xfe0f; Tasks
### 🚀 Starship

=== "C#"

    ```csharp
    public class StarshipShould
    {

        [Theory]
        [InlineData("USS Enterprise","NCC-1701",203)]
        [InlineData("USS Constitution","NCC-1700",204)]
        [InlineData("USS Voyager","NCC-74656",141)]
        [InlineData("USS Defiant","NX-74205",50)]
        [InlineData("USS Enterprise","NCC-1701-D",1000)]
        public void BeValid(string name, string registry, int crew)
        {
            var starship = new Starship{Name=name,Registry=registry,Crew=crew};
            Assert.Equal(starship.Name,name);
            Assert.Equal(starship.Registry,registry);
            Assert.Equal(starship.Crew,crew);
        }
    }
    ```

=== "Python"

    ```py
    import pytest
    from starships import Starship,StarshipClass,Fleet

    @pytest.fixture
    def enterprise():
        return Starship("USS Enterprise","NCC-1701",StarshipClass.CONSTITUTION)

    def test_lookup_by_name(enterprise):
        starfleet = Fleet()
        starfleet.add(enterprise)
        assert starfleet.lookup(enterprise.name) == enterprise
    ```


#### 🚀✔&#xfe0f; StarshipValidator

=== "C#"

    ```csharp
    public class StarshipValidatorShould
    {
        [Theory]
        [InlineData("Jean-Luc Picard", 2305, 7, 13)]
        [InlineData("James Kirk", 2233, 3, 22)]
        public void ValidateCaptainedStarships(string n, params int[] dob)
        {
            var mockStarship = new Mock<IStarship>();
            Captain captain = new Captain(n,new DateTime(dob[0], dob[1], dob[2]));
            mockStarship.Setup(x => x.Captain).Returns(captain);

            StarshipValidator starshipValidator = new StarshipValidator(mockStarship.Object);
            Assert.True(starshipValidator.IsCaptained());
        }

        [Theory]
        [InlineData("USS Enterprise","NCC-1701",203)]
        [InlineData("USS Constitution","NCC-1700",204)]
        [InlineData("USS Voyager","NCC-74656",141)]
        [InlineData("USS Defiant","NX-74205",50)]
        [InlineData("USS Enterprise","NCC-1701-D",1000)]
        public void ValidateStarshipsWithValidRegistryNumbers(string name, string registry, int crew)
        {
            var starship = new Starship{Name =name, Registry =registry,Crew= crew};
            StarshipValidator starshipValidator = new StarshipValidator(starship);
            Assert.True(starshipValidator.ValidateRegistry());
        }
    }
    ```

#### 🚀🏹 StarshipDeployment

=== "C# Test (xUnit)"

    ```csharp
    public class StarshipDeploymentShould
    {
        [Fact]
        public void ThrowOnNullValidator()
        {
            var sut = new StarshipDeployment(null);
            Assert.Throws<ArgumentNullException>(sut);
        }        
        
        [Theory]
        [InlineData("Betelgeuse")]
        public void EvaluateStarship(string destination)
        {
            var mockValidator = new Mock<IStarshipValidator>();
            mockValidator.Setup(x => x.Evaluate()).Returns(true);

            var mockStarship = new Mock<IStarship>();

            var sut = new StarshipDeployment(mockValidator.Object as IStarshipValidator);
            sut.Deploy(mockStarship.Object as Starship, destination);
            mockValidator.Verify(x => x.Evaluate());
        }
    }
    ```


### 👩‍🚀 Officer

#### 👩‍🚀✔&#xfe0f; CaptainSelector

=== "C#"

    ```csharp
    public class CaptainSelectorShould
    {
        [Theory]
        [InlineData('B')]
        [InlineData('C')]
        [InlineData('D')]
        [InlineData('F')]
        public void OnlyAssignGoodCaptains(char grade)
        {
            var mockOfficer = new Mock<IOfficer>();
            mockOfficer.Setup(x => x.Grade).Returns(grade);

            CaptainSelector captainSelector = new CaptainSelector(mockOfficer.Object);
            bool selectionResult = captainSelector.Evaluate();
            Assert.False(selectionResult);
        }
    }
    ```



## 📘 Glossary

**Mock**{: #mock }
:   
    A **mock** is a test double that emulates outgoing interactions, or calls the system under test makes to change the state of a dependency.

    Mocks include [spies][spy].

**Spike**{: #spike }
:   
    A **spike** is an experiment without tests to ensure that an idea will work. Once the spike succeeds, the spike code is thrown away and the logic is recreated following TDD, starting with tests.

**Stub**{: #stub }
:   
    A **stub** is a test double that emulates incoming interactions, or calls the system under test makes to get data from a dependency.

    - **Fakes** provide a working implementation of the dependency, however one which is unsuitable for production (e.g. in-memory databases)
    - **Dummies** are passed around like real implementations but never accessed or used.  These are used to satisfy the parameters of a method.

**Test double**{: #test-double }
:   
    **Test double** include a variety of objects that facilitate unit testing by replacing a production object, usually a data dependency.
    Test doubles can be classified  on what type of interaction the object emulates:

    - [**Mocks**](#mock) emulate outgoing interactions
    - [**Stubs**](#stub) emulate incoming interactions

