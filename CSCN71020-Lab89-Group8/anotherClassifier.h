#pragma once
#include "classifier.h"
class AnotherClassifier :
    public Classifier
{
    virtual double Classify(Position unknown) override;
};
