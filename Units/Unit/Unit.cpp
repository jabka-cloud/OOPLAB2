#include "Unit.h"
#include <algorithm>

// Определение и инициализация статического счетчика ID вне методов класса
int Unit::nextId = 1;

// === Реализация операторов структуры Position ===

bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}

// === Реализация методов базового класса Unit ===

Unit::Unit(UnitType type, int startX, int startY)
    : id(nextId++),
      typeInfo(UnitTypeInfo::getInfo(type)),
      health(typeInfo->getMaxHealth()),
      position(startX, startY) {}

void Unit::subscribe(const std::shared_ptr<IObserver>& observer) {
    if (!observer) return;

    // Проверяем, не подписан ли уже этот наблюдатель, чтобы избежать дубликатов
    for (const auto& weakObs : observers) {
        if (weakObs.lock() == observer) {
            return;
        }
    }
    observers.push_back(observer);
}

void Unit::unsubscribe(const std::shared_ptr<IObserver>& observer) {
    // Используем std::remove_if: сравниваем живой указатель (.lock()) или заодно чистим "мертвые" (.expired())
    auto it = std::remove_if(observers.begin(), observers.end(),
        [&observer](const std::weak_ptr<IObserver>& weakObs) {
            auto locked = weakObs.lock();
            return !locked || locked == observer;
        });

    observers.erase(it, observers.end());
}

void Unit::notify(UnitEvent event) {
    // Безопасный обход списка наблюдателей с попутной очисткой удаленных объектов
    auto it = observers.begin();
    while (it != observers.end()) {
        if (auto observer = it->lock()) {
            // Превращаем weak_ptr во временный shared_ptr и вызываем метод уведомления
            observer->onUnitEvent(shared_from_this(), event);
            ++it;
        } else {
            // Если база уже уничтожена, удаляем пустой weak_ptr из вектора
            it = observers.erase(it);
        }
    }
}

std::string Unit::getType() const {
    return typeInfo->getTypeName();
}

int Unit::getId() const {
    return id;
}

int Unit::getHealth() const {
    return health;
}

const Position& Unit::getPosition() const {
    return position;
}

std::shared_ptr<UnitTypeInfo> Unit::getTypeInfo() const {
    return typeInfo;
}
