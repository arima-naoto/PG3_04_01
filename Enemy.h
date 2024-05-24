#pragma once
#include <stdio.h>

/// <summary>
/// Enemyクラスの作成
/// </summary>
class Enemy
{
private://メンバ関数

	//現在の状態を表すメンバ関数ポインタ
	void (Enemy::*currentState)();

	//関数テーブル
	static void (Enemy::*BehaviorTabel[])();

public://メンバ関数の作成
	
	/// <summary>
	/// 状態遷移メンバ関数
	/// </summary>
	void Transition();

	/// <summary>
	/// 接近メンバ関数
	/// </summary>
	void Approach();

	/// <summary>
	/// 射撃メンバ関数
	/// </summary>
	void BulletShot();

	/// <summary>
	/// 離脱メンバ関数
	/// </summary>
	void Secede();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

};

