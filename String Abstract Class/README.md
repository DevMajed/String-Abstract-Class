# String class Abstraction 

This is a String class that represents a character string abstraction where  C++ Standard Library string class (std::string) is not used. \
The objective of this project is to see what is happening under the hood of String classes in C++ or other languages.


Classs Functions: 


* A constructor accepting a const char pointer to an array of characters, with a default argument value of 0 (null pointer). If a null pointer or empty string (char array of length 1 containing a '\0' null char) is passed, it initializes this String object to point at a dynamically allocated character array of length 1  (containing the null char value '\0') in the heap. Otherwise, it dynamically allocates a char array of the same size as the parameter char array, and copies the parameter char data into it. Note that this is a deep copy (ie. copying all the char data) so that this object has it's own copy of the char data, vs. a shallow copy (just copying the pointer value to the parameter's char data). 

* A copy constructor accepting a String object (by const reference). It initializes this String from the parameter String object, making a deep copy of the character data by dynamically allocating a char array of the same size as the parameter String's, and copying the char data. 

* A destructor that uses the C++ delete operator to free the dynamic character array owned by this String, and then sets the mpText pointer member to null. This prevents the dynamic char array from becoming a memory leak. 

* A length member function returning the current size of the character data (not including the final null character). 

* An asChar member function returning a const char pointer to this String's encapsulated character data. It does not allocate new memory for the char data to be returned. 

* An assign member function accepting a String object parameter (by const reference), and a return type of void. It first checks for assignment to self and returns if true.  Otherwise, it uses delete to  release the current char array it points to, then dynamcally allocates a new char array of the same size as the parameter String's, and copies the character data from the parameter String. 

* An assign member function accepting a const char pointer to an array of characters, and a return type of void. It checks for assignment to self, and returns if true. Otherwise,  does the same as the other assign member function. 

* An equals member function accepting a String object parameter (by const reference), and a return type of bool. It compares the character data of this String with the character data of the parameter String object and returns true if they match, else false (the C++ string library function strcmp or strncmp can be used for the comparison). 

* An indexOf member function accepting a char parameter, and a return type of int.  It searches this String's character data for the first occurrence of the parameter character and returns the position if found (first character is position 0) or -1 if not found.

