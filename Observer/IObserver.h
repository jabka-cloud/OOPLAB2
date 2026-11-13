#pragma once
#include <memory>
class IObserver {
public:
    virtual void onBaseStatusChanged() = 0;
    virtual ~IObserver() = default;
};