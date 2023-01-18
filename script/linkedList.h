#pragma once
#include "gameObject.h"
#include "utility.h"

/// <summary>
/// ノード
/// </summary>
typedef struct node{
	gameObject object;				// オブジェクトのデータ

	struct node* previous;			// 前のノードへのポインタ
	struct node* next;				// 次のノードへのポインタ
}listNode;

/// <summary>
/// 連結リスト
/// </summary>
typedef struct {
	listNode dummy;					// ダミーノード
	listNode* head;					// リスト先頭

	int entryCount;					// 登録数
	enum isValid initializeFlug;	// 初期化関数を使用するか否か
}linkedList;

// 連結リスト
	// 連結リスト生成
	linkedList* createLinkedList(void);

	// 連結リスト解放
	void releaseLinkedList(linkedList* list);

	// 連結リストのメンバー初期化
	void initializeLinkedList(linkedList* list);

	// ノードを最後尾に追加
	void insertAtTail(linkedList* list, gameObject object);

	// 指定した値を持つノードを検索
	listNode* searchNode(linkedList* list, game type);

	// リストの中身をすべて描画
	void draw(linkedList* list);

	// ノードを全解放
	void clearLinkedList(linkedList* list);

// ノード
	// ノード生成
	listNode* createNode(gameObject object, listNode* previous, listNode* next);

	// ノード解放
	listNode* releaseNode(listNode* node);

	// 連結リストのメンバー初期化
	void initializeNode(listNode* node, gameObject object, listNode* previous, listNode* next);
