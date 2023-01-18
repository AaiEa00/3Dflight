#include "linkedList.h"

/// <summary>
/// �A�����X�g����
/// </summary>
/// <returns>���������A�����X�g</returns>
linkedList* createLinkedList(void)
{
	// ���X�g����
	linkedList* list = (linkedList*)malloc(sizeof(linkedList));
	if (list == NULL)
		exit(MEMORY_ERROR);

	// �����o�[������
	initializeLinkedList(list);

	return list;
}

/// <summary>
/// �A�����X�g�̉��
/// </summary>
/// <param name="list">�A�����X�g</param>
void releaseLinkedList(linkedList* list)
{
	// �m�[�h��S���
	clearLinkedList(list);

	// �A�����X�g���
	free(list);
}

/// <summary>
/// �A�����X�g�̃����o�[������
/// </summary>
/// <param name="list">�A�����X�g</param>
void initializeLinkedList(linkedList* list)
{
	// �_�~�[�m�[�h�̍\���̂�������
	list->dummy.object.model = 0;
	list->dummy.object.position = ZERO_VECTOR;
	list->dummy.object.rotation = ZERO_VECTOR;
	list->dummy.object.type = game::gameNum;
	// �_�~�[�m�[�h�̑O�Ǝ��̃m�[�h���_�~�[�m�[�h�ɐݒ�
	list->dummy.next = &list->dummy;
	list->dummy.previous = &list->dummy;

	// �擪�m�[�h���_�~�[�m�[�h�ɐݒ�
	list->head = &list->dummy;

	// �o�^�����O�ŏ�����
	list->entryCount = 0;

	// �������֐����g�p�\�ɐݒ�
	list->initializeFlug = isValid::valid;
}

/// <summary>
/// �Ō���Ƀm�[�h��ǉ�
/// </summary>
/// <param name="list">�A�����X�g</param>
/// <param name="object">�ǉ�����f�[�^</param>
void insertAtTail(linkedList* list, gameObject object)
{
	// �ǉ�����m�[�h���쐬
	listNode* node = createNode(object, list->head->previous, list->head);

	// �A��������
	list->head->previous->next = node;
	list->head->previous = node;

	// �o�^���𑝉�
	list->entryCount++;
}

/// <summary>
/// �w�肵���l�����m�[�h������
/// </summary>
/// <param name="list">�A�����X�g</param>
/// <param name="type">�w�肵���Q�[���I�u�W�F�N�g�̎��</param>
/// <returns>���������m�[�h�i������Ȃ�������NULL�j</returns>
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
/// �`��
/// </summary>
/// <param name="list">�A�����X�g</param>
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
/// �m�[�h��S���
/// </summary>
/// <param name="list">�A�����X�g</param>
void clearLinkedList(linkedList* list)
{
	// �m�[�h��S�������܂Ń��[�v
	while (list->head->next != list->head)
	{
		// �擪�m�[�h�̎��̃|�C���^��n��
		list->head->next = releaseNode(list->head->next);
		list->entryCount--;
	}
}

/// <summary>
/// �m�[�h����
/// </summary>
/// <param name="object">�Q�[���I�u�W�F�N�g�̃f�[�^</param>
/// <param name="previous">�O�̃m�[�h</param>
/// <param name="next">���̃m�[�h</param>
/// <returns>���������m�[�h</returns>
listNode* createNode(gameObject object, listNode* previous, listNode* next)
{
	// �m�[�h����
	listNode* node = (listNode*)malloc(sizeof(listNode));
	if (node == NULL)
		exit(MEMORY_ERROR);

	// �m�[�h�̃f�[�^��ݒ�
	initializeNode(node, object, previous, next);

	return node;
}

/// <summary>
/// �m�[�h�����
/// </summary>
/// <param name="node">�m�[�h�̃f�[�^</param>
/// <returns></returns>
listNode* releaseNode(listNode* node)
{
	// �������m�[�h�̑O�̃m�[�h�ւ̃|�C���^��ۑ�
	listNode* previous = node->previous;

	// �������m�[�h��A������O��
	node->next->previous = previous;
	previous->next = node->next;

	free(node);

	return previous->next;
}

/// <summary>
/// �m�[�h�̐ݒ�
/// </summary>
/// <param name="node">�ݒ肷��m�[�h</param>
/// <param name="object">�ǉ�����Q�[���I�u�W�F�N�g�̃f�[�^</param>
/// <param name="previous">�O�̃m�[�h�ւ̃|�C���^</param>
/// <param name="next">���̃m�[�h�ւ̃|�C���^</param>
void initializeNode(listNode* node, gameObject object, listNode* previous, listNode* next)
{
	node->object = object;
	node->previous = previous;
	node->next = next;
}
