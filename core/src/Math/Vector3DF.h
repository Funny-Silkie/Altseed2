#pragma once

#include "MathTemplate.h"

namespace altseed {
/**
        @brief	3�����x�N�g��
*/
struct Vector3DF {
public:
    /**
            @brief	X����
    */
    float X;

    /**
            @brief	Y����
    */
    float Y;

    /**
            @brief	Z����
    */
    float Z;

    /**
            @brief	�R���X�g���N�^
    */
    Vector3DF();

    /**
    @brief	�R���X�g���N�^
    @param	x	X����
    @param	y	Y����
    @param	z	Z����
    */
    Vector3DF(float x, float y, float z);

    bool operator==(const Vector3DF& o);
    bool operator!=(const Vector3DF& o);
    bool operator>(const Vector3DF& o) const;
    bool operator<(const Vector3DF& o) const;

    Vector3DF operator-();

    Vector3DF operator+(const Vector3DF& o) const;

    Vector3DF operator-(const Vector3DF& o) const;

    Vector3DF operator*(const Vector3DF& o) const;

    Vector3DF operator/(const Vector3DF& o) const;

    Vector3DF operator*(const float& o) const;

    Vector3DF operator/(const float& o) const;

    Vector3DF& operator+=(const Vector3DF& o);

    Vector3DF& operator-=(const Vector3DF& o);

    Vector3DF& operator*=(const Vector3DF& o);

    Vector3DF& operator/=(const Vector3DF& o);

    Vector3DF& operator*=(const float& o);

    Vector3DF& operator/=(const float& o);

    /**
    @brief	���̃x�N�g���̒������擾����B
    */
    float GetLength() const { return sqrt(GetSquaredLength()); }

    /**
    @brief	���̃x�N�g���̒����̓����擾����B
    */
    float GetSquaredLength() const { return X * X + Y * Y + Z * Z; }

    /**
    @brief	���̃x�N�g���̒�����ݒ肷��B
    */
    void SetLength(float value) {
        float length = GetLength();
        (*this) *= (value / length);
    }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g�����擾����B
    */
    Vector3DF GetNormal() {
        float length = GetLength();
        return Vector3DF(X / length, Y / length, Z / length);
    }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g��������B
    */
    void Normalize() {
        float length = GetLength();
        (*this) /= length;
    }

    /**
    @brief	���ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return ����v1�Ev2
    */
    static float Dot(const Vector3DF& v1, const Vector3DF& v2);

    /**
    @brief	�O�ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return �O��v1�~v2
    @note
    �E��̐e�w��v1�A�l�����w��v2�Ƃ����Ƃ��A���w�̕�����Ԃ��B
    */
    static Vector3DF Cross(const Vector3DF& v1, const Vector3DF& v2);

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1+v2
    */
    static Vector3DF Add(Vector3DF v1, Vector3DF v2) { return Vector3DF(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z); }

    /**
    @brief	���Z����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1-v2
    */
    static Vector3DF Subtract(Vector3DF v1, Vector3DF v2);

    /**
    @brief	���Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector3DF Divide(const Vector3DF& v1, const Vector3DF& v2) { return Vector3DF(v1.X / v2.X, v1.Y / v2.Y, v1.Z / v2.Z); }

    /**
    @brief	�X�J���[�ŏ��Z����B
    @param	v1	�l1
    @param	v2	�l2
    @return	v1/v2
    */
    static Vector3DF DivideByScalar(const Vector3DF& v1, float v2) { return Vector3DF(v1.X / v2, v1.Y / v2, v1.Z / v2); }

    /**
    @brief	2�_�Ԃ̋������擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1��v2�̋���
    */
    static float Distance(const Vector3DF& v1, const Vector3DF& v2);
};
}  // namespace altseed