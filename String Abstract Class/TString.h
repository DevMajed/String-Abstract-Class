#define _CRT_SECURE_NO_WARNINGS
//  TString.hpp

#include <string.h>
#include <stdio.h>
#include <iostream>
#define strcpy_s(a, b, c) strncpy(a, c, b)


#ifndef TString_h
#define TString_h

#include <stdio.h>
#define strcpy_s(a, b, c) strncpy(a, c, b)
#include <string.h>


class TString
{

public:

    // default constructor
    TString(const char* pText = 0);

    //Copy Constructor
    TString(const TString& Object);

    // Destructor
    ~TString();

    // length Member Function
    int length() const;

    // asChar Member Function
    char* asChar() const;


    // Member Function To Assign a string or contant to another.
    void assign(const TString& Object);
    void assign(const char* pText);

    // To check equality
    bool equals(const TString& Object) const;

    // To find position of a char
    int indexOf(const char& Position) const;



private:
    // length of char data (not including null char)
    int mLength;
    // pointer to dynamic char array in heap ( Buffer )
    char* mpText;

};



#endif /* TString_hpp */
