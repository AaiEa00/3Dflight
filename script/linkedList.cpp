#include "linkedList.h"

/// <summary>
/// 連結リスト生成
/// </summary>
/// <returns>生成した連結リスト</returns>
linkedList* createLinkedList(void)
{
	// リスト生成
	linkedList* list = (linkedList*)malloc(sizeof(linkedList));
	if (list == NULL)
		exit(MEMORY_ERROR);

	// メンバー初期化
	initializeLinkedList(list);

	return list;
}

/// <summary>
/// 連結リストの解放
/// </summary>
/// <param name="list">連結リスト</param>
void releaseLinkedList(linkedList* list)
{
	// ノードを全解放
	clearLinkedList(list);

	// 連結リスト解放
	free(list);
}

/// <summary>
/// 連結リストのメンバー初期化
/// </summary>
/// <param name="list">連結リスト</param>
void initializeLinkedList(linkedList* list)
{
	// ダミーノードの構造体を初期化
	list->dummy.object.model = 0;
	list->dummy.object.position = ZERO_VECTOR;
	list->dummy.object.rotation = ZERO_VECTOR;
	list->dummy.object.type = game::gameNum;
	// ダミーノードの前と次のノードをダミーノードに設定
	list->dummy.next = &list->dummy;
	list->dummy.previous = &list->dummy;

	// 先頭ノードをダミーノードに設定
	list->head = &list->dummy;

	// 登録数を０で初期化
	list->entryCount = 0;

	// 初期化関数を使用可能に設定
	list->initializeFlug = isValid::valid;
}

/// <summary>
/// 最後尾にノードを追加
/// </summary>
/// <param name="list">連結リスト</param>
/// <param name="object">追加するデータ</param>
void insertAtTail(linkedList* list, gameObject object)
{
	// 追加するノードを作成
	listNode* node = createNode(object, list->head->previous, list->head);

	// 連結させる
	list->head->previous->next = node;
	list->head->previous = node;

	// 登録数を増加
	list->entryCount++;
}

/// <summary>
/// 指定した値を持つノードを検索
/// </summary>
/// <param name="list">連結リスト</param>
/// <param name="type">指定したゲームオブジェクトの種類</param>
/// <returns>見つかったノード（見つからなかったらNULL）</returns>
listNode* searchNode(linkedList* list, game type)
{
	listNode* node = list->head->next;

	while (node != list->head)
	{
		if (type == node->object.type)
			return node;

		node = node->next;
	}

	return NULL;
}

/// <summary>
/// 描画
/// </summary>
/// <param name="list">連結リスト</param>
void draw(linkedList* list)
{
	listNode* node = list->head->next;

	while (node != list->head)
	{
		MV1DrawModel(node->object.model);
		node = node->next;
	}
}

/// <summary>
/// ノードを全解放
/// </summary>
/// <param name="list">連結リスト</param>
void clearLinkedList(linkedList* list)
{
	// ノードを全解放するまでループ
	while (list->head->next != list->head)
	{
		// 先頭ノードの次のポインタを渡す
		list->head->next = releaseNode(list->head->next);
		list->entryCount--;
	}
}

/// <summary>
/// ノード生成
/// </summary>
/// <param name="object">ゲームオブジェクトのデータ</param>
/// <param name="previous">前のノード</param>
/// <param name="next">次のノード</param>
/// <returns>生成したノード</returns>
listNode* createNode(gameObject object, listNode* previous, listNode* next)
{
	// ノード生成
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if (node == NULL)
		exit(MEMORY_ERROR);

	// ノードのデータを設定
	initializeNode(node, object, previous, next);

	return node;
}

/// <summary>
/// ノードを解放
/// </summary>
/// <param name="node">ノードのデータ</param>
/// <returns></returns>
listNode* releaseNode(listNode* node)
{
	// 解放するノードの前のノードへのポインタを保存
	listNode* previous = node->previous;

	// 解放するノードを連結から外す
	node->next->previous = previous;
	previous->next = node->next;

	free(node);

	return previous->next;
}

/// <summary>
/// ノードの設定
/// </summary>
/// <param name="node">設定するノード</param>
/// <param name="object">追加するゲームオブジェクトのデータ</param>
/// <param name="previous">前のノードへのポインタ</param>
/// <param name="next">次のノードへのポインタ</param>
void initializeNode(listNode* node, gameObject object, listNode* previous, listNode* next)
{
	node->object = object;
	node->previous = previous;
	node->next = next;
}
