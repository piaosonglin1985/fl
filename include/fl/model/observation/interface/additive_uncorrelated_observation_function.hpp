/*
 * This is part of the FL library, a C++ Bayesian filtering library
 * (https://github.com/filtering-library)
 *
 * Copyright (c) 2014 Jan Issac (jan.issac@gmail.com)
 * Copyright (c) 2014 Manuel Wuthrich (manuel.wuthrich@gmail.com)
 *
 * Max-Planck Institute for Intelligent Systems, AMD Lab
 * University of Southern California, CLMC Lab
 *
 * This Source Code Form is subject to the terms of the MIT License (MIT).
 * A copy of the license can be found in the LICENSE file distributed with this
 * source code.
 */

/**
 * \file additive_uncorrelated_observation_function.hpp
 * \date June 2015
 * \author Jan Issac (jan.issac@gmail.com)
 */

#ifndef FL__MODEL__OBSERVATION__ADDITIVE_UNCORRELATED_OBSERVATION_FUNCTION_HPP
#define FL__MODEL__OBSERVATION__ADDITIVE_UNCORRELATED_OBSERVATION_FUNCTION_HPP

#include <fl/util/traits.hpp>

#include <fl/model/observation/interface/additive_observation_function.hpp>

namespace fl
{

template <
    typename Obsrv,
    typename State,
    typename Noise,
    int Id = 0
>
class AdditiveUncorrelatedObservationFunction
    : public AdditiveObservationFunction<Obsrv, State, Noise, Id>
{
public:
    typedef AdditiveObservationFunction<
                Obsrv, State, Noise, Id
            >  AdditiveFunctionInterface;

    typedef Eigen::DiagonalMatrix<
                typename Noise::Scalar,
                SizeOf<Obsrv>::Value
            > NoiseDiagonal;
public:
    /**
     * \brief Overridable default destructor
     */
    virtual ~AdditiveUncorrelatedObservationFunction() { }

    virtual const NoiseDiagonal& noise_matrix_diagonal() const = 0;
    virtual const NoiseDiagonal& noise_covariance_diagonal() const = 0;
};

}

#endif
