#include <iostream>

class PIDController {
private:
    double Kp, Ki, Kd;
    double prevError, integral;

public:
    PIDController(double Kp, double Ki, double Kd)
        : Kp(Kp), Ki(Ki), Kd(Kd), prevError(0), integral(0) {}

    double compute(double setPoint, double actualValue, double actualVelocity, double maxVelocity) {
        double error = setPoint - actualValue;

        // If error is within 3% of the setPoint and the velocity is small
        if (std::abs(error) <= 0.03 * setPoint && std::abs(actualVelocity) < maxVelocity) {
            integral = 0;  // Reset integral
            return 0;      // No control input
        }

        integral += error;
        double derivative = error - prevError;
        prevError = error;

        return Kp * error + Ki * integral + Kd * derivative;
    }
};
class Vehicle {
private:
    double xPos, yPos;
    double xVel, yVel;
    double mass;

public:
    Vehicle(double mass) : xPos(0), yPos(0), xVel(0), yVel(0), mass(mass) {}

    void applyForce(double forceX, double forceY) {
        xVel += forceX/mass;  // basic kinematic model for x direction
        yVel += forceY/mass;  // basic kinematic model for y direction
        xVel *= 0.99;  // Decrease velocity by 1% to simulate friction
        yVel *= 0.99;
        xPos += xVel;  // Integrate velocity to get position for x direction
        yPos += yVel;  // Integrate velocity to get position for y direction
    }

    double getX() {
        return xPos;
    }

    double getY() {
        return yPos;
    }
};

int main() {
    PIDController pidControllerX(2, 0.001, 0.2);
    PIDController pidControllerY(2, 0.001, 0.2);
    
    Vehicle vehicle(100);
    double setPointX = 90;
    double setPointY = 100;
    double maxVelocity = 0.1; // You can adjust this value based on desired performance

    for (int time = 0; time <= 1000; time++) {
        // Using the compute function that also considers velocity
        double controlForceX = pidControllerX.compute(setPointX, vehicle.getX(), vehicle.getX(), maxVelocity);
        double controlForceY = pidControllerY.compute(setPointY, vehicle.getY(), vehicle.getY(), maxVelocity);

        vehicle.applyForce(controlForceX, controlForceY);
        
        std::cout << "Time: " << time
                  << ", X: " << vehicle.getX()
                  << ", Y: " << vehicle.getY()
                  << ", Control Force X: " << controlForceX
                  << ", Control Force Y: " << controlForceY << std::endl;
    }

    return 0;
}

