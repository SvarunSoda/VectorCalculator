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

//// VARIABLES END ////

//// FUNCTIONS START ////

public:

	// START POINT FUNCTIONS

	void SetStartX(long double value) {

		x1 = value;

	}

	void SetStartY(long double value) {

		y1 = value;

	}

	void SetStartZ(long double value) {

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

	void SetEndX(long double value) {

		x2 = value;

	}

	void SetEndY(long double value) {

		y2 = value;

	}

	void SetEndZ(long double value) {

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

	void SetAngleX(long double value) {

		if (value > 180) {

			int multIdx = (value / 180);
			value = 180 - (value - (180 * multIdx));
			
			if ((multIdx % 2) != 0) {

				value = -(value);

			} else {

				value = 180 - value;

			}

			cout << "Entered angle value is greater than 180 degrees, changed to ";
			cout << value;
			cout << ".\n";

		} else if (value < -180) {

			int multIdx = (value / 180);
			value = 180 + (value - (180 * multIdx));

			if ((multIdx % 2) == 0) {

				value = 180 - value;
				value = -(value);

			}

			cout << "Entered angle value is smaller than -180 degrees, changed to ";
			cout << value;
			cout << ".\n";

		}

		value = -(value);

		angle_x = value;

	}

	void SetAngleY(long double value) {

		if (value > 90) {

			int multIdx = (value / 90);
			value = 90 - (value - (90 * multIdx));

			if ((multIdx % 2) != 0) {

				value = -(value);

			} else {

				value = 90 - value;

			}

			cout << "Entered angle value is greater than 90 degrees, changed to ";
			cout << value;
			cout << ".\n";

		} else if (value < -90) {

			int multIdx = (value / 90);
			value = 90 + (value - (90 * multIdx));

			if ((multIdx % 2) == 0) {

				value = 90 - value;
				value = -(value);

			}

			cout << "Entered angle value is smaller than -90 degrees, changed to ";
			cout << value;
			cout << ".\n";

		}

		angle_y = value;

	}

	void SetRelAngle(long double value) {

		if (value > 180) {

			value = value - ((180 * (int)(value / 180)));

			cout << "Entered angle value is greater than 180 degrees, changed to ";
			cout << value;
			cout << ".\n";

		} else if (value < -180) {

			value = value + ((180 * (int)(value / 180)));

			cout << "Entered angle value is smaller than -180 degrees, changed to ";
			cout << value;
			cout << ".\n";

		}

		angle_rel_total = value;

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

	// UPDATER FUNCTIONS

	//"UpdateLengthFromPoints" updates the length of the vector given the start and end points values
	//returns true if the length is changed, false if the length remained the same
	bool UpdateLengthFromPoints() {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength = length_total; //Initializing the store variable for the original length value

		length_x = x2 - x1; //Assigning the X component of the vector's length
		length_y = y2 - y1; //Assigning the Y component of the vector's length
		length_z = z2 - z1; //Assigning the Z component of the vector's length

		length_total = sqrt(pow(length_x, 2) + pow(length_y, 2) + pow(length_z, 2)); //Assigning the result of the 3D distance formula to the total length variable

		if (length_total == prevLength) { //Checking whether the distance was changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateLengthFromAngle" updates the length of the vector given the angles and start points of the payload
	//returns true if the length is changed, false if the length remained the same
	bool UpdateLengthFromAngle(long double length) {

		bool changed = false; //Initializing the change tracker variable

		long double prevLength_x = length_x; //Initializing the store variable for the original length X component value
		long double prevLength_y = length_y; //Initializing the store variable for the original length Y component value
		long double prevLength_z = length_z; //Initializing the store variable for the original length Z component value

		length_total = length; //Setting the inputted total length value

		length_y = length_total * (sin((M_PI / 180) * GetAngleY())); //Acquiring the Y component of the length using the appropriate trig function and the angle converted to radians
		length_x = (length_total * cos((M_PI / 180) * GetAngleY())) * (sin((M_PI / 180) * GetAngleX())); //Acquiring the X component of the length using the appropriate trig function and the angle converted to radians
		length_z = (length_total * cos((M_PI / 180) * GetAngleY())) * (cos((M_PI / 180) * GetAngleX())); //Acquiring the Z component of the length using the appropriate trig function and the angle converted to radians
		
		if ((length_x == prevLength_x) && (length_y == prevLength_y) && (length_z == prevLength_z)) { //Checking whether the distance values were changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	//"UpdateEndPoints" updates the endpoints given the start points and the length values
	//returns true if the endpoints have changed, false if the endpoints remained the same
	bool UpdateEndPoint() {

		bool changed = false; //Initializing the change tracker variable

		long double prevx2 = x2; //Initializing the store variable for the original X component value
		long double prevy2 = y2; //Initializing the store variable for the original Y component value
		long double prevz2 = z2; //Initializing the store variable for the original Z component value

		x2 = x1 + length_x; //Assining the X component of the endpoint
		y2 = y1 + length_y; //Assining the Y component of the endpoint
		z2 = z1 + length_z; //Assining the Z component of the endpoint

		if ((x2 == prevx2) && (y2 == prevy2) && (z2 == prevz2)) { //Checking whether the endpoint was changed

			changed = true;

		}

		return changed;

	}

	//"UpdateEndPoints" updates the start points given the endpoints and the length values
	//returns true if the start points have changed, false if the start points remained the same
	bool UpdateStartPoint() {

		bool changed = false; //Initializing the change tracker variable

		long double prevx1 = x1; //Initializing the store variable for the original X component value
		long double prevy1 = y1; //Initializing the store variable for the original Y component value
		long double prevz1 = z1; //Initializing the store variable for the original Z component value

		x1 = x2 - length_x; //Assining the X component of the start point
		y1 = y2 - length_y; //Assining the Y component of the start point
		z1 = z2 - length_z; //Assining the Z component of the start point

		if ((x1 == prevx1) && (y1 == prevy1) && (z1 == prevz1)) { //Checking whether the start point was changed

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

		long double prevAngle = angle_rel_total; //Initializing the store variable for the original total angle value

		angle_rel_total = (180 / M_PI) * acos(((GetLengthX() * OtherVector.GetLengthX()) + (GetLengthY() * OtherVector.GetLengthY()) + (GetLengthZ() * OtherVector.GetLengthZ())) / (GetLength() * OtherVector.GetLength())); //Assigning the result of the 3D vector angle formula to the total angle variable, converted into degrees

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

		angle_x = (180 / M_PI) * (tempAngle_x_2 - tempAngle_x_1); //Assigning the difference between the two horizontal components between the two vectors, and converting it to degrees
		angle_y = (180 / M_PI) * (tempAngle_y_2 - tempAngle_y_1); //Assigning the difference between the two vertical components between the two vectors, and converting it to degrees

		if (signbit(GetLengthX()) != signbit(OtherVector.GetLengthX())) { //Checking whether the horizontal component of the angle exceeds +-90 degrees

			int totalAngle = 180; //Maximum possible angle is 180 degrees

			if (signbit(angle_x) == 1) { //Checking whether angle_x is negative

				totalAngle = -180;

			}

			angle_x = totalAngle - angle_x; //Subtract angle_x from the maximum (180) angle

		}

		if (angle_rel_total == prevAngle) { //Checking whether the total angle was changed

			changed = true;

		}

		return changed; //Returning the change tracker variable

	}

	// STRING FUNCTIONS

	std::string ToString() {

		return "---------------------------------------\nVector start point:\nX: " + std::to_string(x1) + " Y: " + std::to_string(y1) + " Z: " + std::to_string(z1) + "\nVector end point:\nX: " + std::to_string(x2) + " Y: " + std::to_string(y2) + " Z: " + std::to_string(z2) + "\nVector length:\n" + std::to_string(length_total) + "\n---------------------------------------\n";

	}

//// FUNCTIONS END ////

};

//// VECTOR OBJECT END ////