Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
• Event Name
• Date
• Venue
• Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.

  #include<iostream>
using namespace std;
struct details{
	string name;
	string date;
	string venue;
	string organizer;	
};
int main () {
	int n,i=0;
	string date;
	cout<<"enter the total no of events\n";
	cin>>n;
	details*events=new details[n];
	while (i<n) {
		cout<<"enter the name of the event\n";
		cin>>events[i].name;
		cout<<"enter the date of the event\n";
		cin>>events[i].date;
		cout<<"enter the venue of the event\n";
		cin>>events[i].venue;
		cout<<"enter the organizer of the event\n";
		cin>>events[i].organizer;
		++i;
		cout<<"\n";
	}
	i=0;
	cout<<"enter the date\n";
	cin>>date;
	while (i<n) {
		if (date==events[i].date) {
				cout<<"event "<<i+1<<":\n";
			cout<<"name="<<events[i].name<<"\ndate="<<events[i].date<<"\nvenue="<<events[i].venue<<"\norganizer="<<events[i].organizer<<"\n";
			cout<<endl;
	}
		++i;
	}
	delete[] events;
	return 0;
}


  
