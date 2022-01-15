//Author(s): Svarun Soda
//Class: Aerospace & Science Team of College of the Canyons

#include <stdio.h>
#include <tgmath.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <iostream> 
#include <vector>
#define M_PI           3.14159265358979323846

using namespace std;

//// VECTOR OBJECT START ////

class Vector3D {

    //// VARIABLES START ////

private:

    // START POINT COORDINATES VARIABLES

    double x1 = 0;
    double y1 = 0;
    double z1 = 0;

    // END POINT COORDINATES VARIABLES

    double x2 = 0;
    double y2 = 0;
    double z2 = 0;

    // LENGTH VARIABLES

    double length_x = 0;
    double length_y = 0;
    double length_z = 0;
    double length_total = 0;

    // ANGLE VARIABLES

    double angle_roll = 0;
    double angle_pitch = 0;
    double angle_yaw = 0;
    double angle_rel_yaw = 0;
    double angle_rel_pitch = 0;
    double angle_rel_total = 0;
    double angle_target_yaw = 0;
    double angle_target_pitch = 0;

    // MISC VARIABLES

    std::string name = "";
    std::string other_name = "";
    double mass = 0;
    double acceleration = 0;
    double fuel = 0;
    double radius = 0;
    bool is_pos_degrees = false;
    bool particle_hit = false;
    bool debug_enabled = false;

    //// VARIABLES END ////

    //// FUNCTIONS START ////

public:

    // START POINT FUNCTIONS

    void SetStartX(double value, bool isQuiet) {

        if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

            value = BoundValueCircular(value, 180, isQuiet); //If so, bounding the position by 180 degrees

        }

        x1 = value;

    }

    void SetStartY(double value) {

        /*if (signbit(value) == 1) { //Checking if the current Y position component of the vector is negative
          value = 0; //If so, changing it to 0
          if (isQuiet == false) {
            cout << "Entered Y component of the start point value is negative, changed to 0.\n";
          }
        }*/

        y1 = value;

    }

    void SetStartZ(double value, bool isQuiet) {

        if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

            value = BoundValueCircular(value, 90, isQuiet); //If so, bounding the position by 90 degrees

        }

        z1 = value;

    }

    double GetStartX() {

        return x1;

    }

    double GetStartY() {

        return y1;

    }

    double GetStartZ() {

        return z1;

    }

    // END POINT FUNCTIONS

    void SetEndX(double value, bool isQuiet) {

        if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

            value = BoundValueCircular(value, 180, isQuiet); //If so, bounding the position by 180 degrees

        }

        x2 = value;

    }

    void SetEndY(double value) {

        y2 = value;

    }

    void SetEndZ(double value, bool isQuiet) {

        if (GetPosDegreeStatus() == true) { //Checking whether the value should be normalized to a Longitude-Lattitude system

            value = BoundValueCircular(value, 90, isQuiet); //If so, bounding the position by 90 degrees

        }

        z2 = value;

    }

    double GetEndX() {

        return x2;

    }

    double GetEndY() {

        return y2;

    }

    double GetEndZ() {

        return z2;

    }

    // LENGTH FUNCTIONS

    void SetLength(double value) {

        length_total = value;

    }

    void SetLengthX(double value) {

        length_x = value;

    }

    void SetLengthY(double value) {

        length_y = value;

    }

    void SetLengthZ(double value) {

        length_z = value;

    }

    double GetLengthX() {

        return length_x;

    }

    double GetLengthY() {

        return length_y;

    }

    double GetLengthZ() {

        return length_z;

    }

    double GetLength() {

        return length_total;

    }

    // ANGLE FUNCTIONS

    void SetAngleRoll(double value, bool isQuiet) {

        value = BoundValueCircular(value, 180, isQuiet); //Bounding the angle by 180 degrees

        angle_roll = value; //Setting the final roll component angle value

    }

    void SetAnglePitch(double value, bool isQuiet) {

        value = BoundValueCircular(value, 90, isQuiet); //Bounding the angle by 90 degrees

        angle_pitch = value; //Setting the final pitch component angle value

    }

    void SetAngleYaw(double value, bool invert, bool isQuiet) {

        value = BoundValueCircular(value, 90, isQuiet); //Bounding the angle by 90 degrees

        if (invert == true) {

            value = -(value); //Final invert (because the unit circle values have to be converted for later processing)

        }

        angle_yaw = value; //Setting the final yaw component angle value

    }

    void SetRelAnglePitch(double value, bool isQuiet) {

        value = BoundValueCircular(value, 90, isQuiet); //Bounding the relative angle by 90 degrees

        angle_rel_pitch = value; //Setting the final pitch component relative angle value

    }

    void SetRelAngleYaw(double value, bool isQuiet) {

        value = BoundValueCircular(value, 180, isQuiet); //Bounding the relative angle by 180 degrees

        value = -(value); //Final invert (because the unit circle values have to be converted for later processing)

        angle_rel_yaw = value; //Setting the final yaw component relative angle value

    }

    void SetRelAngle(double value, bool isQuiet) {

        value = BoundValueSimple(value, 180, isQuiet); //Bounding the angle by 180 degrees

        angle_rel_total = value; //Setting the final total relative angle value

    }

    void SetTargetAnglePitch(double value, bool isQuiet) {

        value = BoundValueCircular(value, 90, isQuiet); //Bounding the target angle by 90 degrees

        angle_target_pitch = value; //Setting the final pitch component target angle value

    }

    void SetTargetAngleYaw(double value, bool isQuiet) {

        value = BoundValueCircular(value, 180, isQuiet); //Bounding the target angle by 180 degrees

        value = -(value); //Final invert (because the unit circle values have to be converted for later processing)

        angle_target_yaw = value; //Setting the final yaw component target angle value

    }

    double GetAngleRoll() {

        return angle_roll;

    }

    double GetAnglePitch() {

        return angle_pitch;

    }

    double GetAngleYaw() {

        return angle_yaw;

    }

    double GetRelAnglePitch() {

        return angle_rel_pitch;

    }

    double GetRelAngleYaw() {

        return angle_rel_yaw;

    }

    double GetRelAngle() {

        return angle_rel_total;

    }

    double GetTargetAnglePitch() {

        return angle_target_pitch;

    }

    double GetTargetAngleYaw() {

        return angle_target_yaw;

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

    void SetMass(double value) {

        mass = value;

    }

    void SetAccel(double value) {

        acceleration = value;

    }

    void SetFuel(double value) {

        fuel = value;

    }

    void SetRadius(double value) {

        radius = value;

    }

    void SetDebugStatus(bool input) {

        debug_enabled = input;

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

    double GetMass() {

        return mass;

    }

    double GetAccel() {

        return acceleration;

    }

    double GetFuel() {

        return fuel;

    }

    double GetRadius() {

        return radius;

    }

    bool GetDebugStatus() {

        return debug_enabled;

    }

    // UPDATER FUNCTIONS

    //"UpdateLengthFromPoints" updates the length of the vector given the start and end points values
    //returns true if the length is changed, false if the length remained the same
    bool UpdateLengthFromPoints() {

        bool changed = false; //Initializing the change tracker variable

        double prevLength = GetLength(); //Initializing the store variable for the original length value

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
    bool UpdateComponentsFromLength(double length) {

        bool changed = false; //Initializing the change tracker variable

        double prevLength_x = GetLengthX(); //Initializing the store variable for the original length X component value
        double prevLength_y = GetLengthY(); //Initializing the store variable for the original length Y component value
        double prevLength_z = GetLengthZ(); //Initializing the store variable for the original length Z component value

        SetLength(length); //Setting the inputted total length value

        SetLengthY(GetLength() * (sin((M_PI / 180) * GetAnglePitch()))); //Acquiring the Y component of the length using the appropriate trig function and the angle converted to radians
        SetLengthX((GetLength() * cos((M_PI / 180) * GetAnglePitch())) * (sin((M_PI / 180) * GetAngleYaw()))); //Acquiring the X component of the length using the appropriate trig function and the angle converted to radians
        SetLengthZ((GetLength() * cos((M_PI / 180) * GetAnglePitch())) * (cos((M_PI / 180) * GetAngleYaw()))); //Acquiring the Z component of the length using the appropriate trig function and the angle converted to radians

        if ((GetLengthX() != prevLength_x) || (GetLengthY() != prevLength_y) || (GetLengthZ() != prevLength_z)) { //Checking whether the distance values were changed

            changed = true;

        }

        return changed; //Returning the change tracker variable

    }

    //"UpdateLengthFromComponents" updates the length of the vector given the length components
    //returns true if the length has changed, false if the length remained the same
    bool UpdateLengthFromComponents(double lengthX, double lengthY, double lengthZ) {

        bool changed = false; //Initializing the change tracker variable

        double prevLength = GetLength(); //Initializing the store variable for the original length value

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
    bool UpdateLengthFromComponent(std::string component, double length) {

        bool changed = false; //Initializing the change tracker variable

        double prevLength_x = GetLengthX(); //Initializing the store variable for the original length X component value
        double prevLength_y = GetLengthY(); //Initializing the store variable for the original length Y component value
        double prevLength_z = GetLengthZ(); //Initializing the store variable for the original length Z component value

        if ((component.compare("X") == 0) || (component.compare("x") == 0)) {

            if ((GetAngleYaw() == 0) || (GetAngleYaw() == 180) || (GetAngleYaw() == -180)) {

                return changed;

            }

            SetLengthX(length);

            if ((GetAngleYaw() == 90) || (GetAngleYaw() == -90)) {

                SetLengthZ(0);

            }
            else {

                SetLengthZ(GetLengthX() / tan((M_PI / 180) * GetAngleYaw()));

            }

            double lengthHorizontal;

            if ((GetAnglePitch() == 90) || (GetAnglePitch() == -90)) {

                lengthHorizontal = 0;

            }
            else {

                lengthHorizontal = sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2));

                SetLengthY(lengthHorizontal * tan((M_PI / 180) * GetAnglePitch()));

            }

            SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

        }
        else if ((component.compare("Y") == 0) || (component.compare("y") == 0)) {

            if (GetAnglePitch() == 0) {

                return changed;

            }

            SetLengthY(length);

            double lengthHorizontal;

            if ((GetAnglePitch() == 90) || (GetAnglePitch() == -90)) {

                lengthHorizontal = 0;

            }
            else {

                lengthHorizontal = GetLengthY() / tan((M_PI / 180) * GetAnglePitch());

            }

            SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

            SetLengthX(lengthHorizontal * sin((M_PI / 180) * GetAngleYaw()));
            SetLengthZ(lengthHorizontal * cos((M_PI / 180) * GetAngleYaw()));

        }
        else if ((component.compare("Z") == 0) || (component.compare("z") == 0)) {

            if ((GetAngleYaw() == 90) || (GetAngleYaw() == -90)) {

                return changed;

            }

            SetLengthZ(length);

            if ((GetAngleYaw() == 0) || (GetAngleYaw() == 180) || (GetAngleYaw() == -180)) {

                SetLengthX(0);

            }
            else {

                SetLengthX(GetLengthZ() * tan((M_PI / 180) * GetAngleYaw()));

            }

            double lengthHorizontal;

            if ((GetAnglePitch() == 90) || (GetAnglePitch() == -90)) {

                lengthHorizontal = 0;

            }
            else {

                lengthHorizontal = sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2));

                SetLengthY(lengthHorizontal * tan((M_PI / 180) * GetAnglePitch()));

            }

            SetLength(sqrt(pow(lengthHorizontal, 2) + pow(GetLengthY(), 2)));

        }

        if ((GetLengthX() != prevLength_x) || (GetLengthY() != prevLength_y) || (GetLengthZ() != prevLength_z)) { //Checking whether the distance values were changed

            changed = true;

        }

        return changed; //Returning the change tracker variable

    }

    //"UpdateEndPoint" updates the endpoint given the start point and the length values
    //returns true if the endpoint has changed, false if the endpoint remained the same
    bool UpdateEndPoint() {

        bool changed = false; //Initializing the change tracker variable

        double prevx2 = GetEndX(); //Initializing the store variable for the original X component value
        double prevy2 = GetEndY(); //Initializing the store variable for the original Y component value
        double prevz2 = GetEndZ(); //Initializing the store variable for the original Z component value

        SetEndX(GetStartX() + GetLengthX(), true); //Assining the X component of the endpoint
        SetEndY(GetStartY() + GetLengthY()); //Assining the Y component of the endpoint
        SetEndZ(GetStartZ() + GetLengthZ(), true); //Assining the Z component of the endpoint

        if ((GetEndX() != prevx2) || (GetEndY() != prevy2) || (GetEndZ() != prevz2)) { //Checking whether the endpoint was changed

            changed = true;

        }

        return changed;

    }

    //"UpdateEndPoint" updates the start point given the endpoint and the length values
    //returns true if the start point has changed, false if the start point remained the same
    bool UpdateStartPoint() {

        bool changed = false; //Initializing the change tracker variable

        double prevx1 = GetStartX(); //Initializing the store variable for the original X component value
        double prevy1 = GetStartY(); //Initializing the store variable for the original Y component value
        double prevz1 = GetStartZ(); //Initializing the store variable for the original Z component value

        SetStartX(GetEndX() - GetLengthX(), true); //Assining the X component of the start point
        SetStartY(GetEndY() - GetLengthY()); //Assining the Y component of the start point
        SetStartZ(GetEndZ() - GetLengthZ(), true); //Assining the Z component of the start point

        if ((GetStartX() != prevx1) || (GetStartY() != prevy1) || (GetStartZ() != prevz1)) { //Checking whether the start point was changed

            changed = true;

        }

        return changed;

    }

    //"UpdateRelAngle" updates the relative angle & it's components based off of the difference between the current vector and a different vector
    //returns true if the total difference relative angle is changed, false if the total difference relative angle remained the same
    bool UpdateRelAngle(Vector3D OtherVector) {

        bool changed = false; //Initializing the change tracker variable

        if ((GetLengthX() == 0) && ((GetLengthY() == 0)) && ((GetLengthZ() == 0)) || (OtherVector.GetLengthX() == 0) && ((OtherVector.GetLengthY() == 0)) && ((OtherVector.GetLengthZ() == 0))) { //Checking whether there is a 0 vector

            return changed;

        }

        double prevAngle = GetRelAngle(); //Initializing the store variable for the original total angle value

        SetRelAngle((180 / M_PI) * acos(((GetLengthX() * OtherVector.GetLengthX()) + (GetLengthY() * OtherVector.GetLengthY()) + (GetLengthZ() * OtherVector.GetLengthZ())) / (GetLength() * OtherVector.GetLength())), true); //Assigning the result of the 3D vector angle formula to the total angle variable, converted into degrees

        double tempAngle_x_1; //Initializing the first vector horizontal angle variable
        double tempAngle_x_2; //Initializing the second vector horizontal angle variable

        if (GetLengthX() == 0) { //Checking whether there is an X component to the first vector length

            tempAngle_x_1 = (M_PI / 2); //If not, assign the maximum possible angle value (90 degrees)

            if (signbit(GetLengthZ()) == 1) { //Checking whether the 90 degree angle should be negative

                tempAngle_x_1 = -(M_PI / 2);

            }

        } else {

            tempAngle_x_1 = atan(GetLengthZ() / GetLengthX()); //Else, assign the result appropriate trig expression to the horizontal component of to the angle of the first vector

        }

        if (OtherVector.GetLengthX() == 0) { //Checking whether there is an X component to the second vector length

            tempAngle_x_2 = (M_PI / 2); //If not, assign the maximum possible angle value (90 degrees)

            if (signbit(OtherVector.GetLengthZ()) == 1) { //Checking whether the 90 degree angle should be negative

                tempAngle_x_2 = -(M_PI / 2);

            }

        } else {

            tempAngle_x_2 = atan(OtherVector.GetLengthZ() / OtherVector.GetLengthX()); //Else, assign the result appropriate trig expression to the horizontal component of the angle of the second vector

        }

        double tempAngle_y_1; //Initializing the first vector vertical angle variable
        double tempAngle_y_2; //Initializing the second vector vertical angle variable

        tempAngle_y_1 = acos(sqrt(pow(GetLengthX(), 2) + pow(GetLengthZ(), 2)) / GetLength()); //Getting the vertical component of the angle of the first vector
        tempAngle_y_2 = acos(sqrt(pow(OtherVector.GetLengthX(), 2) + pow(OtherVector.GetLengthZ(), 2)) / OtherVector.GetLength()); //Getting the vertical component of the angle of the second vector

        if (signbit(GetLengthY()) == 1) { //Checking whether the vertical component of the difference angle of the first vector should be negative

            tempAngle_y_1 = -(tempAngle_y_1);

        }

        if (signbit(OtherVector.GetLengthY()) == 1) { //Checking whether the vertical component of the difference angle of the second vector should be negative

            tempAngle_y_2 = -(tempAngle_y_2);

        }

        SetRelAngleYaw((180 / M_PI) * (tempAngle_x_2 - tempAngle_x_1), true); //Assigning the difference between the two horizontal components between the two vectors, and converting it to degrees
        SetRelAnglePitch((180 / M_PI) * (tempAngle_y_2 - tempAngle_y_1), true); //Assigning the difference between the two vertical components between the two vectors, and converting it to degrees

        if (signbit(GetLengthX()) != signbit(OtherVector.GetLengthX())) { //Checking whether the horizontal component of the angle exceeds +-90 degrees

            int totalAngle = 180; //Maximum possible angle is 180 degrees

            if (signbit(GetRelAngleYaw()) == 1) { //Checking whether angle_roll is negative

                totalAngle = -180;

            }

            SetRelAngleYaw(totalAngle - GetRelAngleYaw(), true); //Subtract angle_roll from the maximum (180) angle

        }

        //other_name = OtherVector.GetName(); //Acquiring the name of the other vector

        if (GetRelAngle() != prevAngle) { //Checking whether the total angle was changed

            changed = true;

        }

        return changed; //Returning the change tracker variable

    }
    
    //"UpdateTargetAngleDirect" updates the target angle components based off of the start points of the current vector and a different vector
    //returns true if the target angle components were changed, false if the target angle components remained the same
    bool UpdateTargetAngleDirect(Vector3D OtherVector) {

        bool changed = false; //Initializing the change tracker variable

        if ((GetStartX() == OtherVector.GetStartX()) && (GetStartY() == OtherVector.GetStartY()) && (GetStartZ() == OtherVector.GetStartZ())) {

            return changed; //Returning the change tracker variable

        }

        double prevAngleX = GetTargetAngleYaw(); //Initializing the store variable for the X component of the target angle value
        double prevAngleY = GetTargetAnglePitch(); //Initializing the store variable for the Y component of the target angle value

        double distX = OtherVector.GetStartX() - GetStartX(); //Acquiring the X component of the distance between the start points of the two vectors
        double distY = OtherVector.GetStartY() - GetStartY(); //Acquiring the Y component of the distance between the start points of the two vectors
        double distZ = OtherVector.GetStartZ() - GetStartZ(); //Acquiring the Z component of the distance between the start points of the two vectors

        if (distZ == 0) { //Taking the limit of the X component of the difference target angle

            if (signbit(distX) == 1) {

                SetTargetAngleYaw(-90, true);

            }
            else {

                SetTargetAngleYaw(90, true);

            }

        }
        else {

            SetTargetAngleYaw((180 / M_PI) * atan(distZ / distX), true); //Setting the calculated horizontal component target angle from the X and Z components of the distance

        }

        double distHorizontal = sqrt(pow(distX, 2) + pow(distZ, 2)); //Acquring the horizontal component of the distance
        double distTotal = sqrt(pow(distHorizontal, 2) + pow(distY, 2)); //Acquiring the total distance

        SetTargetAnglePitch((180 / M_PI) * acos(distHorizontal / distTotal), true); //Setting the calculated vertical component of the target angle from the horizontal and Y distance components

        if (signbit(distY) == 1) { //Checking whether the vertical component of the target angle should be negative

            SetTargetAnglePitch(-(180 / M_PI) * acos(distHorizontal / distTotal), true); //Setting the calculated vertical component of the target angle from the horizontal and Y distance components

        }
        else {

            SetTargetAnglePitch((180 / M_PI) * acos(distHorizontal / distTotal), true);

        }

        if ((GetTargetAngleYaw() != prevAngleX) || (GetTargetAnglePitch() != prevAngleY)) { //Checking whether the target angle components were changed

            changed = true;

        }

        return changed; //Returning the change tracker variable

    }

    //"UpdateTargetAnglePredictive" updates the target angle components based off of the start points of the current vector and the end points of the different vector
    //returns true if the target angle components were changed, false if the target angle components remained the same
    bool UpdateTargetAnglePredictive(Vector3D OtherVector) {

        bool changed = false; //Initializing the change tracker variable

        if ((GetStartX() == OtherVector.GetStartX()) && (GetStartY() == OtherVector.GetStartY()) && (GetStartZ() == OtherVector.GetStartZ())) {

            return changed; //Returning the change tracker variable

        }

        double prevAngleX = GetTargetAngleYaw(); //Initializing the store variable for the X component of the target angle value
        double prevAngleY = GetTargetAnglePitch(); //Initializing the store variable for the Y component of the target angle value

        double distX = OtherVector.GetEndX() - GetStartX(); //Acquiring the X component of the distance between the start points of the two vectors
        double distY = OtherVector.GetEndY() - GetStartY(); //Acquiring the Y component of the distance between the start points of the two vectors
        double distZ = OtherVector.GetEndZ() - GetStartZ(); //Acquiring the Z component of the distance between the start points of the two vectors

        if (distZ == 0) { //Taking the limit of the X component of the difference target angle

            if (signbit(distX) == 1) {

                SetTargetAngleYaw(-90, true);

            }
            else {

                SetTargetAngleYaw(90, true);

            }

        }
        else {

            SetTargetAngleYaw((180 / M_PI) * atan(distZ / distX), true); //Setting the calculated horizontal component target angle from the X and Z components of the distance

        }

        double distHorizontal = sqrt(pow(distX, 2) + pow(distZ, 2)); //Acquring the horizontal component of the distance
        double distTotal = sqrt(pow(distHorizontal, 2) + pow(distY, 2)); //Acquiring the total distance

        if (signbit(distY) == 1) { //Checking whether the vertical component of the target angle should be negative

            SetTargetAnglePitch(-(180 / M_PI) * acos(distHorizontal / distTotal), true); //Setting the calculated vertical component of the target angle from the horizontal and Y distance components

        }
        else {

            SetTargetAnglePitch((180 / M_PI) * acos(distHorizontal / distTotal), true);

        }

        if ((GetTargetAngleYaw() != prevAngleX) || (GetTargetAnglePitch() != prevAngleY)) { //Checking whether the target angle components were changed

            changed = true;

        }

        return changed; //Returning the change tracker variable

    }

    //"MoveVectorByLength" updates the start & end points of the vector by adding the current length values to them
    //returns true if the start point changed, false if the start point remained the same
    bool MoveVectorByLength() {

        bool changed = false; //Initializing the change tracker variable

        double prevx1 = GetStartX(); //Initializing the store variable for the original X component value
        double prevy1 = GetStartY(); //Initializing the store variable for the original Y component value
        double prevz1 = GetStartZ(); //Initializing the store variable for the original Z component value

        if (GetPosDegreeStatus() == true) {

            SetStartX(GetStartX() + MetricToDegree(GetLengthX(), 180), true); //Moving the X component of the start point by the X component of the length
            SetStartZ(GetStartZ() + MetricToDegree(GetLengthZ(), 180), true); //Moving the Z component of the start point by the Z component of the length

        }
        else {

            SetStartX(GetStartX() + GetLengthX(), true); //Moving the X component of the start point by the X component of the length
            SetStartZ(GetStartZ() + GetLengthZ(), true); //Moving the Z component of the start point by the Z component of the length

        }

        SetStartY(GetStartY() + GetLengthY()); //Moving the Y component of the start point by the Y component of the length

        if ((GetStartX() != prevx1) || (GetStartY() != prevy1) || (GetStartZ() != prevz1)) { //Checking whether the start point was changed

            changed = true;

        }

        return changed;

    }

    //"RotateVectorEuler" rotates the start and end points of the vector using Matrix methods given a set of Euler angles by which to rotate the vector
    //returns true if the start and end points were changed, false it the start and end points weren't changed
    bool RotateVectorEuler(double rotX, double rotY, double rotZ) {

        bool changed = false;

        double prevStartX = GetStartX();
        double prevStartY = GetStartY();
        double prevStartZ = GetStartZ();
        double prevEndX = GetEndX();
        double prevEndY = GetEndY();
        double prevEndZ = GetEndZ();

        rotX = rotX * (M_PI / 180);
        rotY = rotY * (M_PI / 180);
        rotZ = rotZ * (M_PI / 180);

        std::vector<vector<double>> initialStartMatrix {

            {prevStartX},
            {prevStartY},
            {prevStartZ}

        };
        std::vector<vector<double>> initialEndMatrix{

            {prevEndX},
            {prevEndY},
            {prevEndZ}

        };

        std::vector<vector<double>> multMatrixX {

            {1, 0, 0},
            {0, cos(rotX), -sin(rotX)},
            {0, sin(rotX), cos(rotX)}

        };
        std::vector<vector<double>> multMatrixY {

            {cos(rotY), 0, sin(rotY)},
            {0, 1, 0},
            {-sin(rotY), 0, cos(rotY)}

        };
        std::vector<vector<double>> multMatrixZ {

            {cos(rotZ), -sin(rotZ), 0},
            {sin(rotZ), cos(rotZ), 0},
            {0, 0, 1}

        };

        std::vector<vector<double>> finalStartMatrix = MultiplyMatrices(MultiplyMatrices(MultiplyMatrices(initialStartMatrix, multMatrixX, 3, 3), multMatrixY, 3, 3), multMatrixZ, 3, 3);
        std::vector<vector<double>> finalEndMatrix = MultiplyMatrices(MultiplyMatrices(MultiplyMatrices(initialEndMatrix, multMatrixX, 3, 3), multMatrixY, 3, 3), multMatrixZ, 3, 3);

        SetStartX(finalStartMatrix[0][0], true);
        SetStartY(finalStartMatrix[1][0]);
        SetStartZ(finalStartMatrix[2][0], true);

        SetEndX(finalEndMatrix[0][0], true);
        SetEndY(finalEndMatrix[1][0]);
        SetEndZ(finalEndMatrix[2][0], true);

        if ((GetStartX() != prevStartX) || (GetStartY() != prevStartY) || (GetStartZ() != prevStartZ) || (GetEndX() != prevEndX) || (GetEndY() != prevEndY) || (GetEndZ() != prevEndZ)) {

            changed = true;

        }

        return changed;

    }

    //"RotateVectorQuaternion" rotates the start and end points of the vector using Matrix methods given a set of Quaternion angles by which to rotate the vector
    //returns true if the start and end points were changed, false it the start and end points weren't changed
    bool RotateVectorQuaternion(double rotW, double rotX, double rotY, double rotZ) {

        bool changed = false;

        double prevStartX = GetStartX();
        double prevStartY = GetStartY();
        double prevStartZ = GetStartZ();
        double prevEndX = GetEndX();
        double prevEndY = GetEndY();
        double prevEndZ = GetEndZ();



        if ((GetStartX() != prevStartX) || (GetStartY() != prevStartY) || (GetStartZ() != prevStartZ) || (GetEndX() != prevEndX) || (GetEndY() != prevEndY) || (GetEndZ() != prevEndZ)) {

            changed = true;

        }

        return changed;

    }

	// STRING FUNCTIONS

	std::string ToStringPos() {

		return "\n" + GetName() + " Vector Positional Data\n---------------------------------------\nStart point\nX: " + std::to_string(GetStartX()) + " Y: " + std::to_string(GetStartY()) + " Z: " + std::to_string(GetStartZ()) + "\nEnd point\nX: " + std::to_string(GetEndX()) + " Y: " + std::to_string(GetEndY()) + " Z: " + std::to_string(GetEndZ()) + "\nLength: " + std::to_string(GetLength()) + "\n---------------------------------------\n";

	}

	std::string ToStringAngle() {

		return "\n" + GetName() + " Vector Angles\n--------------------------------------\nRoll:\n" + std::to_string(GetAngleRoll()) + "\nPitch:\n" + std::to_string(GetAnglePitch()) + "\nYaw:\n" + std::to_string(GetAngleYaw()) + "\nRelative Angles (with respect to " + GetOtherName() + ")\nRelative Pitch : \n" + std::to_string(GetRelAnglePitch()) + "\nRelative Yaw : \n" + std::to_string(GetRelAngleYaw()) + "\nRelative Total : \n" + std::to_string(GetRelAngle()) + "\n--------------------------------------- \n";

	}

	std::string ToStringMisc() {

		return "\n" + GetName() + " Vector Miscellaneous Data\n---------------------------------------\nMass: " + std::to_string(GetMass()) + "\nEngine Acceleration: " + std::to_string(GetAccel()) + "\nRadius: " + std::to_string(GetRadius()) + "\n---------------------------------------\n";

	}

	std::string ToStringRocketLiveFeed(double AccelerationX, double AccelerationY, double AccelerationZ, double TimeElapsed, int ParticleHits) {

		return "\n" + GetName() + " Vector Live Data Report\n---------------------------------------\nCurrent position\nLongitude (X): " + std::to_string(GetStartX()) + "\nLattitude (Z): " + std::to_string(GetStartZ()) + "\nAltitude (Y): " + std::to_string(GetStartY()) + "\nCurrent angle\nHorizontal (X): " + std::to_string(GetAngleYaw()) + "\nVertical (Y): " + std::to_string(GetAnglePitch()) + "\nTotal: " + std::to_string(GetRelAngle()) + "\nCurrent velocity\nX: " + std::to_string(GetLengthX()) + "\nY: " + std::to_string(GetLengthY()) + "\nZ: " + std::to_string(GetLengthZ()) + "\nSpeed: " + std::to_string(GetLength()) + "\nCurrent acceleration\nX: " + std::to_string(AccelerationX) + "\nY: " + std::to_string(AccelerationY) + "\nZ: " + std::to_string(AccelerationZ) + "\nEngine: " + std::to_string(GetAccel()) + "\nCurrent fuel: " + std::to_string(GetFuel()) + "\nParticle hits: " + std::to_string(ParticleHits) + "\nTime elapsed: " + std::to_string(TimeElapsed) + "\n---------------------------------------\n";

	}

    std::string ToStringRadarLiveFeed(double CurrentRotation, double CurrentRotationSpeed, double TimeElapsed) {

        return "\n" + GetName() + " Vector Live Data Report\n---------------------------------------\n-- Positional Values --\nStart point\nX: " + std::to_string(GetStartX()) + " Y: " + std::to_string(GetStartY()) + " Z: " + std::to_string(GetStartZ()) + "\nEnd point\nX: " + std::to_string(GetEndX()) + " Y: " + std::to_string(GetEndY()) + " Z: " + std::to_string(GetEndZ()) + "\nLength: " + std::to_string(GetLength()) + "\n-- Angular Values --\nCurrent Rotational Position: " + std::to_string(CurrentRotation) + "\nCurrent Rotational Speed: " + std::to_string(CurrentRotationSpeed) + "\nRoll:\n" + std::to_string(GetAngleRoll()) + "\nPitch:\n" + std::to_string(GetAnglePitch()) + "\nYaw:\n" + std::to_string(GetAngleYaw()) + "\n-- Relative Angular Values (with respect to " + GetOtherName() + ") --\nRelative Pitch: \n" + std::to_string(GetRelAnglePitch()) + "\nRelative Yaw: \n" + std::to_string(GetRelAngleYaw()) + "\nRelative Total: \n" + std::to_string(GetRelAngle()) + "\n-- Time Elapsed: " + std::to_string(TimeElapsed) + " --\n---------------------------------------\n";

    }

	// SUPPORTING FUNCTIONS

	//"BoundValueSimple" bounds a given value by a given pair of boundaries
	//Ex: An entered value of 200 with bounds of 180 will be returned as 20
	double BoundValueSimple(double value, double bound, bool isQuiet) {

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
	double BoundValueCircular(double value, double bound, bool isQuiet) {

		if (signbit(bound) == 1) { //Checking whether a negative value for the bounds was entered

			bound = -(bound); //If so, changing it to it's absolute value version

		}

		if (value > bound) { //Checking whether the entered value is greater than the bound

			int multIdx = (value / bound); //If so, counting how many times it goes over the bound
			value = bound - (value - (bound * multIdx)); //Obtaining the first new raw value

			if ((multIdx % 2) != 0) { //Checking whether we are in the same sign area we started in

				value = -(value); //If not, invert the sign value

			} else {

				value = bound - value; //If so, push us into the final correct semicircle

			}
			
			if (isQuiet == false) {

				cout << "Entered value is greater than ";
				cout << bound;
				cout << ", changed to ";
				cout << value;
				cout << ".\n";

			}

		} else if (value < -(bound)) { //Checking whether the entered value is less than the bound

			int multIdx = (value / bound); //If so, counting how many times it goes under the bound
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
	double MetricToDegree(double value, double bound) {

		return bound * (value / ((2 * M_PI * GetRadius()) / (180 / bound)));

	}

    //"CheckQuadrantAngle" provides the quadrant in which the given angle value is located in (in degrees)
    //returns 1 if the given angle is between 0 and 90 degrees, returns 2 if the given angle is between -90 and 0 degrees, returns 3 if the given angle is between 90 and 180 degrees, returns 4 if the given angle is between -180 and -90 degrees
    int CheckQuadrantAngle(double angle) {

        angle = BoundValueCircular(angle, 180, true);

        if ((angle < 0) && (angle > -90)) {

            return 2;

        } else if ((angle > 90) && (angle < 180)) {

            return 3;

        } else if ((angle < -90) && (angle > -180)) {

            return 4;

        }

        return 1;

    }

    //"CheckQuadrantCoordinate" provides the quadrant in which the given pair of coordinates is located in
    //returns 1 if both the first and second coordinates are positive, returns 2 if the first coordinate is negative and the second coordinate is positive, returns 3 if both the first and second coordinates are negative, returns 4 if the first coordinate is positive and the second coordinate is negative
    int CheckQuadrantCoordinate(double x, double y) {

        if ((x < 0) && (y > 0)) {

            return 2;

        } else if ((x < 90) && (y < 0)) {

            return 3;

        } else if ((x > 0) && (y < 0)) {

            return 4;

        }

        return 1;

    }

    //"MultiplyMatrices" returns the resulting matrix from multiplying matrices
    std::vector<vector<double>> MultiplyMatrices(std::vector<vector<double>> initialMatrix, std::vector<vector<double>> multMatrix, int initialCollumns, int finalRows) {

        std::vector<vector<double>> finalMatrix;

        finalMatrix.resize(finalRows);

        for (int i = 0; i < finalMatrix.size(); i++) {
            
            finalMatrix[i].resize(1);

        }

        for (int i = 0; i < finalRows; ++i) {

           double finalValue = 0;

            for (int j = 0; j < initialCollumns; ++j) {

                finalValue = finalValue + (initialMatrix[j][0] * multMatrix[i][j]);

            }

            finalMatrix[i][0] = finalValue;

        }

        return finalMatrix;

    }

//// FUNCTIONS END ////

};

//// VECTOR OBJECT END ////