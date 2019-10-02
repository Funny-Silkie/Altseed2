#pragma once

#include "MathTemplate.h"
#include "Vector4DF.h"

namespace altseed {
/**
@brief	4�����x�N�g��
*/
struct Vector4DI {
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
    @brief	W����
    */
    int32_t W;

    /**
    @brief	�R���X�g���N�^
    */
    Vector4DI();

    /**
    @brief	�R���X�g���N�^
    @param	x	X����
    @param	y	Y����
    @param	z	Z����
    @param	w	W����
    */
    Vector4DI(int32_t x, int32_t y, int32_t z, int32_t w);

    /**
    @brief	���̃x�N�g���̒������擾����B
    */
    float GetLength() const { return sqrt(GetSquaredLength()); }

    /**
    @brief	���̃x�N�g���̒����̓����擾����B
    */
    int32_t GetSquaredLength() const { return X * X + Y * Y + Z * Z + W * W; }

    bool operator==(const Vector4DI& o);
    bool operator!=(const Vector4DI& o);

    Vector4DI operator-();

    Vector4DI operator+(const Vector4DI& o) const;

    Vector4DI operator-(const Vector4DI& o) const;

    Vector4DI operator*(const Vector4DI& o) const;

    Vector4DI operator/(const Vector4DI& o) const;

    Vector4DI operator*(const int32_t& o) const;

    Vector4DI operator/(const int32_t& o) const;

    Vector4DI& operator+=(const Vector4DI& o);

    Vector4DI& operator-=(const Vector4DI& o);

    Vector4DI& operator*=(const Vector4DI& o);

    Vector4DI& operator/=(const Vector4DI& o);

    Vector4DI& operator*=(const int32_t& o);

    Vector4DI& operator/=(const int32_t& o);

    /**
    @brief	���ς��擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return ����v1�Ev2
    */
    static int32_t Dot(const Vector4DI& v1, const Vector4DI& v2);

    /**
    @brief	2�_�Ԃ̋������擾����B
    @param	v1	v1�x�N�g��
    @param	v2	v2�x�N�g��
    @return v1��v2�̋���
    */
    static float Distance(const Vector4DI& v1, const Vector4DI& v2);

	/**
	@brief	Vector4DF�^�ɕϊ�����B
	@return	Vector4DF�^
	*/
    Vector4DF To4DF() const;
};
}  // namespace altseed