#pragma once

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "MathTemplate.h"
#include "Vector4DI.h"
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace altseed {
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------

/**
        @brief	4�~4�s���\���\����
        @note
        M * V[x,y,z,1] �̌`<BR>
        [0,0][0,1][0,2][0,3]
        [1,0][1,1][1,2][1,3]
        [2,0][2,1][2,2][2,3]
        [3,0][3,1][3,2][3,3]
*/
struct Matrix44I {
private:
public:
    /**
            @brief	�I�u�W�F�N�g�𐶐����A�P�ʍs��ŏ���������B
    */
    Matrix44I();

    /**
            @brief	�s��̒l
    */
    int32_t Values[4][4];

    /**
            @brief	�P�ʍs���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetIdentity();

    /**
            @brief	�]�u�s���ݒ肷��B
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetTransposed();

    /**
            @brief	���s�ړ��s���ݒ肷��B
            @param	x	X�����ړ���
            @param	y	Y�����ړ���
            @param	z	Z�����ړ���
            @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetTranslation(int32_t x, int32_t y, int32_t z);

    /**
    @brief	�N�I�[�^�j�I�������ɉ�]�s��(�E��)��ݒ肷��B
    @param	x	�N�I�[�^�j�I��
    @param	y	�N�I�[�^�j�I��
    @param	z	�N�I�[�^�j�I��
    @param	w	�N�I�[�^�j�I��
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetQuaternion(int32_t x, int32_t y, int32_t z, int32_t w);

    /**
    @brief	�g��s���ݒ肷��B
    @param	x	X�����g�嗦
    @param	y	Y�����g�嗦
    @param	z	Z�����g�嗦
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix44I& SetScale(int32_t x, int32_t y, int32_t z);

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector4DI Transform4D(const Vector4DI& in) const;

    Matrix44I operator*(const Matrix44I& right) const;

    Vector4DI operator*(const Vector4DI& right) const;

    /**
            @brief	��Z���s���B
            @param	o	�o�͐�
            @param	in1	�s��1
            @param	in2	�s��2
            @return	�o�͐�̎Q��z
    */
    static Matrix44I& Mul(Matrix44I& o, const Matrix44I& in1, const Matrix44I& in2);
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}  // namespace altseed
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------