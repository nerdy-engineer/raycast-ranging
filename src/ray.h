#pragma once
#include <vector>
#include <Eigen/Dense>
#include <exception>
#include <iostream>

template <typename T>
class ray {
private:
	size_t dimensionality_;
	Eigen::VectorX<T> origin_;
	Eigen::VectorX<T> pointing_vector_;

public:
	ray() = delete;
	ray(const std::vector<T>& origin, const std::vector<T>& pointing_vector) :
		dimensionality_{origin.size()},
		origin_{origin.size()},
		pointing_vector_{ pointing_vector.size() }
	{
		// Origin and pointing vector must exist in the same dimension space
		if (origin.size() != pointing_vector.size()) { throw std::runtime_error("Origin and pointing vectors must be of the same dimensionality"); }
		// Fill the Eigen vectors from the std::vectors
		for (auto i{ 0 }; i < origin.size(); ++i) {
			origin_(i) = origin[i];
			pointing_vector_(i) = pointing_vector[i];
		}
		pointing_vector_.normalize();
	}
	
	size_t dimensionality() const noexcept { return dimensionality_; }
	Eigen::VectorX<T> origin() const noexcept { return origin_; }
	Eigen::VectorX<T> pointing_vector() const noexcept { return pointing_vector_; }

	friend ray<T> create_ray(const std::vector<T>& origin, const std::vector<T>& pointing_vector);

	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const ray<U>& r);
};

template <typename T>
ray<T> create_ray(const std::vector<T>& origin, const std::vector<T>& pointing_vector) {
	return { origin, pointing_vector };
}

template <typename U>
std::ostream& operator<<(std::ostream& out, const ray<U>& r)
{
	out << "Origin: \n" << r.origin_ << '\n';
	out << "Pointing vector: \n" << r.pointing_vector_ << '\n';
	return out;
}

