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