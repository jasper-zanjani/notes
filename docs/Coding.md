# 👨‍💻 Coding

## Simple structures

### Hello, world!

=== "C#"

    ```csharp
    using System;

    class Program
    {
        static void Main()
        {
            Console.WriteLine("Hello World!");
        }
    }
    ```

=== "Python"

    ```py
    def main():
        "Hello, world!")

    if __name__ == "__main__":
        main()
    ```


### Dates and times

Parse a date string

=== "C#"

    ```csharp
    string rawDate = "07/04/1776";
    try 
    {
        DateTime parsedDate = DateTime.Parse(rawDate);
    }
    catch (FormatException)
    {
        Console.WriteLine("Unparsable!")
    }

    // Alternatively:
    DateTime.TryParse(rawDate, out parsedDate);

    Console.WriteLine(parsedDate.ToLongDateString()); // => "July 4, 1776"
    ```


## File operations

Write text to file

=== "C#"

    ```csharp
    using (StreamWriter writer = File.CreateText("test.txt"))
    {
        writer.WriteLine("Hello, world!");
    }
    ```

=== "Python"

    ```py
    with open('text', 'w') as f:
        f.write('Hello, world!')
    ```

Read text from file

=== "C#"

    ```csharp
    using (StreamReader reader = File.OpenText("raven"))
    {
        reader.ReadToEnd();
    }

    // Alternatively:
    using (StreamReader reader = File.OpenText("raven"))
    {
        string s;
        while ((s = sr.ReadLine()) != null)
        {
            Console.WriteLine(s);
        }
    }
    ```

=== "Python"

    ```py
    with open('raven') as f:
        f.readlines()
    ```

### CSV

=== "C#"

    ```csharp
    using System;
    using System.IO;
    using CsvHelper;

    struct Greek
    {
        public string name { get; set; }
        public string city { get; set; }
        public string dob { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("greeks.csv"))
            {
                CsvReader csvreader = new CsvReader(reader, System.Globalization.CultureInfo.InvariantCulture);
                
                var data = csvreader.GetRecords<Greek>();
                
                foreach (Greek item in data)
                {
                    Console.WriteLine($"{item.name,-15} {item.city,-15} {item.dob,-15}");
                }
            }
        }
    }
    ```

=== "Python"

    ```py
    import csv

    with open ("greeks.csv") as f:
        r = csv.reader(f)
        headers = next(r)
        data = [row for row in r]
    ```

### JSON

```csharp


using (var stream = await storageFile.OpenAsync(FileAccessMode.Read))
{
    using (var dataReader = new DataReader(stream))
    {
        await dataReader.LoadAsync((uint)stream.Size);
        var json = dataReader.ReadString((uint)stream.Size);
        customerList = JsonConvert.DeserializeObject<List<Customer>>(json);
    }
}
```

### Random numbers

Integer

=== "C#"

    ```csharp
    Random r = new System.Random();
    int result = r.Next(1, 6);
    ```

=== "Python"

    ```py
    import random
    random.randrange(1,6)
    ```

Real number

=== "C#"

    ```csharp
    Random r = new System.Random();
    int result = r.NextDouble();
    ```

=== "Python"

    ```py
    import random
    random.random()
    ```

### Double array


=== "Python"

    ```py
    primes = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23]
    double = lambda x: 2*x
    list(map(double, primes))

    # Alternatively: 
    [ 2 * el for el in primes ]
    ```




### String formatting
Desired output (10 spaces per column, with the third right-justified):
```
Socrates   Athens         470 BC
Plato      Athens         428 BC
Aristotle  Stagira        384 BC
Euclid     Alexandria     325 BC
Pythagoras Samos          570 BC
```

=== "C#"

    ```csharp
    for (int i = 0; i <= greeks.GetUpperBound(0); i++)
    {
        Console.WriteLine("{0,-10} {1,-10} {2,10}", greeks[i,0], greeks[i,1], greeks[i,2]);
    }
    ```

=== "Python"

    ```py
    for r in greeks:
        print("{0:10} {1:10} {2:>10}".format(r[0],r[1],r[2]))
    ```
    
    In C#, multidimensional arrays cannot be traversed with the `foreach` loops which appear to flatten its structure.

Currency formatting

=== "C#"

    ```csharp
    Console.WriteLine($"{123456.789:C }");          //  $123,456.79
    Console.WriteLine(123456.789d.ToString("C"));   //  $123,456.79
    ```

=== "Python"

    === "f-string"

        ```py
        f"${123456.789:,.2f}"                           #   $123,456.79
        ```

    === "locale module"

        ```py
        import locale
        
        def main():
            """
            Formatting a number in currency requires use of the **locale** module, and 
            for the locale environment variables to be set.
            """
            locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
            locale.currency(123456.789)                 #   $123456.79

        if __name__ == "__main__":
            main()
        ```

### TUI input validation loop

Such a loop will continuously prompt for valid input, in this case an integer.

=== "C#"

    === "Parse"

        ```csharp
        while (true):
        {
            try {
                int option = Int32.Parse(Console.ReadLine());
            }
            catch (FormatException) {
                // Input was not an integer
            }
            catch (OverflowException) {
                // Number was too big
            }
        }

        // Alternatively:
        while (true):
        {
            int option;
            int.TryParse(Console.ReadLine(), out option);
            if (option != null)
            {
                // ...
            }
            else {break;}
        }
        ```

=== "Python"

    ```py
    while True:
        try:
            option = int(input())
        except ValueError:
            # Integer was not able to be parsed
    ```

## CLI

### Parameterized "Hello, world!"

=== "C#"

    ```csharp
    using System;
    using System.CommandLine;
    using System.CommandLine.Invocation;

    namespace CommandLine
    {
        class Program
        {
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
        }
    }
    ```

=== "Python"

    ```py
    import argparse

    def get_args():
        parser = argparse.ArgumentParser(description="Say hello")
        parser.add_argument(
            dest="name",metavar="name", default="World", help="Name to greet"
        )
        parser.add_argument(
            "--greeting","-g", dest="greeting", default="Hello", help="Greeting to use"
        )
        return parser.parse_args()


    def main():
        args = get_args()
        print(f"{args.greeting}, {args.name}!")


    if __name__ == "__main__":
        main()
    ```

### Oxford comma

=== "C#"

    ```csharp
    using System;
    using System.CommandLine;
    using System.CommandLine.Invocation;
    using System.Linq;

    namespace OxfordComma
    {
        class Program
        {
            static int Main(string[] args)
            {
                var cmd = new RootCommand
                {
                    new Argument<string[]>("names")
                };

                cmd.Handler = CommandHandler.Create<string[]>(Handler);

                return cmd.Invoke(args);
            }

            static void Handler(string[] names)
            {
                Console.WriteLine($"{String.Join(", ", names.Take(names.Length -1))}, and {names.Last<string>()}");
            }
        }
    }
    ```

=== "Python"

    ```py
    #!/usr/bin/env python3

    import argparse


    def get_args():
        p = argparse.ArgumentParser(description="Listing args with Oxford comma")
        p.add_argument("words", nargs="+", help="Words to concatenate using Oxford comma")
        return p.parse_args()


    def oxford_commafy(words):
        l = len(words)
        if l > 2:
            words[-1] = f"and {words[-1]}"
            print(", ".join(words))
        elif l == 2:
            print(f"{words[0]} and {words[1]}")
        else:
            print(words[0])


    def main():
        args = get_args().words
        oxford_commafy(args)


    if __name__ == "__main__":
        main()
    ```

### Calculator

=== "Python (argparse)"

    ```py
    import argparse


    def get_args():
        parser = argparse.ArgumentParser()
        parser.add_argument("operand1", type=float)
        parser.add_argument("operand2", type=float)
        op = parser.add_mutually_exclusive_group()
        op.add_argument("-a", "--add", dest="add", action="store_true")
        op.add_argument("-s", "--subtract", action="store_true")
        op.add_argument("-d", "--divide", action="store_true")
        op.add_argument("-m", "--multiply", action="store_true")
        return parser.parse_args()


    def main():
        args = get_args()
        if args.add:
            print("Adding")
            print(args.operand1, " + ", args.operand2, " = ", args.operand1 + args.operand2)
        elif args.subtract:
            print("Subtracting")
            print(args.operand1, " - ", args.operand2, " = ", args.operand1 - args.operand2)
        elif args.divide:
            print("Dividing")
            print(args.operand1, " / ", args.operand2, " = ", args.operand1 / args.operand2)

        elif args.multiply:
            print("Multiplying")
            print(args.operand1, " * ", args.operand2, " = ", args.operand1 * args.operand2)
        else:
            print("Unknown operation!")


    if __name__ == "__main__":
        main()
    ```

### Input validation

=== "C#"

    ```csharp
    string input;
    int inputParsed;
    while (true)
    {
        input = System.Console.ReadLine();
        try
        {
            inputParsed = int.Parse(input);
            break;
        }
        catch {
            System.Console.WriteLine("Please input a number...");
        }
    }
    System.Console.WriteLine($"Number provided: {inputParsed}");
    ```

## Object-oriented programming

### DnD character




=== "C#"

    === "Constructor"

        ```csharp
        class Character
        {
            private int StrengthAbility;
            private int DexterityAbility;
            private int ConstitutionAbility;
            private int IntelligenceAbility;
            private int WisdomAbility;
            private int CharismaAbility;
            private Race Race { get; }

            public Character(Race race)
            {
                this.StrengthAbility = AbilityRoll();
                this.DexterityAbility = AbilityRoll();
                this.ConstitutionAbility = AbilityRoll();
                this.IntelligenceAbility = AbilityRoll();
                this.WisdomAbility = AbilityRoll();
                this.CharismaAbility = AbilityRoll();
                this.Race = race;
            }

            public Character() : this(Race.HUMAN) { }
        }
        ```

    === "Properties"

        ```csharp
        public int Strength
        {
            get
            {
                return StrengthAbility + GetModifier(StrengthAbility) + GetRaceModifier(Abilities.STRENGTH);
            }
        }
        public int Dexterity
        {
            get
            {
                return DexterityAbility + GetModifier(DexterityAbility) + GetRaceModifier(Abilities.DEXTERITY);
            }
        }
        public int Constitution
        {
            get
            {
                return ConstitutionAbility + GetModifier(ConstitutionAbility) + GetRaceModifier(Abilities.CONSTITUTION);
            }
        }
        public int Intelligence
        {
            get
            {
                return IntelligenceAbility + GetModifier(IntelligenceAbility) + GetRaceModifier(Abilities.INTELLIGENCE);
            }
        }
        public int Wisdom
        {
            get
            {
                return WisdomAbility + GetModifier(WisdomAbility) + GetRaceModifier(Abilities.WISDOM);
            }
        }
        public int Charisma
        {
            get
            {
                return CharismaAbility + GetModifier(CharismaAbility) + GetRaceModifier(Abilities.CHARISMA);
            }
        }
        ```

    === "Methods"

        ```csharp
        public void Report()
        {
            Console.Write($"Strength: {Strength,2}");
            Console.Write($"Dexterity: {Dexterity,2}");
            Console.Write($"Constitution: {Constitution,2}");
            Console.Write($"Intelligence: {Intelligence,2}");
            Console.Write($"Wisdom: {Wisdom,2}");
            Console.Write($"Charisma: {Charisma,2}");
        }

        static int Roll(int ceiling)
        {
            Random rng = new Random();
            return rng.Next(1, ceiling);
        }

        static int AbilityRoll()
        {
            List<int> rolls = new List<int> { Roll(6), Roll(6), Roll(6), Roll(6) };
            rolls.Remove(rolls.Min());

            return rolls.Sum();
        }

        public static int GetModifier(int ability)
        {
            return (int)System.Math.Floor(((double)ability - 10) / 2);
        }
        ```

=== "Python"

    === "Constructor"

        ```python
        class Character:
            def __init__(self, race: Race = Race.HUMAN):
                self._strength_ability = self.ability_roll()
                self._dexterity_ability = self.ability_roll()
                self._constitution_ability = self.ability_roll()
                self._intelligence_ability = self.ability_roll()
                self._wisdom_ability = self.ability_roll()
                self._charisma_ability = self.ability_roll()
                self._race = race
        ```


    === "Properties"

        ```python
        @property
        def Strength(self):
            return self._strength_ability + self.get_modifier(self._strength_ability)

        @property
        def Dexterity(self):
            return self._dexterity_ability + self.get_modifier(self._dexterity_ability)

        @property
        def Constitution(self):
            return self._constitution_ability + self.get_modifier(
                self._constitution_ability
            )

        @property
        def Intelligence(self):
            return self._intelligence_ability + self.get_modifier(
                self._intelligence_ability
            )

        @property
        def Wisdom(self):
            return self._wisdom_ability + self.get_modifier(self._wisdom_ability)

        @property
        def Charisma(self):
            return self._charisma_ability + self.get_modifier(self._charisma_ability)
        ```
        
    === "Methods"

        ```python
        @staticmethod
        def Roll(range: int = 6):
            return random.randrange(range) + 1

        @staticmethod
        def get_modifier(score: int):
            return math.floor((score - 10) / 2)

        @classmethod
        def ability_roll(cls):
            rolls = [cls.Roll(), cls.Roll(), cls.Roll(), cls.Roll()]
            rolls.remove(min(rolls))
            return sum(rolls)

        def report(self):
            print(f"Strength: {self.Strength}")
            print(f"Dexterity: {self.Dexterity}")
            print(f"Constitution: {self.Constitution}")
            print(f"Intelligence: {self.Intelligence}")
            print(f"Wisdom: {self.Wisdom}")
            print(f"Charisma: {self.Charisma}")
        ```

### RPG character generator

=== "Player class"

    === "C++"   

        ```cpp
        #include <string>

        class Player {
        protected:
        std::string _name{ "Johnny Bravo" };
        Race _race{Race::HUMAN };
        int _hp{ 100 };
        int _mp{ 100 };

        public:
        Player(std::string n, Race r, int hp, int mp) : _name{n}, _race{r}, _hp(hp), _mp(mp) {}
        virtual std::string attack()= 0;
        int getHp()                 { return _hp;   }
        int getMp()                 { return _mp;   }
        
        std::string getRace()              
        {
            switch (_race)
            {
            case 0:
            return "human";
            break;
            
            case 1:
            return "elf";
            break;
            case 2:
            return "dwarf";
            break;

            default:
            return "none";
            break;
            }
        }
        std::string getName()       { return _name; }
        void setHp(int n)           { _hp = n;   }
        void setMp(int n)           { _mp = n;   }
        void setName(std::string s) { _name = s; }
        void setRace(Race r)        { _race = r;}
        };
        ```

    === "Python"

        ```py
        class Player():
            def __init__(self, name : str, race: Race, hp : int, mp : int):
                self._name = name
                self._race = race
                self._hp = hp
                self._mp = mp
            
            @property
            def getName(self):
                return self._name
            
            @property
            def getRace(self):
                return self._race
            
            @property
            def getHp(self):
                return self._hp
            
            @property
            def getMp(self):
                return self._mp
            
            def attack(self):
                return "Have at thee!"
        ```

=== "Subclasses"

    === "C++"

        ```cpp
        class Warrior : public Player {
        public:
        Warrior(std::string n, Race r) : Player(n, r, 200, 0) {}
        std::string attack() {return "I will destroy you with my sword, foul demon!";}
        };

        class Priest : public Player {
        public:
        Priest(std::string n, Race r) : Player(n, r, 100, 200) {}
        std::string attack() {return "Taste the wrath of the Two True Gods!";}
        };

        class Mage : public Player {
        public:
        Mage(std::string n, Race r) : Player(n, r, 150, 150) {}
        std::string attack() {return "You are overmatched by my esoteric artifices!";}
        };
        ```

    === "Python"

        ```py
        class Warrior(Player):
            def __init__(self, name : str, race: Race):
                super().__init__(name, race, 200, 0)
            def attack(self):
                return "I will destroy with my sword, foul demon!"

        class Priest(Player):
            def __init__(self, name: str, race: Race):
                super().__init__(name, race, 100, 200)
            def attack(self):
                return "Taste the wrath of the Two True Gods!"

        class Mage(Player):
            def __init__(self, name:str, race:Race):
                super().__init__(name, race, 150, 150)
            def attack(self):
                return "You are overmatched by my esoteric artifices!"
        ```

=== "Race"

    === "C++"

        ```cpp
        enum Race { 
            HUMAN, 
            ELF, 
            DWARF
        };
        ```

    === "Python"
    
        ```py
        import enum

        class Race(enum.Enum):
            HUMAN = enum.auto(),
            ELF = enum.auto(),
            DWARF = enum.auto()
        ```



### Starships

This demonstration project provides a scenario for implementing OOP and TDD principles in a variety of languages and implementations.

**Oficer** and **Starship** are simple classes with intuitive properties and fields.
The **StarshipClass** enum defines the available starship types.
**Fleet** serves as a container for Starships.



=== "Officer"

    === "C#"

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


    === "PowerShell"

        ```powershell
        class Captain
        {
            [string]$FirstName
            [string]$LastName
            [DateTime]$BirthDate

            Captain([string]$n1 [string]$n2)
            {
                $this.FirstName = $n1
                $this.LastName = $n2
            }

            [string]Name() { return "$($this.FirstName) $($this.LastName)" }
        }
        ```

    === "C++"

        ```cpp
        #include <string>

        class Officer
        {
        private: 
            std::string _firstName {};
            std::string _lastName {};
            
            std::string Name() { return _firstName + _lastName; }
        }
        ```

    === "Python"

=== "Starship"

    === "C#"

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

    === "PowerShell"

    === "C++"

        ```cpp
        class Starship
        {
        private:
            std::string _name{};
            std::string _reg{};
            StarshipClass _starshipclass{};
            int _crew{};

        public:
            Starship() = default;
            Starship(std::string n, std::string r, StarshipClass cls) : _name {n}, _reg {r}, _starshipclass {cls} {};
            ~Starship() = default;
            int getCrew()             { return _crew; }
            std::string getName()     { return _name; }
            std::string getRegistry() { return _reg; }
            std::string getClass();
        };

        std::string Starship::getClass() 
        {
            switch (_starshipclass)
            {
                case 2:
                    return "Constitution";
                    break;
                
                default:
                    return "Other";
                    break;
            }
        }

        #endif // STARSHIP_H
        ```

    === "Python"

        ```py
        class Starship:
            def __init__(
                self,
                name=None,
                starshipclass: StarshipClass = StarshipClass.NX,
                registry=None,
                crew=0,
            ):
                self.name = name
                self.registry = registry
                self._crew = crew
                self.crew_on_leave = 0
                self._starshipclass = starshipclass

            @property
            def crew(self):
                return self._crew

            @crew.setter
            def crew(self, crew: int):
                if crew < 0:
                    raise Exception
                else:
                    self._crew = crew

            @property
            def starshipclass(self):
                return self._starshipclass

            @starshipclass.setter
            def starshipclass(self, starshipclass: StarshipClass):
                if starshipclass not in StarshipClass:
                    raise Exception
                else:
                    self._starshipclass = starshipclass
        ```


=== "StarshipClass"

    === "C#"

        ```csharp
        public enum StarshipClass
        {
            NX,
            GALAXY,
            CONSTITUTION,
            SOVEREIGN,
            DEFIANT,
            INTREPID,
            MIRANDA
        }
        ```

    === "PowerShell"

    === "C++"

        ```cpp
        enum StarshipClass 
        {
            NX = 0
            GALAXY = 1,
            CONSTITUTION = 2,
            SOVEREIGN = 3,
            DEFIANT = 4
            INTREPID = 5
            MIRANDA = 6
        };
        ```

    === "Python"

        ```py
        from enum import Enum
        class StarshipClass(Enum):
            NX = 'NX'
            GALAXY = 'Galaxy'
            CONSTITUTION = 'Constitution'
            SOVEREIGN = 'Sovereign'
            DEFIANT = 'Defiant'
            INTREPID = 'Intrepid'
            MIRANDA = 'Miranda'
        ```



A Captain is paired with a Starship to form a **StarshipDeployment**.
And the **CaptainSelector** class is passed to StarshipDeployment by dependency injection.

**CaptainSelector** evaluates whether the Officer provided has what it takes to ply the inky black.
This boils down to a check on the Grade property, which is simple to test in testing frameworks where a mocked Officer object can be set up with unsatisfactory Grade values.


=== "C#"

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



**StarshipValidator** makes a few key checks on the Starship object that is passed in upon instantiation.
These checks provide opportunities to mock Starship and Officer objects.

- `IsCaptained()` checks if the Starship has a Captain assigned
- `ValidateRegistry()` makes sure the Starship's registry number begins with NCC or NX
- `Evaluate()` runs all the other methods in the class and returns True only if all checks pass.

=== "C#"

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


**StarshipDeployment** takes a [StarshipValidator](#starshipvalidator) object by dependency injection, which it uses to perform checks on a given Starship upon invocation of `Deploy`, which returns a StarshipMission object.
This provides the opportunity to test a mocked validator for invocation of the `Evaluate()` method.

=== "C#"

    ```csharp
    public class StarshipDeployment
    {
        public IStarshipValidator StarshipValidator { get; set; }

        public StarshipDeployment(IStarshipValidator validator)
        {
            StarshipValidator = validator ?? throw new ArgumentNullException(nameof(validator));
        }

        public bool ValidateDestination(string destination)
        {
            return destination.Length > 1 ? true : false;
        }

        public StarshipMission Deploy(Starship starship, string destination)
        {
            bool destinationValidated = ValidateDestination(destination);
            bool starshipValidated = StarshipValidator.Evaluate();

            return destinationValidated && starshipValidated
                ? new StarshipMission { Starship = starship as Starship, Destination = destination }
                : throw new ArgumentException();
        }
    }
    ```



## Web frameworks

### API mirror

=== "FastAPI"

## Test-driven development

Conventionally, tests have a three-part structure:

1. Arrange
2. Act
3. Assert

A **unit test** tests a small piece of code independently of others, such as a module, function, or class.
An **automated unit test** runs without intervention and reports the pass or fail status of the test suite.
A strict unit test should run entirely in memory and not have any dependencies on the filesystem, network, or databases.

Each **test case** should exercise a unit of code and check if it works correctly.
A **test runner** runs many test cases and reports the results.
A **test suite** refers to a collection of test cases executed by a test runner. 
A **test fixture** is code that supports a test case by setting up data, implementing the Arrange step.
([src](https://app.pluralsight.com/course-player?clipId=fa55af11-913d-4171-a2b0-db9f75f249e1))

Test case names are typically verbose and descriptive about what is being tested. 
([src](https://app.pluralsight.com/course-player?clipId=d0ba9a90-d356-4db2-b021-4a590d605894))

A **spike** is an experiment without tests to ensure that an idea will work. Once the spike succeeds, the spike code is thrown away and the logic is recreated following TDD, starting with tests.






=== "Starship"

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


=== "Fleet"

    === "Python"

        === "unittest"

            ```py
            import unittest
            from starships import Starship, StarshipClass, Fleet


            class FleetTest(unittest.TestCase):
                def setUp(self):
                    self.fleet = Fleet()

                def tearDown(self) -> None:
                    super().tearDown()

                def test_lookup_by_name(self):
                    self.fleet.add(
                        Starship("USS Enterprise", "NCC-1701", StarshipClass.CONSTITUTION)
                    )
                    ent = self.fleet.lookup("USS Enterprise")
                    self.assertEqual("NCC-1701", ent.registry)

                def test_missing_name(self):
                    with self.assertRaises(KeyError):
                        self.fleet.lookup("bla")
            ```

=== "CaptainSelector"

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

=== "StarshipValidator"

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

=== "StarshipDeployment"

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

## Glossary


#### C

> "A programming language is low level when its programs require attention to the irrelevant." -Alan Perlis

Despite C's reputation as a low-level programming language, in fact it merely emulates the ancient PDP-11, which is the only machine for which its abstract machine can be described as "close to the metal". 
In the age of parallel processes, C's serial nature...

Sources:

- [C is not a low-level programming language](https://queue.acm.org/detail.cfm?id=3212479)



#### Enumeration

In C# the term **enumeration** refers to the process of successively returning individual values. In Python, the term **iteration** is used to refer to the same thing, and **iterable** refers to an object that can be iterated, or parsed out into sub-elements.

- In Python, any object that exposes the `__iter__()` and `__next__()` **dunder** methods are iterable.
- In C#, **`IEnumerable`**&#10;The `IEnumerable` interface implements enumeration.

Both languages feature a keyword that allows a subclass to access its direct parent.
Whereas in Python the terms **superclass** and **subclass** are used, in C# the terms **base class** and **derived class** are preferred.

#### Go

Golang or "**Go**" is a fast, high-performance, open-source, statically-typed compiled programming language. It was designed at Google by Rob Pike, Robert Giesemer, and Ken Thompson and first appeared in late 2009. Go has a syntax similar to C, but offers additional features such as memory safety, garbage collection, and others. [[2](#sources)]\
Hello world
```go
package main
import "fmt"
func main() {
  fmt.Println("Hello, Go World!")
}
```
Compile code [[3](#sources)]
```sh
go build script.go # compiles to a binary executable in the same directory named "script"
go run script.go   # compiles and runs the program
```

Mathematical function [[3](#sources)]
```go
package main

import ("fmt" "math")

func main() {
  fmt.Println(math.Max(9, 5))
}
```
Get a GitHub package named `$REPO` by `$AUTHOR`
```sh
go get github.com/$AUTHOR/$REPO
go get gopkg.in/kyokomi/emoji.v1 # Emoji support
```
Evaluate type of data
```go
package main
import ("fmt" "reflect")
func main() {
  fmt.Println(reflect.TypeOf(1))        # => int
  fmt.Println(reflect.TypeOf(9.5))      # => float64
  fmt.Println(reflect.TypeOf("string")) # => string
  fmt.Println(reflect.TypeOf(true))     # => bool
}
```

Sources:

- [Go language for beginners in 16 parts](https://dzone.com/articles/go-language-for-beginners-in-16-parts)




#### Loop unswitching

One of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control

#### Mock

**Mock objects** include a variety of concepts that together comprise a taxonomy of Test Doubles (generically called **mocks**) used to facilitate unit testing by replacing a production object, usually a data dependency: ([src](https://app.pluralsight.com/course-player?clipId=ee56caf3-8cde-4298-8c06-e74241c72023))

- **Fakes** provide a working implementation of the dependency, however one which is unsuitable for production (e.g. in-memory databases)
- **Dummies** are passed around like real implementations but never accessed or used.  These are used to satisfy the parameters of a method.
- **Stubs** can provide answers to calls in the form of property gets and method return values.
- **Mocks** allow the tester to verify that a property or method was called.

#### Register rename engine

Component of modern high-end cores which is one of the largest consumers of die area and power

#### Ruby

REPL shell
```sh
irb
```
Begin a function definition
```rb
def
```
End a function definition
```rb
end
```
Import {package}, or 'gem'
```rb
require package
```
Write given objects to `ios`; writes newline after any that do not already have one
```rb
puts(*obj)
```
Write given objects to `ios`, with no newline
```rb
print(*obj)
```
Sort in-place
```rb
array.sort()
```

#### Rust 

- `cargo` Rust's compilation manager, package manager, and general-purpose tool
- `rustc` Rust compiler, usually invoked by `cargo`
- `rustdoc` Rust documentation tool

Start a new package directory `hello`
```sh
cargo new --bin hello
```
Load the locally-stored Rust book "The Rust Programming Language"
```sh
rustup doc --book
```

`->` precedes return data type

`mut` mutable, when preceding variable identifiers, allows their values to be changed

Data types include:
- `u64` unsigned 64-bit integer
- `i32` signed 32-bit integer
- `u8` unsigned 8-bit integer (byte values)
- `f32` single-precision floating point
- `f64` double-precision floating point


#### Scalar Replacement Of Aggregates

**Scalar Replacement Of Aggregates (SROA)** is one of the core optimizations that a [C](#c) compiler performs; attempts to replace `struct`s and arrays with fixed lengths with individual variables, which allows the compiler to treat accesses as independent and elide operations entirely if it can prove the results are never visible, which also deletes padding sometimes.

#### Segmented architecture

Pointers might be segment IDs and an offset
