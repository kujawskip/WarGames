#ifndef ATTACK_H
#define ATTACK_H
class Attack {
    int attacker;
    int target;
    int accuracy;
    int damage;
public:
    int getAttacker();
    int getTarget();
    int getAccuracy();
    int getDamage();
    void setDamage(int damage);
    void setAccuracy(int accuracy);
    void setTarget(int target);
    void setAttacker(int attacker);
};
#endif // ATTACK_H
