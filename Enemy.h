#pragma once
#include <stdio.h>

/// <summary>
/// Enemy�N���X�̍쐬
/// </summary>
class Enemy
{
private://�����o�֐�

	//���݂̏�Ԃ�\�������o�֐��|�C���^
	void (Enemy::*currentState)();

	//�֐��e�[�u��
	static void (Enemy::*BehaviorTabel[])();

public://�����o�֐��̍쐬
	
	/// <summary>
	/// ��ԑJ�ڃ����o�֐�
	/// </summary>
	void Transition();

	/// <summary>
	/// �ڋ߃����o�֐�
	/// </summary>
	void Approach();

	/// <summary>
	/// �ˌ������o�֐�
	/// </summary>
	void BulletShot();

	/// <summary>
	/// ���E�����o�֐�
	/// </summary>
	void Secede();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

};

