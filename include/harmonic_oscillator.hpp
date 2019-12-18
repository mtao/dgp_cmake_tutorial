#pragma once
#include <Eigen/Core>

class HarmonicOscillator {
    public:
        using Point = std::array<double,3>;


        void integrate(double timestep);

        const Point& p() const { return _p; }

        static void run(const Point& x, Point& dxdt, double timestep);


    private:
        Point _p = std::array<double,3>{{2,3,4}};





};
