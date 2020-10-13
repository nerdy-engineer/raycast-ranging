#include "ray_caster.h"


template <typename T>
Eigen::VectorX<T> ray_caster<T>::range() const noexcept {
	Eigen::MatrixX<T> slopes = Eigen::MatrixX<T>::Zero(dimensionality_ * (rays_.size() - 1), rays_.size());
	Eigen::VectorX<T> deltaP(dimensionality_ * (rays_.size() - 1));
	for (auto x{ 0 }; x < slopes.rows(); ++x) {
		// Notes: Using x % dimensionality will repeat after every set of dimensions (so every after every completed tuple)
		//        Using x / dimensionality will increment after every completed tuple
		auto ray_number = 1 + x / dimensionality_;
		auto axis = x % dimensionality_;
		// Loop through the dimensions of the reference ray and fill the first column of the slope matrix
		slopes(x, 0) = rays_[0].pointing_vector()[axis];
		// This is supposed to fill the rest of the appropriate slots
		slopes(x, ray_number) = -1 * rays_[ray_number].pointing_vector()[axis];
		deltaP(x) = rays_[ray_number].origin()[axis] - rays_[0].origin()[axis];
	}
	// Perform calculation and return
	return slopes.completeOrthogonalDecomposition().pseudoInverse() * deltaP;
}