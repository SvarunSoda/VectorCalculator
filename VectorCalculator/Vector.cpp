//Author(s): Svarun Soda
//Class: Aerospace & Science Team of College of the Canyons

#include <stdio.h>
#include <tgmath.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <iostream> 
#define M_PI           3.14159265358979323846

using namespace std;

//// VECTOR OBJECT START ////

class Vector {

//// VARIABLES START ////

private:

	// START POINT COORDINATES VARIABLES

	long double x1 = 0;
	long double y1 = 0;
	long double z1 = 0;

	// END POINT COORDINATES VARIABLES

	long double x2 = 0;
	long double y2 = 0;
	long double z2 = 0;
	
	// LENGTH VARIABLES

	long double length_x = 0;
	long double length_y = 0;
	long double length_z = 0;
	long double length_total = 0;

	// ANGLE VARIABLES

	long double angle_x = 0;
	long double angle_y = 0;
	long double angle_rel_total = 0;

	// MISC VARIABLES

	std::string name = "";
	std::string other_name = "";
	bool is_pos_degrees = false;
	long double mass = 0;
	long double acceleration = 0;
	long double fuel = 0;
	long double radius = 0;

//// VARIABLES END ////

//// FUNCTIONS START ////

public:

	// START POINT FUNCTIONS

	void SetStartX(long double value, bool isQuiet) {

		if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

			value = BoundValueCircular(value, 180, isQuiet); //If so, bounding the position by 180 degrees

		}

		x1 = value;

	}

	void SetStartY(long double value) {

		/*if (signbit(value) == 1) { //Checking if the current Y position component of the vector is negative

			value = 0; //If so, changing it to 0

			if (isQuiet == false) {

				cout << "Entered Y component of the start point value is negative, changed to 0.\n";

			}

		}*/

		y1 = value;

	}

	void SetStartZ(long double value, bool isQuiet) {

		if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

			value = BoundValueCircular(value, 90, isQuiet); //If so, bounding the position by 90 degrees

		}

		z1 = value;

	}

	long double GetStartX() {

		return x1;

	}

	long double GetStartY() {

		return y1;

	}

	long double GetStartZ() {

		return z1;
	
	}

	// END POINT FUNCTIONS

	void SetEndX(long double value, bool isQuiet) {

		if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

			value = BoundValueCircular(value, 180, isQuiet); //If so, bounding the position by 180 degrees

		}

		x2 = value;

	}

	void SetEndY(long double value) {

		y2 = value;

	}

	void SetEndZ(long double value, bool isQuiet) {

		if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

			value = BoundValueCircular(value, 90, isQuiet); //If so, bounding the position by 90 degrees

		}

		z2 = value;

	}

	long double GetEndX() {

		return x2;

	}

	long double GetEndY() {

		return y2;

	}

	long double GetEndZ() {

		return z2;

	}

	// LENGTH FUNCTIONS

	void SetLength(long double value) {

		length_total = value;

	}

	void SetLengthX(long double value) {

		length_x = value;

	}

	void SetLengthY(long double value) {

		length_y = value;

	}

	void SetLengthZ(long double value) {

		length_z = value;

	}

	long double GetLengthX() {

		return length_x;

	}

	long double GetLengthY() {

		return length_y;

	}

	long double GetLengthZ() {

		return length_z;

	}

	long double GetLength() {

		return length_total;

	}

	// ANGLE FUNCTIONS

	void SetAngleX(long double value, bool isQuiet) {

		value = BoundValueCircular(value, 180, isQuiet); //Bounding the angle by 180 degrees

		value = -(value); //Final invert (because the unit circle values have to be converted for later processing)

		angle_x = value; //Setting the final horizontal component angle value

	}

	void SetAngleY(long double value, bool isQuiet) {

		value = BoundValueCircular(value, 90, isQuiet); //Bounding the angle by 90 degrees

		angle_y = value; //Setting the final vertical component angle value

	}

	void SetRelAngle(long double value, bool isQuiet) {

		value = BoundValueSimple(value, 180, isQuiet); //Bounding the angle by 180 degrees

		angle_rel_total = value; //Setting the final total relative angle value

	}

	long double GetAngleX() {

		return angle_x;

	}

	long double GetAngleY() {

		return angle_y;

	}

	long double GetRelAngle() {

		return angle_rel_total;

	}

	// MISC FUNCTIONS

	void SetName(std::string input) {

		name = input;

	}

	void SetOtherName(std::string input) {

		other_name = input;

	}

	void SetPosDegreeStatus(bool input) {

		is_pos_degrees = input;

	}

	void SetMass(long double value) {

		mass = value;

	}

	void SetAccel(long double value) {

		acceleration = value;

	}

	void SetFuel(long double value) {

		fuel = value;

	}

	void SetRadius(long double value) {

		radius = value;

	}

	std::string GetName() {

		return name;

	}

	std::string GetOtherName() {

		return other_name;

	}

	bool GetPosDegreeStatus() {

		return is_pos_degrees;

	}

	long double GetMass() {

		return mass;

	}

	long double GetAccel() {

		return acceleration;

	}

	long double GetFuel() {

		return fuel;

	}

	long double GetRadius() {

		return radius;

	}

	// UPDATER FUNCTIONS

	//"UpdateLengthFromPoints" updates the length of the vector given the start and end points values
	//returns true if the length is changed, false if the length remained the same
	bool UpdateLengthFromPoints() {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength = GetLength(); //Initializing the store variable for the original length value

		SetLengthX(GetEndX() - GetStartX()); //Assigning the X component of the vector's length
		SetLengthY(GetEndY() - GetStartY()); //Assigning the Y component of the vector's length
		SetLengthZ(GetEndZ() - GetStartZ()); //Assigning the Z component of the vector's length

		SetLength(sqrt(pow(GetLengthX(), 2) + pow(GetLengthY(), 2) + pow(GetLengthZ(), 2))); //Assigning the result of the 3D distance formula to the total length variable

		if (GetLength() != prevLength) { //Checking whether the distance was changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateComponentsFromLength" updates the length of the vector given the angles and start points of the payload
	//returns true if the length components have changed, false if the length components remained the same
	bool UpdateComponentsFromLength(long double length) {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength_x = GetLengthX(); //Initializing the store variable for the original length X component value
		long double prevLength_y = GetLengthY(); //Initializing the store variable for the original length Y component value
		long double prevLength_z = GetLengthZ(); //Initializing the store variable for the original length Z component value

		SetLength(length); //Setting the inputted total length value

		SetLengthY(GetLength() * (sin((M_PI / 180) * GetAngleY()))); //Acquiring the Y component of the length using the appropriate trig function and the angle converted to radians
		SetLengthX((GetLength() * cos((M_PI / 180) * GetAngleY())) * (sin((M_PI / 180) * GetAngleX()))); //Acquiring the X component of the length using the appropriate trig function and the angle converted to radians
		SetLengthZ((GetLength() * cos((M_PI / 180) * GetAngleY())) * (cos((M_PI / 180) * GetAngleX()))); //Acquiring the Z component of the length using the appropriate trig function and the angle converted to radians
		
		if ((GetLengthX() != prevLength_x) || (GetLengthY() != prevLength_y) || (GetLengthZ() != prevLength_z)) { //Checking whether the distance values were changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateLengthFromComponents" updates the length of the vector given the length components
	//returns true if the length has changed, false if the length remained the same
	bool UpdateLengthFromComponents(long double lengthX, long double lengthY, long double lengthZ) {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength = GetLength(); //Initializing the store variable for the original length value

		SetLengthX(lengthX); //Setting the X component of the length
		SetLengthY(lengthY); //Setting the Y component of the length
		SetLengthZ(lengthZ); //Setting the Z component of the length

		SetLength(sqrt(pow(GetLengthX(), 2) + pow(GetLengthY(), 2) + pow(GetLengthZ(), 2))); //Assigning the result of the 3D distance formula to the total length variable

		if (GetLength() != prevLength) { //Checking whether the distance value was changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateLengthFromComponent" updates the length components of the vector given a single component of the new length and the current angle
	//returns true if the length components have changed, false if the length components remained the same
	bool UpdateLengthFromComponent(std::string component, long double length) {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength_x = GetLengthX(); //Initializing the store variable for the original length X component value
		long double prevLength_y = GetLengthY(); //Initializing the store variable for the original length Y component value
		long double prevLength_z = GetLengthZ(); //Initializing the store variable for the original length Z component value

		if ((component.compare("X") == 0) || (component.compare("x") == 0)) {

			if ((GetAngleX() == 0) || (GetAngleX() == 180) || (GetAngleX() == -180)) {

				return changed;

			}

			SetLengthX(length);

			if ((GetAngleX() == 90) || (GetAngleX() == -90)) {

				SetLengthZ(0);

			} else {

				SetLengthZ(GetLengthX() / tan((M_PI / 180) * GetAngleX()));

			}

			long double lengthHorizontal;

			if ((GetAngleY() == 90) || (GetAngleY() == -90)) {

				lengthHorizontal = 0;

			} else {

				lengthHorizontal = sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2));

				SetLengthY(lengthHorizontal * tan((M_PI / 180) * GetAngleY()));

			}

			SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

		} else if ((component.compare("Y") == 0) || (component.compare("y") == 0)) {

			if (GetAngleY() == 0) {

				return changed;

			}

			SetLengthY(length);

			long double lengthHorizontal;

			if ((GetAngleY() == 90) || (GetAngleY() == -90)) {

				lengthHorizontal = 0;

			} else {

				lengthHorizontal = GetLengthY() / tan((M_PI / 180) * GetAngleY());

			}

			SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

			SetLengthX(lengthHorizontal * sin((M_PI / 180) * GetAngleX()));
			SetLengthZ(lengthHorizontal * cos((M_PI / 180) * GetAngleX()));

		} else if ((component.compare("Z") == 0) || (component.compare("z") == 0)) {

			if ((GetAngleX() == 90) || (GetAngleX() == -90)) {

				return changed;

			}

			SetLengthZ(length);

			if ((GetAngleX() == 0) || (GetAngleX() == 180) || (GetAngleX() == -180)) {

				SetLengthX(0);

			} else {

				SetLengthX(GetLengthZ() * tan((M_PI / 180) * GetAngleX()));

			}

			long double lengthHorizontal;

			if ((GetAngleY() == 90) || (GetAngleY() == -90)) {

				lengthHorizontal = 0;

			} else {

				lengthHorizontal = sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2));

				SetLengthY(lengthHorizontal * tan((M_PI / 180) * GetAngleY()));

			}

			SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

		}

		if ((GetLengthX() != prevLength_x) || (GetLengthY() != prevLength_y) || (GetLengthZ() != prevLength_z)) { //Checking whether the distance values were changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateEndPoints" updates the endpoints given the start points and the length values
	//returns true if the endpoints have changed, false if the endpoints remained the same
	bool UpdateEndPoint() {

		bool changed = false; //Initializing the change tracker variable

		long double prevx2 = GetEndX(); //Initializing the store variable for the original X component value
		long double prevy2 = GetEndY(); //Initializing the store variable for the original Y component value
		long double prevz2 = GetEndZ(); //Initializing the store variable for the original Z component value

		SetEndX(GetStartX() + GetLengthX(), true); //Assining the X component of the endpoint
		SetEndY(GetStartY() + GetLengthY()); //Assining the Y component of the endpoint
		SetEndZ(GetStartZ() + GetLengthZ(), true); //Assining the Z component of the endpoint

		if ((GetEndX() != prevx2) || (GetEndY() != prevy2) || (GetEndZ() != prevz2)) { //Checking whether the endpoint was changed

			changed = true;

		}

		return changed;

	}

	//"UpdateEndPoints" updates the start points given the endpoints and the length values
	//returns true if the start points have changed, false if the start points remained the same
	bool UpdateStartPoint() {

		bool changed = false; //Initializing the change tracker variable

		long double prevx1 = GetStartX(); //Initializing the store variable for the original X component value
		long double prevy1 = GetStartY(); //Initializing the store variable for the original Y component value
		long double prevz1 = GetStartZ(); //Initializing the store variable for the original Z component value

		SetStartX(GetEndX() - GetLengthX(), true); //Assining the X component of the start point
		SetStartY(GetEndY() - GetLengthY()); //Assining the Y component of the start point
		SetStartZ(GetEndZ() - GetLengthZ(), true); //Assining the Z component of the start point

		if ((GetStartX() != prevx1) || (GetStartY() != prevy1) || (GetStartZ() != prevz1)) { //Checking whether the start point was changed

			changed = true;

		}

		return changed;

	}

	//"UpdateRelAngle" updates the angle & it's components based off of the difference between the current vector and a different vector
	//returns true if the total difference angle is changed, false if the total difference angle remained the same
	bool UpdateRelAngle(Vector OtherVector) {

		bool changed = false; //Initializing the change tracker variable

		if ((GetLengthX() == 0) && ((GetLengthY() == 0)) && ((GetLengthZ() == 0)) || (OtherVector.GetLengthX() == 0) && ((OtherVector.GetLengthY() == 0)) && ((OtherVector.GetLengthZ() == 0))) { //Checking whether there is a 0 vector

			return changed;

		}

		long double prevAngle = GetRelAngle(); //Initializing the store variable for the original total angle value

		SetRelAngle((180 / M_PI) * acos(((GetLengthX() * OtherVector.GetLengthX()) + (GetLengthY() * OtherVector.GetLengthY()) + (GetLengthZ() * OtherVector.GetLengthZ())) / (GetLength() * OtherVector.GetLength())), true); //Assigning the result of the 3D vector angle formula to the total angle variable, converted into degrees

		long double tempAngle_x_1; //Initializing the first vector horizontal angle variable
		long double tempAngle_x_2; //Initializing the second vector horizontal angle variable
		
		if (GetLengthX() == 0) { //Checking whether there is an X component to the first vector length

			tempAngle_x_1 = (M_PI / 2); //If not, assign the maximum possible angle value (90 degrees)

			if (signbit(GetLengthZ()) == 1) { //Checking whether the 90 degree angle should be negative

				tempAngle_x_1 = -(M_PI / 2);

			}

		} else {

			tempAngle_x_1 = atan(GetLengthZ() / GetLengthX()); //Else, assign the result appropriate trig expression to the horizontal component of to the angle of the first vector

		} 
		
		if (OtherVector.GetLengthX() == 0) { //Checking whether there is an X component to the second vector length

			tempAngle_x_2 = M_PI / 2; //If not, assign the maximum possible angle value (90 degrees)

			if (signbit(OtherVector.GetLengthZ()) == 1) { //Checking whether the 90 degree angle should be negative

				tempAngle_x_2 = -(M_PI / 2);

			}

		} else {

			tempAngle_x_2 = atan(OtherVector.GetLengthZ() / OtherVector.GetLengthX()); //Else, assign the result appropriate trig expression to the horizontal component of the angle of the second vector

		}

		long double tempAngle_y_1; //Initializing the first vector vertical angle variable
		long double tempAngle_y_2; //Initializing the second vector vertical angle variable

		tempAngle_y_1 = acos(sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2)) / GetLength()); //Getting the vertical component of the angle of the first vector
		tempAngle_y_2 = acos(sqrt(pow(OtherVector.GetLengthX(), 2) + pow(OtherVector.GetLengthZ(), 2)) / OtherVector.GetLength()); //Getting the vertical component of the angle of the second vector

		if (signbit(GetLengthY()) == 1) { //Checking whether the vertical component of the difference angle of the first vector should be negative

			tempAngle_y_1 = -(tempAngle_y_1);

		}

		if (signbit(OtherVector.GetLengthY()) == 1) { //Checking whether the vertical component of the difference angle of the second vector should be negative

			tempAngle_y_2 = -(tempAngle_y_2);

		}

		SetAngleX((180 / M_PI) * (tempAngle_x_2 - tempAngle_x_1), true); //Assigning the difference between the two horizontal components between the two vectors, and converting it to degrees
		SetAngleY((180 / M_PI) * (tempAngle_y_2 - tempAngle_y_1), true); //Assigning the difference between the two vertical components between the two vectors, and converting it to degrees

		if (signbit(GetLengthX()) != signbit(OtherVector.GetLengthX())) { //Checking whether the horizontal component of the angle exceeds +-90 degrees

			int totalAngle = 180; //Maximum possible angle is 180 degrees

			if (signbit(angle_x) == 1) { //Checking whether angle_x is negative

				totalAngle = -180;

			}

			angle_x = totalAngle - angle_x; //Subtract angle_x from the maximum (180) angle

		}

		//other_name = OtherVector.GetName(); //Acquiring the name of the other vector

		if (GetRelAngle() != prevAngle) { //Checking whether the total angle was changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"MoveVectorByLength" updates the start & end points of the vector by adding the current length values to them
	//returns true if the start point changed, false if the start point remained the same
	bool MoveVectorByLength() {

		bool changed = false; //Initializing the change tracker variable

		long double prevx1 = GetStartX(); //Initializing the store variable for the original X component value
		long double prevy1 = GetStartY(); //Initializing the store variable for the original Y component value
		long double prevz1 = GetStartZ(); //Initializing the store variable for the original Z component value

		if (GetPosDegreeStatus() == true) {

			SetStartX(GetStartX() + MetricToDegree(GetLengthX(), 180), true); //Moving the X component of the start point by the X component of the length
			SetStartZ(GetStartZ() + MetricToDegree(GetLengthZ(), 180), true); //Moving the Z component of the start point by the Z component of the length

		} else {

			SetStartX(GetStartX() + GetLengthX(), true); //Moving the X component of the start point by the X component of the length
			SetStartZ(GetStartZ() + GetLengthZ(), true); //Moving the Z component of the start point by the Z component of the length

		}

		SetStartY(GetStartY() + GetLengthY()); //Moving the Y component of the start point by the Y component of the length

		if ((GetStartX() != prevx1) || (GetStartY() != prevy1) || (GetStartZ() != prevz1)) { //Checking whether the start point was changed

			changed = true;

		}

		return changed;

	}

	// STRING FUNCTIONS

	std::string ToStringPos() {

		return "\n" + GetName() + " Vector Positional Data\n---------------------------------------\nStart point\nX: " + std::to_string(GetStartX()) + " Y: " + std::to_string(GetStartY()) + " Z: " + std::to_string(GetStartZ()) + "\nEnd point\nX: " + std::to_string(GetEndX()) + " Y: " + std::to_string(GetEndY()) + " Z: " + std::to_string(GetEndZ()) + "\nLength: " + std::to_string(GetLength()) + "\n---------------------------------------\n";

	}

	std::string ToStringAngle() {

		return "\n" + GetName() + " Vector Difference Angles (" + GetName() + "'s Angular Origin with respect to " + GetOtherName() + ")\n--------------------------------------\nHorizontal:\n" + std::to_string(GetAngleX()) + "\nVertical:\n" + std::to_string(GetAngleY()) + "\nTotal:\n" + std::to_string(GetRelAngle()) + "\n---------------------------------------\n";

	}

	std::string ToStringMisc() {

		return "\n" + GetName() + " Vector Miscellaneous Data\n---------------------------------------\nMass: " + std::to_string(GetMass()) + "\nEngine Acceleration: " + std::to_string(GetAccel()) + "\nRadius: " + std::to_string(GetRadius()) + "\n---------------------------------------\n";

	}

	std::string ToStringRocketLiveFeed(long double AccelerationX, long double AccelerationY, long double AccelerationZ, long double TimeElapsed, int ParticleHits) {

		return "\n" + GetName() + " Vector Live Data Report\n---------------------------------------\nCurrent position\nLongitude (X): " + std::to_string(GetStartX()) + "\nLattitude (Z): " + std::to_string(GetStartZ()) + "\nAltitude (Y): " + std::to_string(GetStartY()) + "\nCurrent angle\nHorizontal (X): " + std::to_string(GetAngleX()) + "\nVertical (Y): " + std::to_string(GetAngleY()) + "\nTotal: " + std::to_string(GetRelAngle()) + "\nCurrent velocity\nX: " + std::to_string(GetLengthX()) + "\nY: " + std::to_string(GetLengthY()) + "\nZ: " + std::to_string(GetLengthZ()) + "\nSpeed: " + std::to_string(GetLength()) + "\nCurrent acceleration\nX: " + std::to_string(AccelerationX) + "\nY: " + std::to_string(AccelerationY) + "\nZ: " + std::to_string(AccelerationZ) + "\nEngine: " + std::to_string(GetAccel()) + "\nCurrent fuel: " + std::to_string(GetFuel()) + "\nParticle hits: " + std::to_string(ParticleHits) + "\nTime elapsed: " + std::to_string(TimeElapsed) + "\n---------------------------------------\n";

	}

	// SUPPORTING FUNCTIONS

	//"BoundValueSimple" bounds a given value by a given pair of boundaries
	//Ex: An entered value of 200 with bounds of 180 will be returned as 20
	long double BoundValueSimple(long double value, long double bound, bool isQuiet) {

		if (signbit(bound) == 1) { //Checking whether a negative value for the bounds was entered

			bound = -(bound); //If so, changing it to it's absolute value version

		}

		if (value > bound) { //Checking whether the entered value is greater than the bound

			value = value - ((bound * (int)(value / bound))); //If so, bringing the value down by the amnount of times it went over the bound

			if (isQuiet == false) {

				cout << "Entered value is greater than ";
				cout << bound;
				cout << ", changed to ";
				cout << value;
				cout << ".\n";

			}

		} else if (value < -(bound)) { //Checking whether the entered value is less than the negative version of the bound

			value = value + ((bound * (int)(value / bound))); //If so, bringing the value up by the amnount of times it went under the negative version of the bound

			if (isQuiet == false) {

				cout << "Entered value is smaller than ";
				cout << -(bound);
				cout << ", changed to ";
				cout << value;
				cout << ".\n";

			}

		}

		return value; //Returning the processed value variable

	}

	//"BoundValueCircular" bounds a given value by a given pair of boundaries, based off of the unit circle
	//Ex: An entered value of 200 with bounds of 180 will be returned as -160
	long double BoundValueCircular(long double value, long double bound, bool isQuiet) {

		if (signbit(bound) == 1) { //Checking whether a negative value for the bounds was entered

			bound = -(bound); //If so, changing it to it's absolute value version

		}

		if (value > bound) { //Checking whether the entered value is greater than 180 degrees

			int multIdx = (value / bound); //If so, counting how many times it goes over 180 degrees
			value = bound - (value - (bound * multIdx)); //Obtaining the first new raw value

			if ((multIdx % 2) != 0) { //Checking whether we are in the same sign area we started in

				value = -(value); //If not, invert the sign value

			}
			else {

				value = bound - value; //If so, push us into the final correct semicircle

			}
			
			if (isQuiet == false) {

				cout << "Entered value is greater than ";
				cout << bound;
				cout << ", changed to ";
				cout << value;
				cout << ".\n";

			}

		} else if (value < -(bound)) { //Checking whether the entered value is less than -180 degrees

			int multIdx = (value / bound); //If so, counting how many times it goes under -180 degrees
			value = bound + (value - (bound * multIdx)); //Obtaining the first new raw value

			if ((multIdx % 2) == 0) { //Checking whether we are in the same sign area we started in

				value = bound - value; //If not, invert the sign value
				value = -(value); //Push us into the final correct semicircle

			}

			if (isQuiet == false) {

				cout << "Entered value is smaller than ";
				cout << -(bound);
				cout << ", changed to ";
				cout << value;
				cout << ".\n";

			}

		}

		return value; //Returning the processed value variable

	}

	//"MetricToDegree" converts Carthesian coordinates of position or speed to Longitude-Lattitude degrees, given the planetary data
	long double MetricToDegree(long double value, long double bound) {

		return bound * (value / ((2 * M_PI * GetRadius()) / (180 / bound)));

	}

//// FUNCTIONS END ////

};

//// VECTOR OBJECT END ////