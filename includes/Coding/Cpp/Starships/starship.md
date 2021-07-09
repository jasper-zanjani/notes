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