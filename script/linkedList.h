#pragma once
#include "gameObject.h"
#include "utility.h"

/// <summary>
/// �m�[�h
/// </summary>
typedef struct node{
	gameObject object;				// �I�u�W�F�N�g�̃f�[�^

	struct node* previous;			// �O�̃m�[�h�ւ̃|�C���^
	struct node* next;				// ���̃m�[�h�ւ̃|�C���^
}listNode;

/// <summary>
/// �A�����X�g
/// </summary>
typedef struct {
	listNode dummy;					// �_�~�[�m�[�h
	listNode* head;					// ���X�g�擪

	int entryCount;					// �o�^��
	enum isValid initializeFlug;	// �������֐����g�p���邩�ۂ�
}linkedList;

// �A�����X�g
	// �A�����X�g����
	linkedList* createLinkedList(void);

	// �A�����X�g���
	void releaseLinkedList(linkedList* list);

	// �A�����X�g�̃����o�[������
	void initializeLinkedList(linkedList* list);

	// �m�[�h���Ō���ɒǉ�
	void insertAtTail(linkedList* list, gameObject object);

	// �w�肵���l�����m�[�h������
	listNode* searchNode(linkedList* list, game type);

	// ���X�g�̒��g�����ׂĕ`��
	void draw(linkedList* list);

	// �m�[�h��S���
	void clearLinkedList(linkedList* list);

// �m�[�h
	// �m�[�h����
	listNode* createNode(gameObject object, listNode* previous, listNode* next);

	// �m�[�h���
	listNode* releaseNode(listNode* node);

	// �A�����X�g�̃����o�[������
	void initializeNode(listNode* node, gameObject object, listNode* previous, listNode* next);
