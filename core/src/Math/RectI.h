#pragma once

#include <array>
#include "MathTemplate.h"
#include "asd.Vector2DI.h"

namespace altseed {
/**
        @brief	�����`(����)�̍\����
*/
struct RectI {
public:
    /**
            @brief	����X���W
    */
    int X;

    /**
            @brief	����Y���W
    */
    int Y;

    /**
            @brief	����
    */
    int Width;

    /**
            @brief	�c��
    */
    int Height;

    /**
            @brief	�R���X�g���N�^
    */
    RectI();

    /**
            @brief	�R���X�g���N�^
            @param	x	����X���W
            @param	y	����Y���W
            @param	width	����
            @param	height	�c��
    */
    RectI(int x, int y, int width, int height);

    /**
    @brief	�R���X�g���N�^
    @param	position	������W
    @param	size	�傫��
    */
    RectI(Vector2DI position, Vector2DI size);

    /**
            @brief	������W���擾����B
            @return	������W
    */
    Vector2DI GetPosition() const;

    /**
            @brief	�傫�����擾����B
            @return	�傫��
    */
    Vector2DI GetSize() const;

    /**
            @brief	�l���̍��W��(X,Y)�A(X+Width,Y)�A(X+Width,Y+Height)�A(X,Y+Height)�̏��ɔz��Ƃ��Ď擾����B
            @return	���W
    */
    std::array<Vector2DI, 4> GetVertexes() const;

    bool operator==(const RectI& other) const;

    /**
    @brief	RectF�^�ɕϊ�����B
    @return	RectF�^
    */
    RectF ToF() const;
};
}  // namespace altseed