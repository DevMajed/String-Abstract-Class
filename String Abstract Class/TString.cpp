#define _CRT_SECURE_NO_WARNINGS


#include "TString.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#define strcpy_s(a, b, c) strncpy(a, c, b)








// Initilazation Constructur
//----------------------------------------------------------\\
    // Constructor with default Value PText = nullptr, So no garbage values.
    // The point of it is ti give a name to the string and save content in it.
    // When user Call TString, then some name, this will make sure that some
    // chars interd bu the user stored in a pointer pText.
    // then we will make new memory adress for mpTest member and give it that
    // Data. this way we can use Tstring type for many variables.


    // parameterize constructor
TString::TString(const char* pText)
{
    // Allocating to Null
    if (pText == nullptr)

    {
        mLength = 0;
        mpText = new char[mLength + 1];
        mpText[mLength] = '\0';
    }

    // Allocating to the heap and copying the contant in the mpText pointer
    else
    {
        // Taking  length of the intered chars to alocate a memory adress.
        mLength = strlen(pText);
        // using new to make new memory adress in the heap for mpTest.
        mpText = new char[mLength + 1];
        // Giving the data from pText to mpText, Deep copy, this way we
        // can make many variables of type TString.
        strcpy(mpText, pText);
    }

    // Goal is done, Now mpText has memory adress and Data.

}

//----------------------------------------------------------\\







//Copy Constructor
//----------------------------------------------------------\\
    //It is called when any object created of the same type from an already
    //created object then it performs a deep copy. It allocates new space on
    //the heap for the object that is to be created and copies the contents
    //of the passed object(that is passed as a reference).
    // Wht const reference? because using by value will make shallow copy, By
    // reference will change the contant of the pointer so no need to return
    // which save time and memory, but const reference will insure that the
    // function does not change the value of the argument.
TString::TString(const TString& Object)
    : mLength(Object.mLength) // Cleaner initializer list instead of mLength = Object.mLength; in the body

{
    //  Ex: Tstring Majed (William);
     // dot operator to access members and function public
     // to that class and to give the length of the passed argument.
     // using new to make new memory adress in the heap for mpTest.
    mpText = new char[mLength + 1];
    // Copy the Object argument into mpText.
    strcpy(mpText, Object.mpText);

    // Now in example above, Majed is equal to the contant of William.
}
//----------------------------------------------------------\\






//Destructur
//----------------------------------------------------------\\
    //to Relese the Memory and t0o avoid memory leaking because
    //we used (new) and we got place in heap memory.

TString:: ~TString()
{
    delete[] mpText;
};



//----------------------------------------------------------\\
    




//Length member function
//----------------------------------------------------------\\

int TString::length() const
{
    return mLength;
    // Explanation of int length() const Member Function:
    // It is a Getter, we can't edit or motivy any of the class members.
    // the reason it is Const is that we dont want it to edit
    // the member that it will call, we just want int length.
    // No stuff in the bodt of the function because we just want to
    // make the user's life easier when they want the length they
    // write Majed.length(); for example,so it just directs mLength.
    // if we say const int* const int length () const, it will mean:
    // it means we returning a pointer thatn can't be modified,
    // The content of the pointer can't be modified, and the function
    // itself can't modify
}
//----------------------------------------------------------\\




// asChar member function
//----------------------------------------------------------\\
    // Returns a character representation of the given string.
    // without the need to allocate new memory for the returned chars.
    // Const Char* : returning a pointer thatn can't be modified,
    // asChar() Const: the function itself can't modify arguments.
    // it is orgnizer just like length

char* TString::asChar() const

{
    return mpText;
}
//----------------------------------------------------------\\




// Assign member function
//----------------------------------------------------------\\
    
void TString::assign(const TString& Object)
// This will do the assignment so each variable has its  own chars.
// calling by const reference so we won't change anything in Object.
// it check for assignment to self and return if true instead of wasting
// memory.
// if not, it uses delete to delete the contant of char array it points,
// Then it dynamically allocates new char array with the same size as
// the passed string and coppies the data from the passed string in the
// parameter to the char array.
// Example: assigning one string to other
// string str1 = "hello"
// string str2 = str1  // makes a new copy
// str1[0] = 'y'; // changes str1, but not str2

// To assign to self i'll ned ( this ) here
// The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
// "This" is a pointer to the current instance.

{
    // is the cuurent instance of Object equal to Object in this function? if yes return
    if (this == &Object)
    {
        return;
    }

    // if not equal, delete mpText, Give it a memory adress, copy the Pass Object to it.
    else
    {
        delete mpText;
        // use mLength through the dot operator
        mLength = (Object.mLength);
        mpText = new char[Object.mLength + 1];
        // Copt the current mpText from this function to the real mpText
        strcpy(mpText, Object.mpText);





    }
}

//----------------------------------------------------------\\




// Assign member function
//----------------------------------------------------------\\
    // it accepts a buffer, const char pointer to array of chars( the one we made in the constructor )
    // it does the same as the above function but at the pointer level.


void TString::assign(const char* pText)
{
    // if the two pointers equal to each other, save memory and return.
    if (mpText == pText)
    {
        return;
    }

    else


    {
        delete mpText;
        if (pText == nullptr)
        {
            mLength = 0;
            mpText = new char[mLength + 1];
            mpText[mLength] = '\0';
        }
        else
        {
            // use mLength through the dot operator
            mLength = strlen(pText);
            mpText = new char[mLength + 1];
            // Copt the current mpText from this function to the real mpText
            strcpy(mpText, pText);
        }
    }

}

//----------------------------------------------------------\\




// equals member function
//----------------------------------------------------------\\
// This will check if two strings are equal or not, otherways it will not edit any member.
    // Example:
    //string s1( "abc" );
    //string s2( "def" );
    //string s3( "abc" );
    //...
    //bool flag1 = ( s1 == s2 ); // flag1 = false now
    //bool flag2 = ( s1 == s3 ); // flag2 = true now

bool TString::equals(const TString& Object) const

{
    if (strcmp(mpText, Object.mpText) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//----------------------------------------------------------\\




// indexOf member function
//----------------------------------------------------------\\
// This one will accept a charictar and then it will search in the array of chars
// to see where is the position of that char.


int TString::indexOf(const char& Position) const


{
    int i;
    for (i = 0; i < mLength; i++)
    {
        if (mpText[i] == Position)
        {
            return i;
        }
    }
    return -1;

}
//----------------------------------------------------------\\


