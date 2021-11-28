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

    cout << "Please input the Payload Data.";
    cout << "\nLongitude (X): ";
    cin >> input;
    RocketVector.SetStartX(input);
    cout << "Lattitude (Z): ";
    cin >> input;
    RocketVector.SetStartZ(input);
    cout << "Altitude (Y): ";
    cin >> input;
    RocketVector.SetStartY(input);
    cout << "Horizontal Angle (+-180): ";
    cin >> input;
    RocketVector.SetAngleX(input);
    cout << "Vertical Angle (+-90): ";
    cin >> input;
    RocketVector.SetAngleY(input);
    cout << "Speed: ";
    cin >> input;
    RocketVector.UpdateLengthFromAngle(input);
    RocketVector.UpdateEndPoint();

    cout << "\nPayload Vector:\n";
    cout << RocketVector.ToString();

    cout << "\n";

    // INITIALIZING THE PARTICLE VECTOR

    Vector ParticleVector;

    cout << "Please input the Particle Vector Data.";
    cout << "\nStart Point X: ";
    cin >> input;
    ParticleVector.SetStartX(input);
    cout << "Start Point Y: ";
    cin >> input;
    ParticleVector.SetStartY(input);
    cout << "Start Point Z: ";
    cin >> input;
    ParticleVector.SetStartZ(input);
    cout << "End Point X: ";
    cin >> input;
    ParticleVector.SetEndX(input);
    cout << "End Point Y: ";
    cin >> input;
    ParticleVector.SetEndY(input);
    cout << "End Point Z: ";
    cin >> input;
    ParticleVector.SetEndZ(input);
    ParticleVector.UpdateLengthFromPoints();

    cout << "\nParticle Vector:\n";
    cout << ParticleVector.ToString();

    cout << "\n";

    // CALCULATING THE VECTOR ANGLE

    ParticleVector.UpdateRelAngle(RocketVector);

    cout << "Vector Difference Angles (Particle's Angular Origin with respect to the Payload):\n---------------------------------------";
    cout << "\n";
    cout << "Horizontal:\n";
    cout << ParticleVector.GetAngleX();
    cout << "\n";
    cout << "Vertical:\n";
    cout << ParticleVector.GetAngleY();
    cout << "\n";
    cout << "Total:\n";
    cout << ParticleVector.GetRelAngle();
    cout << "\n";
    cout << "---------------------------------------\n\n\n";

    // PROGRAM END

    cout << "PROGRAM FINISHED\n\n";

    system("pause");

    return 0;

}