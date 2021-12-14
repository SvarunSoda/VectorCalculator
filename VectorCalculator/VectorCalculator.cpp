//Author(s): Svarun Soda
//Class: Aerospace & Science Team of College of the Canyons

#include <stdio.h>
#include "vector.cpp"
#include <iostream> 

using namespace std;

int main() {

    cout << "Vector Calculator Program\n";
    cout << "Author(s): Svarun Soda";

    long double input;

    cout << "\n\n\n";

    // INITIALIZING THE PAYLOAD VECTOR

    Vector RocketVector;

    RocketVector.SetName("Payload");
    RocketVector.SetPosDegreeStatus(true);
    cout << "Please input the Payload Data:";
    cout << "\nLongitude (X): ";
    cin >> input;
    RocketVector.SetStartX(input, false);
    cout << "Lattitude (Z): ";
    cin >> input;
    RocketVector.SetStartZ(input, false);
    cout << "Altitude (Y): ";
    cin >> input;
    RocketVector.SetStartY(input);
    cout << "Horizontal Angle (+-180): ";
    cin >> input;
    RocketVector.SetAngleX(input, true, false);
    cout << "Vertical Angle (+-90): ";
    cin >> input;
    RocketVector.SetAngleY(input, false);
    cout << "Speed: ";
    cin >> input;
    RocketVector.UpdateComponentsFromLength(input);
    RocketVector.UpdateEndPoint();

    cout << RocketVector.ToStringPos();

    cout << "\n";

    // INITIALIZING THE PARTICLE VECTOR

    Vector ParticleVector;

    ParticleVector.SetName("Particle");
    ParticleVector.SetPosDegreeStatus(true);
    cout << "Please input the Particle Vector Data:";
    cout << "\nStart Point X: ";
    cin >> input;
    ParticleVector.SetStartX(input, false);
    cout << "Start Point Y: ";
    cin >> input;
    ParticleVector.SetStartY(input);
    cout << "Start Point Z: ";
    cin >> input;
    ParticleVector.SetStartZ(input, false);
    cout << "End Point X: ";
    cin >> input;
    ParticleVector.SetEndX(input, false);
    cout << "End Point Y: ";
    cin >> input;
    ParticleVector.SetEndY(input);
    cout << "End Point Z: ";
    cin >> input;
    ParticleVector.SetEndZ(input, false);
    ParticleVector.UpdateLengthFromPoints();

    cout << ParticleVector.ToStringPos();

    // ACQUIRING THE VECTOR DIFFERENCE ANGLE

    ParticleVector.UpdateRelAngle(RocketVector);

    cout << ParticleVector.ToStringAngle();

    // PROGRAM END

    cout << "\n\nPROGRAM FINISHED\n\n";

    system("pause");

    return 0;

}