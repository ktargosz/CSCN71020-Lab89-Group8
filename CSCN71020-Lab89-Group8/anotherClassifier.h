#pragma once
#include "classifier.h"

/// @file anotherClassifier.h
/// @brief This file contains the class anotherClassifier
/// @author Group 8
/// @date April 2022

class anotherClassifier : public classifier
{
    virtual double classify(position unknown) override;
};