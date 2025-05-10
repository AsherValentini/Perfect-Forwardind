
//lvalue = value that i can get the address of directly. I can assign to it. Persistent name or object identitiy. Way to name or refer to a location in memory. 

//rvalue = value that i cannot get the address of directly. I cannot assign to it. Temporary or short lived. What we might called unnamed memory location. 

//lvalue_references = alias or another way to refer to a named location in memory. 

//rvalue_reference = create an alias for an rvalue

//Move semantics: this is where the sample code comes in: 

#include <iostream>
#include <string>
#include <utility>

int main() {

    std::string myString = "copy construct me"; 
    std::string newString; 

    std::cout << "myString: " << myString << std::endl; 
    std::cout << "newString: " << newString << std::endl; 


    //now lets implement some move semantics 
    //std::move(T name) essentially tells the compiler that the argument is ready to be moved 
    
    std::cout << "Moving data from myString to newString with move semantics: " << std::endl; 
    newString = std::move(myString); 

    std::cout << "myString: " << myString << std::endl; 
    std::cout << "newString: " << newString << std::endl; 

    //So what is std::move() actaully doing, well the way the compiler knows that the value is ready to be moved is by making it a rvalue_reference 
    //So lets show that by moving the data back to myString by casting newString as a rvalue_reference 
    myString = static_cast<std::string&&>(newString); 

    std::cout << "myString: " << myString << std::endl; 
    std::cout << "newString: " << newString << std::endl; 

    return 0; 

}