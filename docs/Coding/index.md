# Overview

## Text
### Hello, world!

=== "Hello, world!"

    !!! py "&nbsp;"
        ```py
        "Hello, world!"
        ```

    !!! rs "&nbsp;"
        --8<-- "includes/Coding/Rust/hw.md"


    ??? cs "&nbsp;"
        ```csharp
        Console.WriteLine("Hello World!");
        ```

=== "Parameterized"

    !!! py "&nbsp;"
        --8<-- "includes/Coding/Python/hwp.md"

    !!! rs "&nbsp;"
        --8<-- "includes/Coding/Rust/hwp.md"

    ??? cs "&nbsp;"
        --8<-- "includes/Coding/C-Sharp/hwp.md"


=== "Interactive"

    !!! py "&nbsp;"
        --8<-- "includes/Coding/Python/hwi.md"

    !!! rs "&nbsp;"
        --8<-- "includes/Coding/Rust/hwi.md"

        
=== "CLI framework"

    !!! py "&nbsp;"
        === "argparse"
            --8<-- "includes/Coding/Python/hwp-argparse.md"

    !!! rs "&nbsp;"
        === "clap"
            --8<-- "includes/Coding/Rust/hw-clap.md"

## Numbers

=== "Weight on Mars"

    !!! rs "&nbsp;"
        --8<-- "includes/Coding/Rust/mars.md"

    !!! py "&nbsp;"
        --8<-- "includes/Coding/Python/mars.md"

=== "Double array"

    !!! py "&nbsp;"

        === "List comprehension"

            ```py
            [ 2 * el for el in primes ]
            ```
            
        === "map()"

            ```py
            primes = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23]
            double = lambda x: 2*x
            list(map(double, primes))
            ```


Parse a date string

??? cs "&nbsp;"


    === "`TryParse`"

        ```csharp linenums="1" hl_lines="8"
        namespace Program
        {
            class Program
            {
                static void Main()
                {
                    string rawDate = "07/04/1776";
                    DateTime.TryParse(rawDate, out parsedDate);
                    Console.WriteLine(parsedDate.ToLongDateString()); // => "July 4, 1776"
                }
            }
        }
        ```

    === "`try/catch`"
   
        ```csharp linenums="1" hl_lines="8-15"
        namespace Program
        {
            class Program
            {
                static void Main()
                {
                    string rawDate = "07/04/1776";
                    try 
                    {
                        DateTime parsedDate = DateTime.Parse(rawDate);
                    }
                    catch (FormatException)
                    {
                        Console.WriteLine("Unparsable!")
                    }
                }
            }
        }
        ```

## File operations



=== ":material-plus: Create"

    ??? cs "&nbsp;"

        ```csharp
        using (StreamWriter writer = File.CreateText("test.txt"))
        {
            writer.WriteLine("Hello, world!");
        }
        ```

    !!! py "&nbsp;"

        ```py
        with open('text', 'w') as f:
            f.write('Hello, world!')
        ```

=== ":material-eye: Read"

    ??? cs "&nbsp;"

        === "ReadAllText"

            ```csharp
            using System.IO;

            string raven = File.ReadAllText("raven");
            ```

        === "ReadAllLines"

            ```csharp
            using System.IO;

            string[] raven = File.ReadAllLines("raven");
            ```

        Using `StreamReader` objects

        === "ReadToEnd"

            ```csharp
            using System.IO;

            using (StreamReader reader = File.OpenText("raven"))
            {
                reader.ReadToEnd();
            }
            ```

        === "Loop"

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

    !!! py "&nbsp;"

        ```py
        with open('raven') as f:
            f.readlines()
        ```


=== ":material-content-copy: Copy"

    ??? cs "&nbsp;"

        ```csharp
        using System.IO;

        File.Copy('raven', 'raven.bak', true)
        ```

    !!! py "&nbsp;"

        ```python
        import shutil

        shutil.copyfile('raven', 'raven.bak')
        ```

=== ":material-file-move: Move"

    ??? cs "&nbsp;"

        ```csharp
        using System.IO;

        File.Move('raven', 'raven.bak');
        ```


### Text output

!!! rs "&nbsp;"

    ```rs
    fn main() {
        let args: Vec<String> = std::env::args().collect();

        let filename = &args[1];

        let contents = std::fs::read_to_string(filename)
            .expect("Couldn't read file");

        println!("{}", contents);
    }
    ```

### Data file formats

=== "CSV"


    !!! py "&nbsp;"

        ```py
        import csv

        with open ("greeks.csv") as f:
            r = csv.reader(f)
            headers = next(r)
            data = [row for row in r]
        ```

    ??? cs "&nbsp;"

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

=== "JSON"

    ??? cs "&nbsp;"

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

=== "Integer"

    ??? cs "&nbsp;"

        ```csharp
        Random r = new System.Random();
        int result = r.Next(1, 6);
        ```

    !!! py "&nbsp;"

        ```py
        import random
        random.randrange(1,6)
        ```

=== "Real number"

    ??? cs "&nbsp;"

        ```csharp
        Random r = new System.Random();
        int result = r.NextDouble();
        ```

    !!! py "&nbsp;"

        ```py
        import random
        random.random()
        ```




### String formatting


```
Socrates   Athens         470 BC
Plato      Athens         428 BC
Aristotle  Stagira        384 BC
Euclid     Alexandria     325 BC
Pythagoras Samos          570 BC
```

??? cs "&nbsp;"

    In C#, multidimensional arrays cannot be traversed with the `foreach` loops which appear to flatten its structure.

    ```csharp
    for (int i = 0; i <= greeks.GetUpperBound(0); i++)
    {
        Console.WriteLine("{0,-10} {1,-10} {2,10}", greeks[i,0], greeks[i,1], greeks[i,2]);
    }
    ```

!!! py "&nbsp;"

    ```py
    for r in greeks:
        print("{0:10} {1:10} {2:>10}".format(r[0],r[1],r[2]))
    ```
    
    

Currency formatting

??? cs "&nbsp;"

    ```csharp
    Console.WriteLine($"{123456.789:C }");          //  $123,456.79
    Console.WriteLine(123456.789d.ToString("C"));   //  $123,456.79
    ```

!!! py "&nbsp;"

    === "f-string"

        ```py
        f"${123456.789:,.2f}"                           #   $123,456.79
        ```

    === "locale module"

        Formatting a number in currency requires use of the **locale** module, and for the locale environment variables to be set.

        ```py
        import locale
        
        locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
        locale.currency(123456.789)                 #   $123456.79
        ```

## Network

[**Berkeley sockets <sup>:material-wikipedia:</sup>**](https://en.wikipedia.org/wiki/Berkeley_sockets) have formed the basis of modern network communication since their introduction in the early 1980s. 
The use of the term "socket" to refer to an endpoint for communication began as early as [1971 <sup>:material-wikipedia:</sup>](https://en.wikipedia.org/wiki/Network_socket#History) with ARPANET.
As a concept it belongs in the Session layer of the OSI model.

The original Berkeley sockets API, written in C, has been maintained in implementations of other languages

- Python's [**socket module <sup>:material-language-python:</sup>**](https://docs.python.org/3/library/socket.html)
- Rust's [**net** module <sup>:material-language-rust:</sup>](https://doc.rust-lang.org/std/net/index.html)

The API:

- **socket()** creates a new socket in the operating system, identified by an integer. It returns a file descriptor
- **bind()** associates a socket with an *address structure*: IP address and port number
- **listen()** blocks for incoming connections
- **accept()** creates a new TCP connection from the remote client

### Echo server

An echo server simply reflects text sent to it over a TCP connection

- Both Python's **socket** object and Rust's **TcpListener** object expose a `bind()` method, although in Rust host and port are combined in a string, whereas in Python they are passed as a `(str,int)` tuple.
- Both implementations expose an `accept()` method that returns a tuple, but in Python the tuple returned contains the **socket** (named "conn") object and a nested tuple that contains the address of the client.
In Rust, the equivalent to the connection object seems to be a **TcpStream** object ...
    - This object contains binary data which must be put into a buffer. 
    In Rust the buffer is passed as a mutable reference to the `read()` method (i.e. `read(&mut buffer)`). The buffer size is determined by the size of the initialized buffer.
    - In Python the binary information is assigned to a variable using the `recv()` method, which does take an integer argument specifying the buffer size.

```
echo "Hello, world!" | netcat localhost 8080
```

!!! rs "&nbsp;"

    ```rs
    use std::net::TcpListener;
    use std::io::Read;

    fn main() {
        let server = Server::new("127.0.0.1:8000".to_string());
        server.run();
    }

    pub struct Server {
        addr: String,
    }

    impl Server {
        pub fn new(addr: String) -> Self {
            Self { addr }
        }

        pub fn run(self) {
            println!("Listening on {}", self.addr);

            let listener = TcpListener::bind(&self.addr).unwrap();

            loop {
                match listener.accept() {
                    Ok((mut stream, _)) => {
                        let mut buffer = [0; 1024];
                        match stream.read(&mut buffer) {
                            Ok(_) => {
                                println!("Received request: {}", String::from_utf8_lossy(&buffer));
                            },
                            Err(e) => println!("Failed to read from connection: {}", e),
                        }
                    }
                    Err(e) => println!("Failed to establish a connection: {}", e), 
                }
            }
        }
    }
    ```

!!! py "&nbsp;"

    ```py
    import socket


    class Echo_Server:
        def __init__(self, address: str):
            self.addr = address

        def run(self):
            HOST = self.addr[: self.addr.find(":")]
            PORT = int(self.addr[self.addr.find(":") + 1 :])

            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.bind((HOST, PORT))
                s.listen()
                conn, addr = s.accept()
                with conn:
                    print(f"Received connection from {addr}")
                    while True:
                        data = conn.recv(1024)
                        if not data:
                            break
                        print(data.decode("utf-8"))
                        # conn.sendall(data) # Echo server


    def main():
        server = Echo_Server("127.0.0.1:8000")
        server.run()

    if __name__ == '__main__':
        main()
    ```

## Terminal
### Input validation loop

Such a loop will continuously prompt for valid input, in this case an integer.

??? cs "&nbsp;"

    === "TryParse"

        ```csharp
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

    === "try/catch"

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
        ```


!!! py "&nbsp;"

    ```py
    while True:
        try:
            option = int(input())
        except ValueError:
            # Integer was not able to be parsed
    ```

### Guessing game

!!! rs "&nbsp;"
    --8<-- "includes/Coding/Rust/guess.md"

### Oxford comma

??? cs "&nbsp;"

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

!!! py "&nbsp;"

    ```py
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


### Color output

=== ":red_square:"
    ??? cs "&nbsp;"

        ```csharp
        Console.Color = ConsoleColor.Red;
        Console.WriteLine("Red!")
        Console.ResetColor();
        ```

    !!! py "&nbsp;"

        ```python
        print(f"{colorama.Fore.RED} Red! {colorama.Style.RESET_ALL}")
        ```


=== ":green_square:"

    ??? cs "&nbsp;"
        ```csharp
        Console.Color = ConsoleColor.Green;
        Console.WriteLine("Green!")
        Console.ResetColor();
        ```

    !!! py "&nbsp;"
        ```python
        print(f"{colorama.Fore.GREEN} Green! {colorama.Style.RESET_ALL}")
        ```

=== ":yellow_square:"

    ??? cs "&nbsp;"

        ```csharp
        Console.Color = ConsoleColor.Yellow;
        Console.WriteLine("Yellow!")
        Console.ResetColor();
        ```

    !!! py "&nbsp;"

        ```python
        print(f"{colorama.Fore.YELLOW} Yellow! {colorama.Style.RESET_ALL}")
        ```

=== ":blue_square:"

    ??? cs "&nbsp;"

        ```csharp
        Console.Color = ConsoleColor.Blue;
        Console.WriteLine("Blue!")
        Console.ResetColor();
        ```

    !!! py "&nbsp;"

        ```python
        print(f"{colorama.Fore.BLUE} Blue! {colorama.Style.RESET_ALL}")
        ```

=== ":purple_square:"

    ??? cs "&nbsp;"

        ```csharp
        Console.Color = ConsoleColor.Magenta;
        Console.WriteLine("Magenta!")
        Console.ResetColor();
        ```

    !!! py "&nbsp;"

        ```python
        print(f"{colorama.Fore.MAGENTA} Magenta! {colorama.Style.RESET_ALL}")
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

### To-do app

Notably, the [dstask](https://github.com/naggie/dstask) Go application is a very sophisticated evolution of a terminal-based to-do app featuring subcommands, YAML-formatted tasks, and Git integration.

## TDD

Test fixture



## OOP

### DnD character

Generating a Dungeons 'n Dragons character provides the opportunity to exercise a variety of OOP techniques: public and private fields and properties and methods using simple arithmetic.

!!! info ""

    A Dungeons 'n Dragons character has six character attributes that can be randomly assigned.
    This process, called an **ability roll**, is calculated by rolling four six-sided dice (d6) and summing the highest three values, discarding the lowest.
    The raw ability score is then modified according to a [table](/Coding/DnD/#ability-modifiers) to produce a final ability score.

    In the implementations below, all ability scores are dynamically calculated using getter functions that sum the raw ability score (stored as a private field) and modifier.
    Both the ability roll and modifier lookup are implemented as public static functions.


!!! py "&nbsp;"

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
        class Character:
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

??? cs "&nbsp;"

    === "Constructor"

        ```csharp
        partial class Character
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
        partial class Character
        {
            public int Strength     { get => StrengthAbility + GetModifier(StrengthAbility) + GetRaceModifier(Abilities.STRENGTH) }
            public int Dexterity    { get => DexterityAbility + GetModifier(DexterityAbility) + GetRaceModifier(Abilities.DEXTERITY) }
            public int Constitution { get => ConstitutionAbility + GetModifier(ConstitutionAbility) + GetRaceModifier(Abilities.CONSTITUTION) }
            public int Intelligence { get => IntelligenceAbility + GetModifier(IntelligenceAbility) + GetRaceModifier(Abilities.INTELLIGENCE) }
            public int Wisdom       { get => WisdomAbility + GetModifier(WisdomAbility) + GetRaceModifier(Abilities.WISDOM) }
            public int Charisma     { get => CharismaAbility + GetModifier(CharismaAbility) + GetRaceModifier(Abilities.CHARISMA) }
        }
        ```

    === "Methods"

        ```csharp
        partial class Character
        {
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
        }
        ```


### RPG character generator

!!! py "&nbsp;"

    === "Player class"

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

        ```py
        import enum

        class Race(enum.Enum):
            HUMAN = enum.auto(),
            ELF = enum.auto(),
            DWARF = enum.auto()
        ```


??? cpp "&nbsp;"

    === "Player class"

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
    
    === "Subclasses"

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

    === "Race"

        ```cpp
        enum Race { 
            HUMAN, 
            ELF, 
            DWARF
        };
        ```


### Starships

This project provides a scenario for implementing OOP and TDD principles in a variety of languages and implementations.

Simple classes with intuitive properties and fields include **Officer** and **Starship**, which also has a field containing a variant of the **StarshipClass** enum.
**Fleet** serves as a container for Starships.
An Officer is paired with a Starship to form a **StarshipDeployment**.

**CaptainSelector**, which is passed to StarshipDeployment by dependency injection, evaluates whether the Officer provided has what it takes to ply the inky black.
This boils down to a check on the Officer's Grade property, which is simple to test in testing frameworks where a mocked Officer object can be set up with unsatisfactory Grade values.
    - StarshipDeployment also takes a **StarshipValidator** object by dependency injection, which it uses to perform checks on a given Starship.
These checks provide opportunities to mock Starship and Officer objects in unit testing.
        - `IsCaptained()` checks if the Starship has a Captain assigned
        - `ValidateRegistry()` makes sure the Starship's registry number begins with NCC or NX
        - `Evaluate()` runs all the other methods in the class and returns True only if all checks pass. This provides the opportunity to test a mocked validator for invocation of the `Evaluate()` method.

!!! rs "&nbsp;"
    === "Officer"
        --8<-- "includes/Coding/Rust/Starships/Officer.md"
    === "Starship"
        --8<-- "includes/Coding/Rust/Starships/Starship.md"

!!! py "&nbsp;"
    === "StarshipClass"
        --8<-- "includes/Coding/Python/Starships/StarshipClass.md"
    === "Starship"
        --8<-- "includes/Coding/Python/Starships/Starship.md"

??? cs "&nbsp;"
    === "StarshipClass"
        --8<-- "includes/Coding/C-Sharp/Starships/StarshipClass.md"
    === "Officer"
        --8<-- "includes/Coding/C-Sharp/Starships/Officer.md"
    === "CaptainSelector"
        --8<-- "includes/Coding/C-Sharp/Starships/CaptainSelector.md"
    === "StarshipValidator"
        --8<-- "includes/Coding/C-Sharp/Starships/StarshipValidator.md"
    === "StarshipDeployment"
        --8<-- "includes/Coding/C-Sharp/Starships/StarshipDeployment.md"

## 📘 Glossary

**C**
:   
    > "A programming language is low level when its programs require attention to the irrelevant." -Alan Perlis

    Despite C's reputation as a low-level programming language, in fact it merely emulates the ancient PDP-11, which is the only machine for which its abstract machine can be described as "close to the metal". 
    In the age of parallel processes, C's serial nature...

    Sources:

    - [C is not a low-level programming language](https://queue.acm.org/detail.cfm?id=3212479)

**Enumeration**
:   
    In C# the term **enumeration** refers to the process of successively returning individual values. 
    In Python, the term **iteration** is used to refer to the same thing, and **iterable** refers to an object that can be iterated, or parsed out into sub-elements.

    - In Python, any object that exposes the `__iter__()` and `__next__()` **dunder** methods are iterable.
    - In C#, the `IEnumerable` interface implements enumeration.

    Both languages feature a keyword that allows a subclass to access its direct parent.
    Whereas in Python the terms **superclass** and **subclass** are used, in C# the terms **base class** and **derived class** are preferred.

**Garbage collector**
:   
    A garbage collector is a feature of some programming language runtimes that periodically pauses execution to remove data that is no longer used.
    Such languages are considered unsuitable for use in database applications because of the unpredictable latency this garbage collection creates, despite the added memory safety.

**Loop unswitching**
:   
    One of the core optimizations that a C compiler performs; transforms a loop containing a conditional into a conditional with a loop in both parts, which changes flow control


**Register rename engine**
:   
    Component of modern high-end cores which is one of the largest consumers of die area and power


**Scalar Replacement Of Aggregates (SROA)**{: #sroa }
:   
    One of the core optimizations that a [C](#c) compiler performs; attempts to replace `struct`s and arrays with fixed lengths with individual variables, which allows the compiler to treat accesses as independent and elide operations entirely if it can prove the results are never visible, which also deletes padding sometimes.

**Segmented architecture**
:   
    Pointers might be segment IDs and an offset
