#include "Enemy.h"

void Enemy::Transition()
{
	//メンバ関数ポインタに入っている関数を呼び出す
	(this->*currentState)();
}

//敵の接近挙動
void Enemy::Approach() 
{
	printf("敵が接近してきました\n");
	currentState = &Enemy::BulletShot;
}

//敵の射撃挙動
void Enemy::BulletShot(){
	printf("敵が射撃してきました\n");
	currentState = &Enemy::Secede;
}

//敵の離脱挙動
void Enemy::Secede() {
	printf("敵が離脱しました\n");
	currentState = &Enemy::Approach;
}

//staticで宣言したメンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::BehaviorTabel[])() = {
	&Enemy::Approach,   //接近関数
	&Enemy::BulletShot, //射撃関数
	&Enemy::Secede      //離脱関数
};

//更新処理
void Enemy::Update() 
{
	//for分を使用して、メンバ関数ポインタに入っている関数を3回呼び出す
	for (int i = 0; i < 3; i++) 
	{
		(this->*BehaviorTabel[i])();
	}
}


