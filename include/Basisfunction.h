#ifndef BASISFUNCTION_H
#define BASISFUNCTION_H

#include <GoTools/utils/Point.h>
#include <GoTools/geometry/Streamable.h>
#include <vector>

namespace LR {

enum parameterEdge {
NONE       = 0,
WEST       = 1,
EAST       = 2,
SOUTH      = 8,
NORTH      = 16,
SOUTH_WEST = 9,
SOUTH_EAST = 10,
NORTH_WEST = 17,
NORTH_EAST = 18};

typedef enum parameterEdge parameterEdge;

class Basisfunction : public Go::Streamable {
public:
	// constructors
	Basisfunction(double *knot_u, double *knot_v, double *controlpoint, int dim, int order_u, int order_v, double weight=1.0);
	~Basisfunction();


	double evaluate(double u, double v) const;
	void evaluate(std::vector<double> &results, double u, double v, int derivs) const;

	bool operator==(const Basisfunction &other) const;
	void operator+=(const Basisfunction &other) ;

	// get/set methods
	void setEdge(parameterEdge edge_index);
	void addEdge(parameterEdge edge_index);
	parameterEdge getEdgeIndex() const;
	void getControlPoint(Go::Point &pt) const;

	// IO-functions
	virtual void read(std::istream &is);
	virtual void write(std::ostream &os) const;

// private:
	double *knot_u_;
	double *knot_v_;
	double *controlpoint_;
	int dim_;
	int order_u_;
	int order_v_;
	double weight_;
	parameterEdge edge_index_;

};

} // end namespace LR

#endif

