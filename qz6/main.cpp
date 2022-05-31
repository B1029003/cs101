#include <iostream>
#include <string>

using namespace std;

class Clock {
    public:
        int hour;
        int minute;
        int second;
        string meridian;
        
        Clock(int h, int m, int s, string mer) {
            hour = h;
            minute = m;
            second = s;
            meridian = mer;
        };
        
        void display() {
            cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
            
        };
    
};

class StandardClock : Clock {
    public:
        StandardClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
            hour = h;
            minute = m;
            second = s;
            meridian = mer;
        };
        void display() {
            if (meridian == "AM") {
				cout << "上午 " << hour << ":" << minute << ":" << second << endl;
			} else if (meridian == "PM") {
				cout << "下午 " <<hour << ":" << minute << ":" << second << endl;
			}
		};
    
};

class MillitaryClock : Clock {
    public:
        MillitaryClock(int h, int m, int s, string mer) : Clock(h, m, s, mer) {
            hour = h;
            minute = m;
            second = s;
            meridian = mer;
        };
        void display() {
            if (meridian == "AM") {
				cout << hour << ":" << minute << ":" << second << endl;
			} else if (meridian == "PM") {
				cout << hour+12 << ":" << minute << ":" << second << endl;
			}
        };
};


int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MillitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    
    return 0;
}
