#pragma once

#include "MathTemplate.h"
#include "Vector3DF.h"

namespace altseed {
/**
        @brief	3�����x�N�g��
*/
struct Vector3DI {
public:
    /**
            @brief	X����
    */
    int32_t X;

    /**
            @brief	Y����
    */
    int32_t Y;

    /**
            @brief	Z����
    */
    int32_t Z;

    /**
            @brief	�R���X�g���N�^
    */
    Vector3DI();

    /**
    @brief	�R���X�g���N�^
    @param	x	X����
    @param	y	Y����
    @param	z	Z����
    */
    Vector3DI(int32_t x, int32_t y, int32_t z);

    bool operator==(const Vector3DI& o);
    bool operator!=(const Vector3DI& o);
    bool operator>(const Vector3DI& o) const;
    bool operator<(const Vector3DI& o) const;

    Vector3DI operator-();

    Vector3DI operator+(const Vector3DI& o) const;

    Vector3DI operator-(const Vector3DI& o) const;

    Vector3DI operator*(const Vector3DI& o) const;

    Vector3DI operator/(const Vector3DI& o) const;

    Vector3DI operator*(const int32_t& o) const;

    Vector3DI operator/(const int32_t& o) const;

    Vector3DI& operator+=(const Vector3DI& o);

    Vector3DI& operator-=(const Vector3DI& o);

    Vector3DI& operator*=(const Vector3DI& o);

    Vector3DI& operator/=(const Vector3DI& o);

    Vector3DI& operator*=(const int32_t& o);

    Vector3DI& operator/=(const int32_t& o);

    /**
    @brief	���̃x�N�g���̒������擾����B
    */
    float GetLength() const { return sqrt(GetSquaredLength()); }

    /**
    @brief	���̃x�N�g���̒����̓����擾����B
    */
    int32_t GetSquaredLength() const { return X * X + Y * Y + Z * Z; }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g�����擾����B
    */
    Vector3DF GetNormal() {
        float length = GetLength();
        return Vector3DF(X / length, Y / length, Z / length);
    }

    /**
    @brief	���ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return ����v1�Ev2
    */
    static int32_t Dot(const Vector3DI& v1, const Vector3DI& v2);

    /**
    @brief	�O�ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return �O��v1�~v2
    @note
    �E��̐e�w��v1�A�l�����w��v2�Ƃ����Ƃ��A���w�̕�����Ԃ��B
    */
    static Vector3DI Cross(const Vector3DI& v1, const Vector3DI& v2);

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1+v2
    */
    static Vector3DI Add(Vector3DI v1, Vector3DI v2) { return Vector3DI(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z); }

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1-v2
    */
    static Vector3DI Subtract(Vector3DI v1, Vector3DI v2);

    /**
    @brief	���Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector3DI Divide(const Vector3DI& v1, const Vector3DI& v2) { return Vector3DI(v1.X / v2.X, v1.Y / v2.Y, v1.Z / v2.Z); }

    /**
    @brief	�X�J���[�ŏ��Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector3DI DivideByScalar(const Vector3DI& v1, float v2) { return Vector3DI(v1.X / v2, v1.Y / v2, v1.Z / v2); }

    /**
    @brief	2�_�Ԃ̋������擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1��v2�̋���
    */
    static float Distance(const Vector3DI& v1, const Vector3DI& v2);

    /**
            @brief	Vector3DF�^�ɕϊ�����B
            @return	Vector3DF�^
    */
    Vector3DF To3DF() const;
};
}  // namespace altseed