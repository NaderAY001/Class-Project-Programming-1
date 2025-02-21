/*
Author: nader abi younes
Date: 4/21/24
Language: C++
Assignment: Project A
Description: This project will show all the different skills
used in this course
*/

/*      MODIFICATIONS
 Feb 4 2024 - Completed header asking for name and
 outputing the first name back
 Feb 18 2024 - Gave user options to decide on square root,
 power of a number, finding out letter grade based on GPA, or exit
 Mar 3 2024 - Modified the welcome section to be more clean and
 efficent. Put the options and swicth in a loop until the user
 wants to exit. Added exit case and default to the switch. Added
 another option to make a triangle. Added box around options
 Mar 17 2024 - Modified swicth statement and commented on case
 4 and 0. Made cases 3 and 4 into user defined functions. made 2 more
 user defined functions. One for calculating weekly pay and one for
 showing yearly interest. I added them in the menu and fixed the box
 Apirl 7 2024 - I changed the global variables rate and hours to local
 and set then to 0.0. Made the orignal header into a user defined function.
 Made a user defined function for the user entering their first and last
 name then welcomes them.
 Apirl 21 2024 - I added a function to ask the user for 5 grades,
 display them and displays the average
 May 5 2024 - I added a structure for contacts and an user defined function 
 to display the prepopulated array of contacts
*/

#include <iostream>
#include <string> // for 2 last names
#include <cmath> // for some of the math functions
#include <iomanip> // for dollars and cents

using  namespace std;

//define structure
struct Contact
{
    string firstName;
    string lastName;
    string phoneNum;
};


//function prototypes
void GPA();
void rightTriangle();
void calculatePay(double rate, double hours);
void displayInterest();
void displayHeader();
void firstLastName(string&, string&);
void getGrades(double[], int);
void displayGrades(double[], int);
double averageGrade(double[], int);
void printContacts(Contact[]);

int main()
{
    //****** Variable section *********
    string firstName;
    string lastName;
    int personsChoice;
    int squareRoot, thePower, baseX, powerY;
    double rate = 0.0, hours = 0.0;
    const int ARRAY_SIZE = 5;
    double grades[ARRAY_SIZE];
    double average;
    Contact contactList[3] = 
    {
        "Kevin", "Roark", "210-837-0600",
        "Bart", "Simpson", "210-444-1234",
        "Sally", "Smith", "210-324-7895"
    };


    //****** Welcome Section **********
    //Output welcome header      
    //prompt user for first name and store   
    //prompt user for last name and store   
    //Output a welcome message to the user   

    //displays header
    displayHeader();

    //user enters first and last name and 
    firstLastName(firstName, lastName);

    //welcome user
    cout << "Welcome to my course project " << firstName
        << " " << lastName << "!" << endl;

    cout << "**********************************************\n";



    do
    {
        // box around the options
        cout << "\n|-------------------------------------------------------------------|\n";

        //give user the options to what they want to do
        cout << "|   Enter 1 to Calculate the square root"
            << "                            |" << endl;
        cout << "|   Enter 2 to Enter X to the Y power"
            << "                               |" << endl;
        cout << "|   Enter 3 to Convert the Numerical GPA "
            << " to a Letter Grade         |" << endl;
        cout << "|   Enter 4 to Create a Right Triangle"
            << "                              |" << endl;
        cout << "|   Enter 5 to Calculate weekly pay"
            << "                                 |" << endl;
        cout << "|   Enter 6 to Calculate interest earned"
            << "                            |" << endl;
        cout << "|   Enter 7 to Calculate grades"
            << "                                     |" << endl;
        cout << "|   Enter 8 to Print Contacts"
            << "                                       |" << endl;
        cout << "|   Enter 0 to exit"
            << "                                                 |" << endl;
        cout << "|-------------------------------------------------------------------|" << endl;

        // have user input their request
        cout << "Enter your request: ";
        cin >> personsChoice;

        //each case will take them to the option they requested
        switch (personsChoice)
        {

            //case 1 will square root the number they decide to input
        case 1:
            cout << "Enter a number to calculate the Square Root: ";
            cin >> squareRoot;

            cout << "The square root of " << squareRoot << " is "
                << sqrt(squareRoot) << endl;
            break;

            //case 2 will have them choose a base of X and a power of Y
            // and calculate
        case 2:
            cout << "Enter a number X to raise to the power Y\n";
            cout << "Enter X: ";
            cin >> baseX;
            cout << "Enter Y: ";
            cin >> powerY;

            cout << baseX << " to the " << powerY << " power is "
                << pow(baseX, powerY) << endl;
            break;

            //case 3 will ask for their GPA to convert to a letter grade
        case 3: GPA();
            break;

            // prompts user to enter a number for the size of their
            //triangle
        case 4: rightTriangle();
            break;

            // prompts user for the hourly pay and amount of hours worked
        case 5: calculatePay(rate, hours);
            break;

            // prompts user for an intial balance and percentage of 
            //yearly interest accquired on that balance and calculates
            // for the next 5 years
        case 6: displayInterest();
            break;

            // prompts user for 5 grades then displays them and averages
            //them out
        case 7: getGrades(grades, ARRAY_SIZE);
            displayGrades(grades, ARRAY_SIZE);
            average = averageGrade(grades, ARRAY_SIZE);
            cout << "The average grade is " << average << endl;
            break;

            //prints out contact list
        case 8: printContacts(contactList);
            break;

            //informs user program has ended
        case 0:
            cout << "You have exited the program.";
            return 0;

        default:
            //informs user if has input an unavaiable number
            cout << "Invaild Number\n";
        }
        //ends loop
    } while (personsChoice != 0);


    return 0;
} // end of main

//function definitions
void GPA()
{
    // declares local variables
    double  gradePointAverage;

    //prompts the user for their numerical grade
    cout << "Enter your numerical grade: ";
    cin >> gradePointAverage;


    // picks basaed on 4.0 gpa scale
    if (gradePointAverage == 4)
    {
        //if user has a 4.0 then they will get a A
        cout << "Your letter grade is an A\n";
    }
    //if user has a 3.0 then they will get a B
    else if (gradePointAverage >= 3)
    {
        cout << "Your letter grade is an B\n";
    }
    //if user has a 2.0 then they will get a C
    else if (gradePointAverage >= 2)
    {
        cout << "Your letter grade is an C\n";
    }
    //if user has a 1.0 then they will get a D
    else if (gradePointAverage >= 1)
    {
        cout << "Your letter grade is an D\n";
    }
    //if user has less than 1 then they get a F
    else
    {
        cout << "Your letter grade is an F\n";
    }
}

void rightTriangle()
{
    //declare local variable
    int triangleSize;

    // has user enter the size of a triangle they
    //want the program to make
    cout << "Enter the size of the triangle: ";
    cin >> triangleSize;

    //loop starts at 1 until it hits the size the user wants
    //for both asterisks and endlines 
    for (int i = 1; i <= triangleSize; i++)
    {
        cout << endl;
        for (int asterisks = 1; asterisks <= i; asterisks++)
        {
            cout << "*";
        }
    }
}

void calculatePay(double rate, double hours)
{
    //declare local variables
    double weeklySum;

    //prompts the user to input hourly rate and hours worked
    cout << "What is your hourly rate: ";
    cin >> rate;
    cout << "How many hours did you work this week: ";
    cin >> hours;

    //if hours are less than 40 they get paid by rate * hours
    //if hours are more than 40 they get paid rate * hours until 
    //they hit more than 40 hours. after that its (1.5 * rate) * hours
    if (hours <= 40)
    {
        //calculate normal hours and display it
        weeklySum = hours * rate;
        cout << "Your weekly pay is " << weeklySum << endl;
    }
    else
    {
        //calculate normal hours + overtime and display it
        weeklySum = (rate * 40) + ((hours - 40) * rate * 1.5);
        cout << "Your weekly pay is " << weeklySum << endl;
    }
}

void displayInterest()
{
    //declare local variables
    double intialBalance, interestRate, interest;

    //prompt user to enter intial balance
    cout << "Enter intial balance: ";
    cin >> intialBalance;

    //prompt user to enter intertest rate
    cout << "Enter yearly interest rate: ";
    cin >> interestRate;

    // increment up by one until it hits year 5
    for (int year = 1; year <= 5; year++)
    {
        //calculate total balance
        interest = intialBalance * interestRate;

        //add interest to each year
        intialBalance += interest;

        //display each years balance
        //sets 2 decimal places for cents
        cout << "Year " << year << ": " << fixed
            << setprecision(2) << intialBalance << endl;
    }

}

//displays header
void displayHeader()
{
    cout << "**********************************************\n"
        << "*        Programming 1 Course Project        *\n"
        << "**********************************************" << endl;

}

//asks user for first and last name
void firstLastName(string& usersFirstName, string& usersLastName)
{
    // usersFirstName is the variable for the user define function
    // firstName is a local variable for main
    cout << "Please enter your first name: ";
    cin >> usersFirstName;
    cout << "Please enter your last name: ";
    cin >> usersLastName;
}

//gets grades from user
void getGrades(double pGrades[], int pSize)
{
    //asks user for 5 grades
    for (int i = 0; i < pSize; i++)
    {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> pGrades[i];
    }
}

//displays the gardes input by user
void displayGrades(double pGrades[], int pSize)
{
    //set the grades to 2 decimal points
    cout << fixed << showpoint << setprecision(2);

    //shows user the 5 grades
    for (int i = 0; i < pSize; i++)
        cout << "Grade " << i + 1 << ": " << pGrades[i] << endl;
}

//calculates average of grades
double averageGrade(double pGrades[], int pSize)
{
    //declare local variables
    double sum = 0;

    // iterate throught array and add the grades to sum
    for (int i = 0; i < pSize; i++)
    {
        sum += pGrades[i];
    }

    //return sum/size to get average
    return (sum / pSize);
}

//prints contact list for user
void printContacts(Contact pContactList[])
{
    //for loop loops through the array to show all the information
    for (int i = 0; i < 3; i++)
    {
        cout << "Name: " << pContactList[i].firstName << " "
            << pContactList[i].lastName << endl;
        cout << "Phone Number: " << pContactList[i].phoneNum << endl;
    }
}