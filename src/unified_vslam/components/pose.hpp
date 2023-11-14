#pragma once


namespace unified_slam::components{
    class Pose{
        private:
            float tx_, ty_, tz_, qx_, qy_, qz_;
        public:
            Pose() : tx_(0), ty_(0), tz_(0), qx_(0), qy_(0), qz_(0) {}
            Pose(const float& tx, const float& ty, const float& tz, const float& qx, const float& qy, const float& qz)
                : tx_(tx), ty_(ty), tz_(tz), qx_(qx), qy_(qy), qz_(qz) {}

            // Getters
            float get_tx() const { return tx_; }
            float get_ty() const { return ty_; }
            float get_tz() const { return tz_; }
            float get_qx() const { return qz_; }
            float get_qy() const { return qy_; }
            float get_gz() const { return qz_;}

            // Setters
            float set_tx(const float& tx) { tx_ = tx; }
            float set_ty(const float& ty) { ty_ = ty; }
            float set_tz(const float& tz) { tz_ = tz; }
            float set_qx(const float& qx) { qx_ = qx; }
            float set_qy(const float& qy) { qy_ = qy; }
            float set_qz(const float& qz) { qz_ = qz; }
    };
}
