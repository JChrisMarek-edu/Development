#include "polynomial.h"

#include <sstream>
#include <iomanip>
#include <cmath>
using std::stringstream;
using std::showpos;
using std::fixed;
using std::setprecision;
/**
 Implement
 1. Constructors
 2. Destructor
 3. Copy Assignment Operator
 4. ToString
 5. Read and Write
 6. The rest  of the methods

*/
Polynomial::Polynomial(size_t degree){  // Construtor
	_degree = degree + 1;
    if(_degree > 0){
    	_coefficients = new float[_degree];
    	for(size_t i = 0; i < _degree; i++){
    		_coefficients[i] = 0.0;
    	}
    }
    _degree -= 1;
};
Polynomial::Polynomial(size_t degree, const float* coefficients){  // Constructor
	_degree = degree;
    _coefficients = const_cast<float*>(coefficients);
};
Polynomial::Polynomial(const Polynomial& other){  // Copy Constructor
	_degree = other._degree;
    _coefficients = other._coefficients;
};
Polynomial::~Polynomial(){  // Destructor
	delete[] _coefficients;
}
const Polynomial Polynomial::Sum(const Polynomial& rhs)const{  // Summation of two Polynomials
  	float retValSize;
  	if(this->_degree >= rhs._degree){
  		retValSize = this->_degree;
  	} else {
    	retValSize = rhs._degree;
  	}
  	Polynomial retVal(retValSize);
  	for(size_t i = 0; i <= this->_degree; i++){
  		retVal._coefficients[i] += this->_coefficients[i];
  	}
  	for(size_t i = 0; i <= rhs._degree; i++){
  		retVal._coefficients[i] += rhs._coefficients[i];
  	}
  	return retVal;

}
const Polynomial Polynomial::Subtract(const Polynomial& rhs)const{  // Subtraction of two Polynomials
	float retValSize;
  	if(this->_degree >= rhs._degree){
  		retValSize = this->_degree;
  	} else {
    	retValSize = rhs._degree;
  	}
  	Polynomial retVal(retValSize);
  	for(size_t i = 0; i <= this->_degree; i++){
  		retVal._coefficients[i] += this->_coefficients[i];
  	}
  	for(size_t i = 0; i <= rhs._degree; i++){
  		retVal._coefficients[i] -= rhs._coefficients[i];
  	}
  	return retVal;
}
const Polynomial Polynomial::Minus()const{  // Unary Minus aka sign flip
	Polynomial retVal(this->_degree);
    for(size_t i = 0; i < this->_degree; i++){
    	retVal._coefficients[i] = -1 * this->_coefficients[i];
    }
	return retVal;
}
const Polynomial Polynomial::Multiply(const Polynomial& rhs)const{  // Multiplication of two Polynomials
	Polynomial retVal(this->_degree + rhs._degree);
    for(size_t i = 0; i <= this->_degree; i++){
    	for(size_t j = 0; j <= rhs._degree; j++){
        	retVal._coefficients[i+j] += this->_coefficients[i] * rhs._coefficients[j];
        }
    }
  	return retVal;
}
const Polynomial Polynomial::Divide(const Polynomial& rhs)const{  // Division of two Polynomials *EC*
    return Polynomial(0);
}
const Polynomial Polynomial::Divide(const Polynomial& rhs, Polynomial& remainder)const{  // Division of two Polynomials *EC*
    remainder = Polynomial(0);
    return Polynomial(0);
}
const Polynomial Polynomial::Derive()const{  // Derivation of a single Polynomial
	Polynomial retVal(this->_degree - 1);
    for(size_t i = 1; i < retVal._degree + 1; i++){
    	 retVal._coefficients[i - 1] = this->_coefficients[i] * i;
    }
  	return retVal;
}
float Polynomial::Evaluate(float x)const{  // Evaluation of a single Polynomial
	float result = _coefficients[0];
    for(size_t i = 1; i <= this->_degree; i++){
    	result += _coefficients[i] * pow(x, i);
    }
  	return result;
}
float Polynomial::Integrate(float start, float end)const{  // Integration of a single Polynomial *EC*
    return 0.0;
}
const Polynomial& Polynomial::operator=(const Polynomial& rhs){  // Copy Assignment Operator
    if(this != &rhs){
    	delete[] _coefficients;
    	this->_coefficients = rhs._coefficients;
    	this->_degree = rhs._degree;
    }
    return *this;
}
string Polynomial::ToString()const{  // Converts to string *Provided Do not Touch*
    stringstream ss;
    for (size_t i = _degree; i > 0; i--) {
        ss << showpos << fixed << setprecision(2) << _coefficients[i] << "x^" << i << " ";
    }
    ss << showpos << fixed << setprecision(2) << _coefficients[0];
    return ss.str();
}
bool Polynomial::Equals(const Polynomial& rhs)const{ // Checks if two Polynomials are the same
	if(this->_degree != rhs._degree){
    	return false;
    } else {
    	for(size_t i = 0; i < this->_degree; i++){
        	if(this->_coefficients[i] != rhs._coefficients[i]){
            	return false;
            }
        }
    }
    return true;
}
ostream& Polynomial::Write(ostream& output)const{  // Writes to a stream *Provided Do not Touch*
    output << _degree << " ";
    for (size_t i = 0; i < _degree + 1; i++) {
        output << _coefficients[i] << " ";
    }
    return output;
}
istream& Polynomial::Read(istream& input){  // Reads from a stream *Provided Do not Touch*
    size_t degree;
    input >> degree;
    if (input.fail()){
        return input;
    }
    float* coefficients = new float[degree + 1];
    for (size_t i = 0; i < degree + 1; i++) {
        input >> coefficients[i];
        if (input.fail()){
            delete[] coefficients;
            return input;
        }
    }

    if (degree != _degree){
        if (_coefficients){
            delete[] _coefficients;
        }
        _degree = degree;
        _coefficients = coefficients;
    }else{
        for (size_t i = 0; i < _degree + 1; i++) {
            _coefficients[i] = coefficients[i];
        }
        delete[] coefficients;
    }
    return input;
}
