#ifndef SPEED_H
#define SPEED_H 

class Speed
{
    public:
        Speed(int speed);
        int getEngineSpeed() const;
        Speed operator+(const Speed & speed) const;
    private:
        int speedPersent;
};

#endif /* SPEED_H */
