#pragma once

#include "MathTemplate.h"
#include "Vector4DI.h"

namespace altseed {
/**
@brief	4�����x�N�g��
*/
struct Vector4DF {
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
    @brief	W����
    */
    float W;

    /**
    @brief	�R���X�g���N�^
    */
    Vector4DF();

    /**
    @brief	�R���X�g���N�^
    @param	x	X����
    @param	y	Y����
    @param	z	Z����
    @param	w	W����
    */
    Vector4DF(float x, float y, float z, float w);

    /**
    @brief	���̃x�N�g���̒������擾����B
    */
    float GetLength() const { return sqrt(GetSquaredLength()); }

    /**
    @brief	���̃x�N�g���̒����̓����擾����B
    */
    float GetSquaredLength() const { return X * X + Y * Y + Z * Z + W * W; }

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
    Vector4DF GetNormal() {
        float length = GetLength();
        return Vector4DF(X / length, Y / length, Z / length, W / length);
    }

    /**
    @brief	���̃x�N�g���̒P�ʃx�N�g��������B
    */
    void Normalize() {
        float length = GetLength();
        (*this) /= length;
    }

    bool operator==(const Vector4DF& o);
    bool operator!=(const Vector4DF& o);

    Vector4DF operator-();

    Vector4DF operator+(const Vector4DF& o) const;

    Vector4DF operator-(const Vector4DF& o) const;

    Vector4DF operator*(const Vector4DF& o) const;

    Vector4DF operator/(const Vector4DF& o) const;

    Vector4DF operator*(const float& o) const;

    Vector4DF operator/(const float& o) const;

    Vector4DF& operator+=(const Vector4DF& o);

    Vector4DF& operator-=(const Vector4DF& o);

    Vector4DF& operator*=(const Vector4DF& o);

    Vector4DF& operator/=(const Vector4DF& o);

    Vector4DF& operator*=(const float& o);

    Vector4DF& operator/=(const float& o);

    /**
    @brief	���ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return ����v1�Ev2
    */
    static float Dot(const Vector4DF& v1, const Vector4DF& v2);

    /**
    @brief	2�_�Ԃ̋������擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1��v2�̋���
    */
    static float Distance(const Vector4DF& v1, const Vector4DF& v2);

    /**
     @brief	Vector4DI�^�ɕϊ�����B
     @return	Vector4DI�^
         */
    Vector4DI To4DI() const;
};
}  // namespace altseed