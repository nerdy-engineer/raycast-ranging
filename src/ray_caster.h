#pragma once
#include <algorithm>
#include <exception>
#include <Eigen/Dense>
#include "ray.h"

template <typename T>
class ray_caster {
private:
	std::vector<ray<T>> rays_;
	size_t dimensionality_;

public:
	ray_caster(const std::vector<ray<T>>& rays) :
		rays_{ rays },
		dimensionality_{ rays[0].dimensionality() }
	{
		if (!all_of(rays.begin(), rays.end(), [this](const ray<T>& r) { return r.dimensionality() == this->dimensionality_; })) {
			throw std::runtime_error("All rays must be of the same dimensionality");
		}
	}

	Eigen::VectorX<T> range() const noexcept;


	friend ray_caster<T> create_ray_caster(const std::vector<ray<T>>& rays);
};

template <typename T>
ray_caster<T> create_ray_caster(const std::vector<ray<T>>& rays) {
	return { rays };
}