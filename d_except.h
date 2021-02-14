/*
CIS 2542 - Advanced C++ Programming
Chapter # 2 - Overloaded Operators

2 / 12 / 2021
Marc D. Holman

 EXCEPTION HANDLING FOR DATE CLASS

Description:  add requisite operator overloading to provided date class.
Please find test run with following dates attached to driver.cpp file:

5/5/1977 10/24/1973
2/25/1944 9/30/1982
3/5/1999 3/7/1999
3/5/1999 3/5/1999

*/// Created by march on 2/14/2021.
//

//#ifndef FINAL3_D_EXCEPT_H
//#define FINAL3_D_EXCEPT_H
//
//#endif //FINAL3_D_EXCEPT_H

#ifndef EXCEPTION_CLASSES
#define EXCEPTION_CLASSES

#include <sstream>
#include <string>

using namespace std;

class baseException
{
public:
    baseException(const string& str = "") :
            msgString(str)
    {
        if (msgString == "")
            msgString = "Unspecified exception";
    }

    string what() const
    {
        return msgString;
    }

    // protected allows a derived class to access msgString.
    // chapter 13 discusses protected in detail
protected:
    string msgString;
};

// failure to allocate memory (new() returns NULL)
class memoryAllocationError : public baseException
{
public:
    memoryAllocationError(const string& msg = "") :
            baseException(msg)
    {}
};

// function argument out of proper range
class rangeError : public baseException
{
public:
    rangeError(const string& msg = "") :
            baseException(msg)
    {}
};

// index out of range
class indexRangeError : public baseException
{
public:
    indexRangeError(const string& msg, int i, int size) :
            baseException()
    {
        ostringstream indexErr;

        indexErr << msg << "  index " << i << "  size = " << size << ends;
        // indexRangeError can modify msgString, since it is in
        // the protected section of baseException
        msgString = indexErr.str();
    }
};

// attempt to erase from an empty container
class underflowError : public baseException
{
public:
    underflowError(const string& msg = "") :
            baseException(msg)
    {}
};

// attempt to insert into a full container
class overflowError : public baseException
{
public:
    overflowError(const string& msg = "") :
            baseException(msg)
    {}
};

// error in expression evaluation
class expressionError : public baseException
{
public:
    expressionError(const string& msg = "") :
            baseException(msg)
    {}
};

// bad object reference
class referenceError : public baseException
{
public:
    referenceError(const string& msg = "") :
            baseException(msg)
    {}
};

// feature not implemented
class notImplementedError : public baseException
{
public:
    notImplementedError(const string& msg = "") :
            baseException(msg)
    {}
};

// date errors
class dateError : public baseException
{
public:
    dateError(const string& first, int v, const string& last) :
            baseException()
    {
        ostringstream dateErr;

        dateErr << first << ' ' << v << ' ' << last << ends;
        // dateError can modify msgString, since it is in
        // the protected section of baseException
        msgString = dateErr.str();
    }
};

// error in graph class
class graphError : public baseException
{
public:
    graphError(const string& msg = "") :
            baseException(msg)
    {}
};

// file open error
class fileOpenError : public baseException
{
public:
    fileOpenError(const string& fname) :
            baseException()
    {
        ostringstream fileErr;

        fileErr << "Cannot open \"" << fname << "\"" << ends;
        // fileOpenError can modify msgString, since it is in
        // the protected section of baseException
        msgString = fileErr.str();
    }
};

// error in graph class
class fileError : public baseException
{
public:
    fileError(const string& msg = "") :
            baseException(msg)
    {}
};

#endif	// EXCEPTION_CLASSES
