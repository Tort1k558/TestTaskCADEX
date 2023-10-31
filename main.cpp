#include <iostream>
#include <vector>
#include <algorithm>

#include<Curves.h>

int main() {
    std::srand(std::time(0));

    std::vector<std::shared_ptr<Curve>> curves;

    //Creating random curves
    size_t countCurves = 100000;
    for (size_t i = 0; i < countCurves; i++)
    {
        int random = std::rand() % 3;
        switch (random)
        {
        case 0:
            curves.push_back(std::make_shared<Circle>(static_cast<float>(std::rand() % 10)));
            break;
        case 1:
            curves.push_back(std::make_shared<Ellipse>(static_cast<float>(std::rand() % 10), static_cast<float>(std::rand() % 10)));
            break;
        case 2:
            curves.push_back(std::make_shared<Helix>(static_cast<float>(std::rand() % 10), static_cast<float>(std::rand() % 11) / 10.0f));
            break;
        default:
            break;
        }
    }

    //Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    for (const auto& curve : curves) 
    {
        Vec3 point = curve->calculatePoint(PI / 4.0f);
        Vec3 derivative = curve->calculateDerivative(PI / 4.0f);
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
        std::cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << std::endl;
    }

    //Populate a second container that would contain only circles from the first container
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) 
    {
        std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve);
        if (circle) 
        {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle> a, std::shared_ptr<Circle> b) 
        {
            return a->getRadius() < b->getRadius();
        });
    

    //Calculate the total sum of the radii of all the curves in the second container using openmp
    float totalRadiusSum = 0.0f;
    #pragma omp parallel for reduction(+:totalRadiusSum)
    for (int i = 0; i < circles.size(); ++i) 
    {
        totalRadiusSum += circles[i]->getRadius();
    }


    std::cout << "Total sum of radii: " << totalRadiusSum << std::endl;

    return 0;
}