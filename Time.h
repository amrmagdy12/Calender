#ifndef TIME_H
#define TIME_H
#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    string daynight;

public:
    /** Constructor **/
    Time();
    /** Setters and Getters **/
    void setHour(int) ;
    int getHour() ;
    void setMinute(int) ;
    int getMinute() ;
    void setDayNight(string) ;
    string getDayNight() ;

    /** Input time **/
    friend istream& operator>>(istream& in, Time&);

    /** Output time **/
    friend ostream& operator<<(ostream& out, Time) ;

    /** Overloading relational operators to compare 2 time objects **/
    bool operator<(Time&);
    bool operator>(Time&);
    bool operator==(Time&);
    bool operator!=(Time&);
};

class Appointment
{
private:
    Time Start;
    Time End;

public:
    /** Constructor **/
    Appointment();

    /** Input an appointment **/
    friend istream& operator>>(istream& in, Appointment&);

    /** Output an appointment **/
    friend ostream& operator<<(ostream& out, Appointment);

    /** Overloading the relational operators to compare 2 appointment objects **/
    bool operator<=(Appointment);
    bool operator>=(Appointment);
    bool operator<(Appointment);
    bool operator>(Appointment);
    bool operator==(Appointment);
    bool operator!=(Appointment);
};

class DayAppointments
{
private:
    Appointment *appointments;
    int numOfAppointments;
    string weekDay;

public:
    /** Default constructor **/
    DayAppointments();

    /** Destructor **/
    virtual ~DayAppointments();

    /** Copy constructor **/
    DayAppointments(const DayAppointments& other);

    /** Input the appointments of a day **/
    friend istream& operator>>(istream& in, DayAppointments&);

    /** Output the appointments of a day **/
    friend ostream& operator<<(ostream& out, DayAppointments&);

    /** Overloading the equal operator to assign the appointments of a day to another day **/
    DayAppointments& operator=(DayAppointments&);

    /** Overloading the relational operatE:\Time\Time\main.cppors to compare 2 day appointments objects **/
    bool operator==(DayAppointments);
    bool operator!=(DayAppointments);
};

class Calendar
{
    private:
        DayAppointments * days;
        int numOfDays;

    public:
        /** Default Constructor **/
        Calendar();

        /** Destructor **/
        virtual ~Calendar();

        /** Input the appointments of a week **/
        friend istream& operator>>(istream& in, Calendar&);

        /** Output the appointments of a week **/
        friend ostream& operator<<(ostream& out, Calendar&);
};

#endif // CALENDAR_H
