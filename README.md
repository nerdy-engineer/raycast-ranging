# raycast-ranging
Uses C++ standard library and Eigen to do ray casting.

**Purpose:**
There are a variety of practical problems that involve finding the point of intersection (or the closest thing to it) of many lines. This library is my attempt at facilitating quick and simple calculation of those intersections in whatever dimensional space your heart so desires. It is generalized to be useful for any number of rays in any dimensional space.

**How it works:**
Here we use std::vectors for input and output, but internally we're using Eigen for matrix/vector math. The rays each consist of an origin and a vector direction (the vector direction is normalized on initialization of the ray objects). By combining these direction vectors into a matrix and the origins into vector, we can use the pseudo-inverse of the large matrix to calculate the ranges to the least squares intersection solution.

**How to use the library:**
This library provides two objects: `ray` and `ray_caster`.
A `ray`represents a mathematical ray: it has an origin and a vector direction. A single ray on it's own doesn't do much, but if you create several of them in a std::vector you can pass them to a `ray_caster` to do some fun things.
A `ray_caster` can be used to see where all the rays intersect (uses the linear algebra equivalent of a least squares solver to find the point of closest approach). Calling `ray_caster::range()` will return an Eigen::VectorX of the ranges from each ray origin to the point of intersection (range index 0 is the distance between ray 0 and the point of intersection, range index 1 is between ray 1 and the point of intersection, and so on).
