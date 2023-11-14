#pragma once

class Accelerometer{
    public:
        Accelerometer(const float& x, const float& y, const float& z) { x_ = x, y_ = y; z_ = z; };

    private:
        float x_, y_, z_;
};