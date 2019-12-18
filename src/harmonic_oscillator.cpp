#include "harmonic_oscillator.hpp"
#include <boost/numeric/odeint.hpp>
using namespace boost::numeric::odeint;


void HarmonicOscillator::run(const Point& x, Point& dxdt, double timestep) {
    dxdt[0] = -x[1];
    dxdt[1] = x[0]  ;
    dxdt[2] = 0;
}
void HarmonicOscillator::integrate(double timestep) {

    runge_kutta4<Point> _integrator;
    _integrator.do_step(run,_p,0,timestep);
}
