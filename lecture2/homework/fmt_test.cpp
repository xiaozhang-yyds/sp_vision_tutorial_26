#include <fmt/core.h>



int main() {
    fmt::print("|{:10}|\n", "left");     
    fmt::print("|{:>10}|\n", "right");   
    fmt::print("|{:^10}|\n", "center");  
    fmt::print("|{:*^10}|\n", "cool");  
    
    fmt::print("{} are admitted to {}\n", "zlw","TSinghua University");
    return 0;
}
