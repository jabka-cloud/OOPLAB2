#pragma once
#include <vector>
#include "UnitTypeInfo.h"
#include "IObserver.h"
struct Position{
    int x;
    int y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;
};
class Unit : public IObservable, public std::enable_shared_from_this<Unit>{
private:
    static int nextId;
    int id;
    std::shared_ptr<UnitTypeInfo> typeInfo;
    std::vector<std::weak_ptr<IObserver>> observers;
protected:
    int health;
    Position position;

    Unit(UnitType type, int startX, int startY);

public:
    virtual ~Unit() = default;


    Unit(const Unit&) = delete;
    Unit& operator=(const Unit&) = delete;

    void subscribe(const std::shared_ptr<IObserver>& observer) override;
    void unsubscribe(const std::shared_ptr<IObserver>& observer) override;
    void notify(UnitEvent event) override;

    std::string getType() const;
    int getId() const;
    int getHealth() const;
    const Position& getPosition() const;
    std::shared_ptr<UnitTypeInfo> getTypeInfo() const;

    virtual void move(const Position& newPos) = 0;
    virtual void attack(const std::shared_ptr<Unit>& target) = 0;
    virtual void takeDamage(int amount) = 0;
};  