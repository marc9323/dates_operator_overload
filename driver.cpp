/*
CIS 2542 - Advanced C++ Programming
Chapter # 2 - Overloaded Operators

2 / 12 / 2021
Marc D. Holman

MAIN DRIVER CLASS FOR LAb # 3

Description:  add requisite operator overloading to provided date class.
Please find test run with following dates attached to this document:

5/5/1977 10/24/1973
2/25/1944 9/30/1982
3/5/1999 3/7/1999
3/5/1999 3/5/1999

*/

#include <iostream>
#include "d_date.h"
#include <string>

using namespace std;


// free comparison functions (!= and == )
bool operator ==(const date& d1, const date& d2)
{
    return (d1.getDay() == d2.getDay()) && (d1.getMonth() == d2.getMonth()) && (d1.getYear() == d2.getYear());
}

bool operator !=(const date& d1, const date& d2)
{
    return !(d1 == d2);
}

int main(void)
{
    date date1;
    date date2;



    cout << "Enter date1 and date2:" << endl;

    while (cin >> date1 >> date2)
    {
        cout << "Printing date1 and date2" << endl;
        cout << date1 << endl << date2 << endl;

        if (date1 == date2)
            cout << date1 << " is equal to " << date2 << endl;

        if (date1 != date2)
            cout << date1 << " is not equal to " << date2 << endl;

        if (date1 < date2)
            cout << date1 << " is less than " << date2 << endl;

        if (date1 > date2)
            cout << date1 << " is greater than " << date2 << endl;

        date1++;
        date2++;

        cout << "Increment of date1: " << date1 << endl;
        cout << "Increment of date2: " << date2 << endl;

        cout << endl << "---End of Run---" << endl << endl;

        cout << "Enter date1 and date2:" << endl;
    }

    return EXIT_SUCCESS;

}


/*
*
* Sample run with dates provided:

Enter date1 and date2:
Month:
5
Day:
5
Year:
1977
Month:
10
Day:
24
Year:
1973
Printing date1 and date2
5/5/1977
24/10/1973
5/5/1977 is not equal to 24/10/1973
5/5/1977 is greater than 24/10/1973
Increment of date1: 6/5/1977
Increment of date2: 25/10/1973

---End of Run---

Enter date1 and date2:
Month:
2
Day:
25
Year:
1944
Month:
9
Day:
30
Year:
1982
Printing date1 and date2
25/2/1944
30/9/1982
25/2/1944 is not equal to 30/9/1982
25/2/1944 is less than 30/9/1982
Increment of date1: 26/2/1944
Increment of date2: 1/10/1982

---End of Run---

Enter date1 and date2:
Month:
3
Day:
5
Year:
1999
Month:
3
Day:
7
Year:
1999
Printing date1 and date2
5/3/1999
7/3/1999
5/3/1999 is not equal to 7/3/1999
5/3/1999 is less than 7/3/1999
Increment of date1: 6/3/1999
Increment of date2: 8/3/1999

---End of Run---

Enter date1 and date2:
Month:
3
Day:
5
Year:
1999
Month:
3
Day:
5
Year:
1999
Printing date1 and date2
5/3/1999
5/3/1999
5/3/1999 is equal to 5/3/1999
Increment of date1: 6/3/1999
Increment of date2: 6/3/1999

---End of Run---


*/

