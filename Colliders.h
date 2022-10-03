#include <Eigen/Dense>
#include <Eigen/Geometry>
using Eigen::VectorXd;
using Eigen::MatrixXd;

/*First we make a struct that consists of points that will represent the furthest 2 points inside 2 colliding
objects
 A is the vector representing the furthest point of OBJECT  A inside OBJECT B
 B is the vector representing the furthest point OF OBJECT B inside OBJECT A 
*/
struct CollisionPoints {
	Eigen::Vector3f A; // Furthest point of A into B
	Eigen::Vector3f B; // Furthest point of B into A
	Eigen::Vector3f Normal; // B – A normalized
	float Depth;    // Length of B – A
	bool HasCollision;
};
 
struct Transform { // Describes an objects location better, also can account for rotations and scaling ob objects
	Eigen::Vector3f Position;
	Eigen::Vector3f Scale;
	Eigen::Quaternionf Rotation;
};

struct Collider { //We create a base struct, to be the storage area of the children structs.Colliders will have test functions that can test collision between different objects, each object's goemtry will result in a different type of collider functions.
	virtual CollisionPoints TestCollision(
		const Transform* transform, //accepting a pointer to a transform struct which contains information about position and orientation and scale
        const Collider* collider,//accepting a pointer to another collider struct 
		const Transform* colliderTransform) const = 0; //accepting a pointer to another transform struct that will contain the result of the transform
 
	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const SphereCollider* sphere,
		const Transform* sphereTransform) const = 0;
 
	virtual CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const = 0;
};

struct PlaneCollider
	: Collider
{
	Eigen::Vector3f Plane;
	float Distance;
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const Collider* collider,
		const Transform* colliderTransform) const override
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const SphereCollider* sphere,
		const Transform* sphereTransform) const override
	{
		// reuse sphere code
		return sphere->TestCollision(sphereTransform, this, transform);
	}
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const override
	{
		return {}; // No plane v plane
	}
};
 
struct SphereCollider
	: Collider
{
	Eigen::Vector3f Center;
	float Radius;
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const Collider* collider,
		const Transform* colliderTransform) const override
	{
		return collider->TestCollision(colliderTransform, this, transform);
	}
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const SphereCollider* sphere,
		const Transform* sphereTransform) const override
	{
		return algo::FindSphereSphereCollisionPoints(
			this, transform, sphere, sphereTransform);
	}
 
	CollisionPoints TestCollision(
		const Transform* transform,
		const PlaneCollider* plane,
		const Transform* planeTransform) const override
	{
		return algo::FindSpherePlaneCollisionPoints(
			this, transform, plane, planeTransform);
	}
};

namespace algo {
	CollisionPoints FindSphereSphereCollisionPoints(
		const SphereCollider* a, const Transform* ta,
		const SphereCollider* b, const Transform* tb);
 
 
	CollisionPoints FindSpherePlaneCollisionPoints(
		const SphereCollider* a, const Transform* ta,
		const PlaneCollider* b, const Transform* tb);
}
