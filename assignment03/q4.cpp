Imagine you're developing a simulation software for autonomous drones. The
software includes a Drone abstract class that encapsulates common properties and
functionalities of drones, such as their position (latitude and longitude), altitude,
and speed. Additionally, it provides methods like adjustAltitude(float meters) to
change the drone's altitude and setSpeed(float speed) to modify its speed.
a) Your software also includes interfaces for different drone capabilities. The Flyable
interface outlines methods for movement in three-dimensional space, including
takeoff(), land(), and navigateTo(float latitude, float longitude, float altitude). The
Scannable interface defines methods for scanning the environment, such as
scanArea(float radius) to detect objects within a specified radius.
b) Using your software, create a class named ReconDrone that extends the Drone
class and implements both the Flyable and Scannable interfaces. The ReconDrone
class should have additional attributes like cameraResolution and maxFlightTime,
along with methods to control its flight and scanning operations.
Override the navigateTo(float latitude, float longitude, float altitude) method in
ReconDrone to calculate the distance between the current position and the target
position using GPS coordinates. Display the estimated time required for the drone
to reach the destination based on its current speed and altitude.

Implement the scanArea(float radius) method in ReconDrone to simulate scanning
the environment within the specified radius. Display the number of objects
detected and their coordinates.
c) Create a main function to demonstrate the functionality of the ReconDrone class.
Instantiate a ReconDrone object, set its initial position and altitude, then navigate
it to a different location while scanning the area. Display the results of the
navigation and scanning operations.
e) Handle any potential exceptions that may occur during the navigation and
scanning processes, such as GPS signal loss or communication errors with the drone
hardware.

  #include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
class drone {
    protected:
    double longitude,latitude,altitude,speed;
    public:
    drone(double longitude,double latitude,double altitude,double speed):longitude(longitude),latitude(latitude),altitude(altitude),speed(speed) {}
    void adjustaltitude(float altitude) { this->altitude=altitude; }
    void setspeed(double speed) { this->speed=speed; }
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual double navigateto(double latitude,double longitude,double altitude) = 0;
    virtual void scanarea(double radius) = 0;
};
class ReconDrone:public drone {
    double CameraResolution,maxFlightTime;
    public:
    ReconDrone(double CameraResolution,double maxFlightTime,double longitude,double latitude,double altitude,double speed):drone(longitude,latitude,altitude,speed) {
        this->CameraResolution=CameraResolution;
        this->maxFlightTime=maxFlightTime;
    }
    double navigateto(double latitude,double longitude,double altitude ) override {
        return double(sqrt(pow(longitude-this->longitude,2)+pow(latitude-this->latitude,2)+pow(altitude-this->altitude,2))/speed);
    }
void scanarea(double radius) {
    int n;
    srand(time(0));
    n=rand()%10 + 1;
    cout<<n<<" objects are found to be in the red zone\n";
    for (int i=1;i<=n;++i) {
        cout<<"co-ordinates for the "<<i<<" object are:("<<rand()%(int64_t(latitude+radius)+1)<<","<<rand()%(int64_t(longitude+radius)+1)<<","<<rand()%(int64_t(altitude+radius)+1)<<")\n";
    }
}
void land() override { longitude=latitude=altitude=speed=0; }
void takeoff() override { 
    //assuming the takeoff  feature will change the co-ordinates in this way
    longitude=latitude=altitude=speed=4; 
    }
};
int main() {
    double n;
    ReconDrone shapater(4000,60,0,0,0,0);
    cout<<"Welcome to your drone control simulator\n";
    while (1) {
        cout<<"enter 1 to take off\nenter 2 to adjust altitude\nenter 3 to adjust speed\nenter 4 to navigate to a different location\nenter 5 to scan the area\nenter 6 to land\nenter 7 to exit the app\n";
        cin>>n;
        if  (n==1) shapater.takeoff();
        else if (n==2) {
            cout<<"enter the altitude\n";
            cin>>n;
            shapater.adjustaltitude(n);
        }
        else if (n==3) {
            cout<<"enter the speed\n";
            cin>>n;
            shapater.setspeed(n);
        }
        else if (n==4) {
            double o,p;
            cout<<"enter the  latitude, longitude and the altitude of the destination\n";
            cin>>n>>o>>p;
            cout<<"It will take you "<<shapater.navigateto(n,o,p)<<" minutes to reach to the target\n";
        }
        else if (n==5) {
            cout<<"enter the radius\n";
            cin>>n;
            shapater.scanarea(n);
        }
        else if (n==6) shapater.land();
        else  if (n==7) return 0;
    }
}
