// Implement low pass filter algorithm for accelerometer 
#include <iostream>
using namespace std;


struct Acceleration
{
	Acceleration(int x=0, int y=0, int z=0) : x(x),y(y), z(z) {};
	int x;
	int y;
	int z;
};


void Gravity_LowPassFilter(const Acceleration& sensor, Acceleration& m_Gravity)
{
  // alpha is calculated as t / (t + dT)
  // with t, the low-pass filter's time-constant
  // and dT, the event delivery rate

  float alpha = 0.9;

  m_Gravity.x = alpha * m_Gravity.x + (1 - alpha) * sensor.x;
  m_Gravity.y = alpha * m_Gravity.y + (1 - alpha) * sensor.y;
  m_Gravity.z = alpha * m_Gravity.z + (1 - alpha) * sensor.z;

}

void HighPassFilter(const Acceleration& sensor, Acceleration& gravity, Acceleration& adjusted_acc)
{
		Gravity_LowPassFilter(sensor, gravity);			// calc m_Gravity with highest possible frequency, aprx 100Hz
		adjusted_acc.x = sensor.x - gravity.x;
		adjusted_acc.y = sensor.y - gravity.y;
		adjusted_acc.z = sensor.z - gravity.z;
}


bool LowPassFilterUnitTest(){
const int SENSOR_SIZE = 42;
	Acceleration sensor[SENSOR_SIZE] = {
							{0,0, -1000}
							,{0,-2, -999}
							,{0,-2, -990}
							,{ 0, 2, -1002 }
							,{ 2, 5, -999 }
							,{ 0, 5, -990 }
							,{ 10, 5, -999 }
							,{ -4, 7, -999 }
							,{ 0, 3, -1000 }
							,{ 0, 0, -1002 }
							,{ 1,-2, -994 }
							,{0,0, -1000}
							,{ 0,-2, -999 }
							,{ 0,-2, -990 }
							,{ 0, 2, -1002 }
							,{ 2, 0, -999 }
							,{ 0, 20, -990 }
							,{ 10, 20, -999 }
							,{ -4, 15, -999 }
							,{ 0, 3, -1000 }
							,{ 0, 0, -1002 }
							,{ 1,-2, -994 }
							,{ 0,-2, -990 }
							,{ 0, 2, -1002 }
							,{ 2, 5, -999 }
							,{ 0, 5, -990 }
							,{ 10, 5, -999 }
							,{ -4, 7, -999 }
							,{ 0, 3, -1000 }
							,{ 0, 0, -1002 }
							,{ 1,-2, -994 }
							,{ 0,0, -1000 }
							,{ 0,-2, -999 }
							,{ 0,-2, -990 }
							,{ 0, 2, -1002 }
							,{ 2, 0, -999 }
							,{ 0, 20, -990 }
							,{ 10, 20, -999 }
							,{ -4, 15, -999 }
							,{ 0, 3, -1000 }
							,{ 0, 0, -1002 }
							,{ 1,-2, -994 }

	};
	Acceleration m_Gravity(0,0,-998);
	for (int i = 0; i< SENSOR_SIZE; i++){
		Gravity_LowPassFilter(sensor[i], m_Gravity);
		if (i>20)
		cout << "i=" << i << ", Gravity: x=" << m_Gravity.x << ", y=" << m_Gravity.y << ", z=" << m_Gravity.z << endl;
	}
	
	return true;
}

