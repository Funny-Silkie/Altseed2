#pragma once
#include "Vector2DF.h"
#include "Vector3DF.h"

namespace altseed {
/**
        @brief	3�~3�s���\���\���́B
        @note
        [0,0][0,1]
        [1,0][1,1]
        */
struct Matrix33F {
public:
    /**
            @brief	�I�u�W�F�N�g�𐶐����A�P�ʍs��ŏ���������B
    */
    Matrix33F();

    /**
            @brief	�s��̒l
    */
    float Values[3][3];

    /**
            @brief	�P�ʍs���ݒ肷��B
    */
    Matrix33F& SetIdentity();

    /**
    @brief	�]�u�s���ݒ肷��B
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix33F& SetTransposed();

    /**
    @brief	�t�s���ݒ肷��B
    @return	���̃C���X�^���X�ւ̎Q��
    */
    Matrix33F& SetInverted();

    /**
    @brief	�t�s����擾����B
    @return	�t�s��
    */
    Matrix33F GetInverted();

    /**
            @brief	���s�ړ��̍s���ݒ肷��B
	*/
    Matrix33F& SetTranslation(float x, float y);

    /**
    @brief	��]�s���ݒ肷��B
    */
    Matrix33F& SetRotation(float angle);

    /**
            @brief	�g��E�k���s���ݒ肷��B
    */
    Matrix33F& SetScale(float x, float y);

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector2DF Transform2D(const Vector2DF& in) const;

    /**
    @brief	�s��Ńx�N�g����ό`������B
    @param	in	�ό`�O�x�N�g��
    @return	�ό`��x�N�g��
    */
    Vector3DF Transform3D(const Vector3DF& in) const;

    /**
    @brief	3�~3�s��̊|���Z���v�Z����B
            */
    Matrix33F operator*(const Matrix33F& right);

    Vector3DF operator*(const Vector3DF& right);
};
}  // namespace asd