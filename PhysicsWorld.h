#include <vector>
#include "Eigen/Dense"
using Eigen::VectorXd;
using Eigen::MatrixXd;
/*For creating resizable dynamic matrices/vectors, we use the following expression

Eigen::MatrixXd matrixname; 

while we use the following declaration when we need to create constant size matrices

*/
struct Object {
	Eigen::Vector3d Position; // struct with 3 floats for x, y, z coordiantes of vector
	Eigen::Vector3d Velocity;
	Eigen::Vector3d Force;
	float Mass;
};

class PhysicsWorld {
private:
	std::vector<Object*> m_objects; //Creating an array of pointers to our object structure, where each pointer points to object from struct
	Eigen::Vector3d m_gravity={0, -9.81, 0}; //Creating a vector to represent gravity, assuming it affects only y direction downwards
 
public:
	void AddObject   (Object* object) { /* ... */ }
	void RemoveObject(Object* object) { /* ... */ }
 
	void Step(float dt)
	{
		for (Object* obj : m_objects) { //We are practically saying that for each pointer in the m_object vector to pointers, do the following stuff
			obj->Force += (obj->Mass * m_gravity); // apply a force to the object, using equation F=ma
 
			obj->Velocity += obj->Force / obj->Mass * dt;
			obj->Position += obj->Velocity * dt;
 
			obj->Force << 0, 0, 0; // reset net force at the end
		}
	}
};