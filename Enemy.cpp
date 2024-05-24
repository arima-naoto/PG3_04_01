#include "Enemy.h"

void Enemy::Transition()
{
	//�����o�֐��|�C���^�ɓ����Ă���֐����Ăяo��
	(this->*currentState)();
}

//�G�̐ڋߋ���
void Enemy::Approach() 
{
	printf("�G���ڋ߂��Ă��܂���\n");
	currentState = &Enemy::BulletShot;
}

//�G�̎ˌ�����
void Enemy::BulletShot(){
	printf("�G���ˌ����Ă��܂���\n");
	currentState = &Enemy::Secede;
}

//�G�̗��E����
void Enemy::Secede() {
	printf("�G�����E���܂���\n");
	currentState = &Enemy::Approach;
}

//static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (Enemy::* Enemy::BehaviorTabel[])() = {
	&Enemy::Approach,   //�ڋߊ֐�
	&Enemy::BulletShot, //�ˌ��֐�
	&Enemy::Secede      //���E�֐�
};

//�X�V����
void Enemy::Update() 
{
	//for�����g�p���āA�����o�֐��|�C���^�ɓ����Ă���֐���3��Ăяo��
	for (int i = 0; i < 3; i++) 
	{
		(this->*BehaviorTabel[i])();
	}
}


