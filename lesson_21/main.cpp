#include <iostream>
#include <vector>
#include <algorithm>


class Hero;

enum class Event {
    CURSE_APPLIED,
    DAMAGE_DEALT
};

class Observer {
public:
    virtual ~Observer() {}
    virtual void onNotify(const Hero& hero, Event event) = 0;
};

class Subject {
public:
    virtual ~Subject() {}
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const Hero& hero, Event event) = 0;
};

class Hero : public Observer {
private:
    std::string name;
    int health;

public:
    Hero(const std::string& name, int health) : name(name), health(health) {}

    std::string getName() const { return name; }
    int getHealth() const { return health; }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void onNotify(const Hero& hero, Event event) override {
        if (event == Event::CURSE_APPLIED) {
            std::cout << name << "is notified, that " << hero.getName() << " has been cursed!\n";
        } else if (event == Event::DAMAGE_DEALT) {
            std::cout << name << "is notified, that " << hero.getName() << " received damage. Health is now: " << hero.getHealth() << "\n";
        }
    }
};

class CurseTower : public Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(const Hero& hero, Event event) override {
        for (Observer* observer : observers) {
            observer->onNotify(hero, event);
        }
    }

    void curseHero(Hero& hero) {
        addObserver(&hero);
        notifyObservers(hero, Event::CURSE_APPLIED);
    }

    void applyCurseDamage(int damage) {
        std::cout << "Curse Tower: Applying curse damage of " << damage << " to all cursed heroes!\n";
        for (Observer* observer : observers) {
            Hero* hero = dynamic_cast<Hero*>(observer);
            if (hero) {
                hero->takeDamage(damage);
                notifyObservers(*hero, Event::DAMAGE_DEALT);
            }
        }
    }
};

int main() {
    CurseTower curseTower;

    Hero hero1("Ragnulf Ironbeard", 100);
    Hero hero2("Astrid Stormbringer", 80);
    Hero hero3("Bjorn Bloodaxe", 60);

    curseTower.curseHero(hero1);
    curseTower.curseHero(hero2);
    curseTower.curseHero(hero3);

    curseTower.applyCurseDamage(30);

    return 0;
}
