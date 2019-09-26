#pragma once

#include "MathTemplate.h"

namespace altseed {

/**
@brief	2�����x�N�g��(����)
*/
struct Vector2DI {
public:
    /**
    @brief	X
    */
    int32_t X;

    /**
    @brief	Y
    */
    int32_t Y;

    /**
    @brief	�R���X�g���N�^
    */
    Vector2DI();

    /**
    @brief	�R���X�g���N�^
    */
    Vector2DI(int32_t x, int32_t y);

    bool operator==(const Vector2DI& o);

    bool operator!=(const Vector2DI& o);

    Vector2DI operator-();

    Vector2DI operator+(const Vector2DI& right);

    Vector2DI operator-(const Vector2DI& right);

    Vector2DI operator*(const Vector2DI& right);

    Vector2DI operator/(const Vector2DI& right);

    Vector2DI operator*(int32_t right);

    Vector2DI operator/(int32_t right);

    Vector2DI& operator+=(const Vector2DI& right);

    Vector2DI& operator-=(const Vector2DI& right);

    Vector2DI& operator*=(const Vector2DI& right);

    Vector2DI& operator/=(const Vector2DI& right);

    Vector2DI& operator*=(int32_t right);

    Vector2DI& operator/=(int32_t right);

    /**
    @brief	Vector2DF�^�ɕϊ�����B
    @return	Vector2DF�^
    */
    Vector2DF To2DF() const;

    /**
    @brief	�X�J���[�ŏ��Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector2DI DivideByScalar(const Vector2DI& v1, float v2);
};
}  // namespace altseed