#pragma once
#include <memory>
class Unit;
enum class UnitEvent {
    Created,
    Damaged,
    Healed,
    Died
};

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onUnitEvent(const std::shared_ptr<Unit>& unit, UnitEvent event) = 0;
};
class IObservable {
public:
    virtual ~IObservable() = default;
    virtual void subscribe(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void unsubscribe(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void notify(UnitEvent event) = 0;
};