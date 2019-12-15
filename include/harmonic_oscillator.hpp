#pragma once
#include <Eigen/Core>

class HarmonicOscillator {
    public:
        using Point = Eigen::RowVector3d;


        void integrate(double timestep);

        const Point& p() const { return _p; }

        static void run(const Point& x, Point& dxdt, double timestep);


    private:
        Point _p = Point::Random();





};
