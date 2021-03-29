# 👨‍💻 Coding

## Simple structures

### Hello, world!

=== ":material-language-csharp:"

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

=== ":material-language-python:"

    ```py
    def main():
        "Hello, world!")

    if __name__ == "__main__":
        main()
    ```


### Dates and times

Parse a date string

=== ":material-language-csharp:"

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

### Write text file

=== ":material-language-csharp:"

    ```csharp
    using (StreamWriter writer = File.CreateText("test.txt"))
    {
        writer.WriteLine("Hello, world!");
    }
    ```

=== ":material-language-python:"

    ```py
    with open('text', 'w') as f:
        f.write('Hello, world!')
    ```

### Read text file

=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    string raven = File.ReadAllText("raven");
    ```

=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    string[] raven = File.ReadAllLines("raven");
    ```


=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    using (StreamReader reader = File.OpenText("raven"))
    {
        reader.ReadToEnd();
    }
    ```

=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    using (StreamReader reader = File.OpenText("raven"))
    {
        string s;
        while ((s = sr.ReadLine()) != null)
        {
            Console.WriteLine(s);
        }
    }
    ```

=== ":material-language-python:"

    ```py
    with open('raven') as f:
        f.readlines()
    ```

### Copy file

=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    File.Copy('raven', 'raven.bak')
    ```

=== ":material-language-python:"

    ```python
    import shutil

    shutil.copyfile('raven', 'raven.bak')
    ```

=== ":material-bash:"

    ```sh
    cp ./raven{,.bak}
    ```

=== ":material-powershell:"

    ```powershell
    Copy-Item .\raven .\raven.bak
    ```

### Copy file, overwriting

=== ":material-language-csharp:"

    ```csharp
    using System.IO;

    File.Copy('raven', 'raven.bak', true)
    ```

=== ":material-language-python:"

    ```python
    import shutil

    shutil.copyfile('raven', 'raven.bak')
    ```

=== ":material-bash:"

    ```sh
    cp -f ./raven{,.bak}
    ```

=== ":material-powershell:"

    ```powershell
    Copy-Item -Force .\raven .\raven.bak
    ```

### Move file

```csharp
using System.IO;

File.Move('raven', 'raven.bak');
```


### CSV

=== ":material-language-csharp:"

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

=== ":material-language-python:"

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

=== ":material-language-csharp:"

    ```csharp
    Random r = new System.Random();
    int result = r.Next(1, 6);
    ```

=== ":material-language-python:"

    ```py
    import random
    random.randrange(1,6)
    ```

Real number

=== ":material-language-csharp:"

    ```csharp
    Random r = new System.Random();
    int result = r.NextDouble();
    ```

=== ":material-language-python:"

    ```py
    import random
    random.random()
    ```

### Double array


=== ":material-language-python:"

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

=== ":material-language-csharp:"

    ```csharp
    for (int i = 0; i <= greeks.GetUpperBound(0); i++)
    {
        Console.WriteLine("{0,-10} {1,-10} {2,10}", greeks[i,0], greeks[i,1], greeks[i,2]);
    }
    ```

=== ":material-language-python:"

    ```py
    for r in greeks:
        print("{0:10} {1:10} {2:>10}".format(r[0],r[1],r[2]))
    ```
    
    In C#, multidimensional arrays cannot be traversed with the `foreach` loops which appear to flatten its structure.

Currency formatting

=== ":material-language-csharp:"

    ```csharp
    Console.WriteLine($"{123456.789:C }");          //  $123,456.79
    Console.WriteLine(123456.789d.ToString("C"));   //  $123,456.79
    ```

=== ":material-language-python:"

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

=== ":material-language-csharp:"

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

=== ":material-language-python:"

    ```py
    while True:
        try:
            option = int(input())
        except ValueError:
            # Integer was not able to be parsed
    ```

## Terminal

### Color output

=== ":material-language-csharp:"

    === ":red_square:"

        ```csharp
        Console.Color = ConsoleColor.Red;
        Console.WriteLine("Red!")
        Console.ResetColor();
        ```


    === ":green_square:"

        ```csharp
        Console.Color = ConsoleColor.Green;
        Console.WriteLine("Green!")
        Console.ResetColor();
        ```

    === ":yellow_square:"

        ```csharp
        Console.Color = ConsoleColor.Yellow;
        Console.WriteLine("Yellow!")
        Console.ResetColor();
        ```

    === ":blue_square:"

        ```csharp
        Console.Color = ConsoleColor.Blue;
        Console.WriteLine("Blue!")
        Console.ResetColor();
        ```

    === ":purple_square:"

        ```csharp
        Console.Color = ConsoleColor.Magenta;
        Console.WriteLine("Magenta!")
        Console.ResetColor();
        ```

=== ":material-language-python: colorama"

    === ":red_square:"

        ```python
        print(f"{colorama.Fore.RED} Red! {colorama.Style.RESET_ALL}")
        ```

    === ":green_square:"

        ```python
        print(f"{colorama.Fore.GREEN} Green! {colorama.Style.RESET_ALL}")
        ```

    === ":yellow_square:"

        ```python
        print(f"{colorama.Fore.YELLOW} Yellow! {colorama.Style.RESET_ALL}")
        ```

    === ":blue_square:"

        ```python
        print(f"{colorama.Fore.BLUE} Blue! {colorama.Style.RESET_ALL}")
        ```

    === ":purple_square:"

        ```python
        print(f"{colorama.Fore.MAGENTA} Magenta! {colorama.Style.RESET_ALL}")
        ```



### Parameterized "Hello, world!"

=== ":material-language-csharp:"

    ```csharp
    using System.CommandLine;
    using System.CommandLine.Invocation;

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
    ```

=== ":material-language-python:"

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

=== ":material-language-csharp:"

    ```csharp
    using System.CommandLine;
    using System.CommandLine.Invocation;
    using System.Linq;

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
    ```

=== ":material-language-python:"

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

=== ":material-language-python: (argparse)"

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

=== ":material-language-csharp:"

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

### Subcommands

```
./app command subcommand argument
```

=== ":material-language-csharp:"

    ```csharp
    static int Main(string[] args)
    {
        var rootCommand = new RootCommand("command");
        var command = new Command("subcommand")
        {
            new Argument<string>("argument");
        };
        command.Handler = new CommandHandler.Create<string>(argumentHandler);
        rootCommand.Add(command);
        rootCommand.Invoke(args);
    }

    private static void argumentHandler(string argument)
    {
        /* ... */
    }
    ```


## Object-oriented programming

### DnD character




=== ":material-language-csharp:"

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

=== ":material-language-python:"

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

    === ":material-language-cpp:"   

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

    === ":material-language-python:"

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

    === ":material-language-cpp:"

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

    === ":material-language-python:"

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

    === ":material-language-cpp:"

        ```cpp
        enum Race { 
            HUMAN, 
            ELF, 
            DWARF
        };
        ```

    === ":material-language-python:"
    
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

    === ":material-language-csharp:"

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


    === ":material-powershell:"

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

    === ":material-language-cpp:"

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

    === ":material-language-python:"

=== "Starship"

    === ":material-language-csharp:"

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

    === ":material-powershell:"

    === ":material-language-cpp:"

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

    === ":material-language-python:"

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

    === ":material-language-csharp:"

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

    === ":material-powershell:"

    === ":material-language-cpp:"

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

    === ":material-language-python:"

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


=== ":material-language-csharp:"

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

=== ":material-language-csharp:"

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

=== ":material-language-csharp:"

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
    fmt.Println(reflect.TypeOf(1))        // => int
    fmt.Println(reflect.TypeOf(9.5))      // => float64
    fmt.Println(reflect.TypeOf("string")) // => string
    fmt.Println(reflect.TypeOf(true))     // => bool
}
```

Sources:

- [Go language for beginners in 16 parts](https://dzone.com/articles/go-language-for-beginners-in-16-parts)




#### Loop unswitching

One of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control


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
