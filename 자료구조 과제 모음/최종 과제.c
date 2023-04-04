#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinSearchTreeNodeType //���
{
	int key;
	char value;

	struct BinSearchTreeNodeTyoe* pLeftChild;
	struct BinSearchTreeNodeTyoe* pRightChild;
} BinSearchTreeNode;

typedef struct BinSeachTreeType
{
	BinSearchTreeNode* pRootNode; //Ʈ��
} BinSearchTree;

BinSearchTree* createBinSearchTree()
{
	BinSearchTree* pReturn = NULL;
	pReturn = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
	}
	else {
		printf("����, �޸� �Ҵ�, createBinSearchTree()\n");
	}

	return pReturn;
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode* pReturn = NULL;

	if (pBinSearchTree == NULL) {  //�˻��Ϸ��� Ʈ���� �� Ʈ���� null�� ��ȯ�ϰ� �����ڴ�
		return NULL;
	}
	pReturn = pBinSearchTree->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		else if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	return pReturn;
}

int getParentNode(BinSearchTreeNode* pCurrentNode, int key, BinSearchTreeNode** ppResult)
{
	int ret = 1;
	BinSearchTreeNode* pParentNode = NULL;

	while (pCurrentNode != NULL) {
		if (key == pCurrentNode->key) {
			printf("����, �ߺ��� Ű-[%d], getParentNode()\n", key);
			ret = 0;
			return ret;
		}
		else if (key < pCurrentNode->key) {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pRightChild;
		}
	}
	if (1 == ret) {
		*ppResult = pParentNode;
	}

	return ret;
}

BinSearchTreeNode* createNewBinSearchTreeNode(int key, char value)
{
	BinSearchTreeNode* pNewNode = NULL;

	pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
	if (pNewNode != NULL) {
		pNewNode->key = key;
		pNewNode->value = value;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;
	}

	return pNewNode;
}

void insertNewBinSearchTreeNode(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pNewNode)
{
	if (pParentNode == NULL) {
		pBinSearchTree->pRootNode = pNewNode;
	}
	else {
		if (pNewNode->key < pParentNode->key) {
			pParentNode->pLeftChild = pNewNode;
		}
		else {
			pParentNode->pRightChild = pNewNode;
		}

	}

}

int insertDataBST(BinSearchTree* pBinSearchTree, int key, char value)
{
	int ret = 1;
	BinSearchTreeNode* pParentNode = NULL;
	BinSearchTreeNode* pNewNode = NULL;

	if(pBinSearchTree == NULL) {
		ret = 0;
		return ret;
	}

	ret = getParentNode(pBinSearchTree->pRootNode, key, &pParentNode);
	if (0 == ret) {
		return ret;
	}

	pNewNode = createNewBinSearchTreeNode(key, value);
	if (NULL == pNewNode) {
		return 0;
	}
	insertNewBinSearchTreeNode(pBinSearchTree, pParentNode, pNewNode);
	return ret;
}

BinSearchTreeNode* searchWithParentNodeBST(BinSearchTree* pBinSearchTree, int key, BinSearchTreeNode** ppParentNode)
{                                                                    //���� ����� �� ��带 ã�� �Լ�
	BinSearchTreeNode* pReturn = NULL;
	BinSearchTreeNode* pParentNode = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}
	pReturn = pBinSearchTree->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}

		pParentNode = pReturn;

		if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	if (NULL != ppParentNode) {
		*ppParentNode = pParentNode;
	}

	return pReturn;
}

void deleteNodeNochildren(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pDelNode)
{
	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = NULL;
		}
		else {
			pParentNode->pRightChild = NULL;
		}
	}
	else {
		pBinSearchTree->pRootNode = NULL;
	}
}

void deleteNodeOneChildren(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pDelNode)
{
	BinSearchTreeNode* pChildNode = NULL;

	if (pDelNode->pLeftChild != NULL) {
		pChildNode = pDelNode->pLeftChild; //������ ����� �ڽ� ��带 �����ص״ٰ� ���߿� ������ ������� �ٽ� �ٿ��ֱ� ���� �����ص�
	}
	else {
		pChildNode = pDelNode->pRightChild;
	}

	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = pChildNode;
		}
		else {
			pParentNode->pRightChild = pChildNode;
		}
	}
	else {
		pBinSearchTree->pRootNode = pChildNode;
	}
}

void deleteNodeTwoChildren(BinSearchTree* BinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pDelNode)
{
	BinSearchTreeNode* pPredecessor = NULL, * pSuccessor = NULL;

	pPredecessor = pDelNode;             //���� ������ ��� ã�ư��� ����
	pSuccessor = pDelNode->pLeftChild;

	while (pSuccessor->pRightChild != NULL) {
		pPredecessor = pSuccessor;
		pSuccessor = pSuccessor->pRightChild;
	}

	pPredecessor->pRightChild = pSuccessor->pLeftChild;
	pSuccessor->pLeftChild = pDelNode->pLeftChild;
	pSuccessor->pRightChild = pDelNode->pRightChild;

	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = pSuccessor;
		}
		else {
			pParentNode->pRightChild = pSuccessor;
		}
	}
	else {  //�����Ǵ� ��尡 ��Ʈ ����� ���
		BinSearchTree->pRootNode = pSuccessor;
	}
}

int deleteDataBST(BinSearchTree* pBinSearchTree, int key) 
{
	int ret = 1;
	BinSearchTreeNode* pDelNode = NULL, * pParentNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = 0;
		return ret;
	}
	pDelNode = searchWithParentNodeBST(pBinSearchTree, key, &pParentNode);
	if (pDelNode == NULL) {
		printf("����, �������� �ʴ� Ű-[%d],deleteDataBST()\n", key);
		ret = 0;
		return ret;
	}

	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		deleteNodeNochildren(pBinSearchTree, pParentNode, pDelNode);
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		deleteNodeTwoChildren(pBinSearchTree, pParentNode, pDelNode);
	}
	else {
		deleteNodeOneChildren(pBinSearchTree, pParentNode, pDelNode);
	}

	free(pDelNode);
	return ret;
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
	if (pTreeNode != NULL) {
		deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
		deleteBinSearchTreeInternal(pTreeNode->pRightChild);
		free(pTreeNode);
	}
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree) //Ʈ�� ��ü�� ����
{
	if (pBinSearchTree != NULL) {
		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
		free(pBinSearchTree);
	}
}

void displayBinSearchTree(BinSearchTreeNode* pTreeNode, int level, char type)
{
	int i = 0;

	if (pTreeNode != NULL) {
		for (i = 0; i < level; i++) {
			printf("   ");
		}
		
		printf("-(%c)-key: %i, value-%c\n", type, pTreeNode->key, pTreeNode->value);
		displayBinSearchTree(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTree(pTreeNode->pRightChild, level + 1, 'R');
	}
}


int countNode(BinSearchTreeNode* pTreeNode) //��� ���� ���ϴ� �Լ�
{
	int count = 0;
	if (pTreeNode != NULL)
	{
		count = 1 + countNode(pTreeNode->pLeftChild) + countNode(pTreeNode->pRightChild);
	}
	return count;
}

void arrayNode(BinSearchTreeNode* pTreeNode, int level)   //Ʈ���� �ִ� ���� �迭�� �־ ��ȯ
{
	int i = 0;
	int num = countNode(pTreeNode);

	int *nodes = malloc(sizeof(int) * num);

	if (pTreeNode != NULL) {
		for (i = 0; i < level; i++) {
			nodes[i] = pTreeNode->key;
		}

		arrayNode(pTreeNode->pLeftChild, level + 1);
		arrayNode(pTreeNode->pRightChild, level + 1);
	}

	return nodes;

}

int return_getParentNode(BinSearchTreeNode* pCurrentNode, int key) //insert�� ����� �θ� ��带 ã�Ƽ� �θ����� Ű�� ������ִ� �Լ�
{
	BinSearchTreeNode* pParentNode = NULL;

	while (pCurrentNode != NULL) {
		if (key == pCurrentNode->key) {
			return 0;
		}
		else if (key < pCurrentNode->key) {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pRightChild;
		}
	}

	return pParentNode->key;
}



int main()
{

	FILE* fp = fopen("C:\\bintree\\hw_input.txt", "r+");
	if (fp == NULL) {
		printf("���Ͽ��� ����\n");
		return 1;
	}

	FILE* fp2 = fopen("C:\\bintree\\hw_output.txt", "w+");
	if (fp2 == NULL) {
		printf("���Ͽ��� ����\n");
		return 1;
	}

	int nodes1[200], nodes2[200];
	char line[100] = { '0' }; //������ �о���� ���� ����
	int line_count = 1; //ù��° Ʈ���� ��� �� -1 ��ŭ �б����� ���Ͽ��� ���� �� count �ϱ� ���� ��
	int count1 = 0, count2 = 0; //������(������?) ������ �迭 ũ��

	fgets(line, sizeof(line), fp); //��� ���� �迭�� ���� ���ҰŴϱ� ��� �� �κ��� �׳� �б⸸ ��
	int first_tree = atoi(line); //���� �� -1 (= ù��° Ʈ��)�� ��������� �б� ���ؼ�  first_tree�� ù��° Ʈ���� ��� �� �����ص�

	while (line_count != first_tree) // ù ��° Ʈ���� �������� �о nodes �迭�� ����
	{
		fgets(line, sizeof(line), fp);
		char* ptr = strtok(line, " ");
		nodes1[count1++] = atoi(ptr);
		ptr = strtok(NULL, " ");
		nodes1[count1++] = atoi(ptr);
		line_count++;
	}

	fgets(line, sizeof(line), fp); //��� ���� �迭�� ���� ���ҰŴϱ� ���� �� �κ��� �׳� �б⸸ ��
	int second_tree = atoi(line);

	while (feof(fp) == 0) //// �� ��° Ʈ���� �������� �о nodes �迭�� ����
	{
		fgets(line, sizeof(line), fp);
		char* ptr = strtok(line, " ");
		nodes2[count2++] = atoi(ptr);
		ptr = strtok(NULL, " ");
		nodes2[count2++] = atoi(ptr);
	}
	
	BinSearchTree* pTree = NULL;
	BinSearchTreeNode* pSearchNode = NULL;
	pTree = createBinSearchTree(); 

	int add_edges = 1, rm_edges = 0; //�߰��� ����, ������ ������ ���� ������ ���� (Ʈ��1�� Ʈ��2�� �ٿ����� �Ŵϱ� ������ ������ 1���� �߰��Ǵϱ� �׳� �ʱⰪ�� 1�� ��)
	int parentNode_key; //return_getParentNode() �Լ��� ���� �����ϱ� ���� ����

	if (pTree != NULL)
	{
		if(count1>=count2){ //�� Ʈ�� �߿� ��� ���� �� ���� (���� ���� �� ����) Ʈ���� ���� �����ؼ� ����Ǵ� ������ ����� �ּ�ȭ�ϱ� ����
			for (int i = 0; i < first_tree; i++) { // ����� ������ ���� Ʈ�� ���� ����
				if (i == 0) //������ ������� �迭�� �����صױ� ������ �� ó�� index�� �ִ� ���� ���� ó���ǵ��� �ؼ� ��Ʈ ��� ���� ������
					insertDataBST(pTree, nodes1[0], NULL);
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes1[2 * i - 1]); //��ó�� index�� ���� ó���ؼ� ��Ʈ��带 ���������ϱ� �������� �� �κп� �ִ� ���(�߰��� ���)�� �θ� ������
					int ret = insertDataBST(pTree, nodes1[2 * i - 1], NULL); //�������� �޺κп� �ִ� ���(�߰��� ���)�� �߰�
					if (ret == 1) //insertDataBST()�� ���������� ������� ��쿡�� output ���Ͽ� ��µ� �� �ֵ��� �ϱ� ����
						fprintf(fp2, "%d %d\n", parentNode_key, nodes1[2 * i - 1]); //output ���Ͽ� �θ� ���� �߰��Ǵ� ��带 ����ؼ� ������ ǥ��
				}

			} // ����� ������ ���� Ʈ�� ���� ����

			for (int i = 0; i < second_tree; i++) { //���� for������ ������ Ʈ���� �ٸ� 1���� Ʈ���� ������ 1���� �߰�
				if (i == 0) {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[0]);
					int ret = insertDataBST(pTree, nodes2[0], NULL);
					if (ret == 1) //insertDataBST()�� ���������� ������� ��쿡�� output ���Ͽ� ��µ� �� �ֵ��� �ϱ� ����
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[0]);
				}
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[2 * i - 1]);
					if (parentNode_key != nodes2[2 * i - 2])
						rm_edges++, add_edges++; //���Ӱ� �߰��� ����� �θ���� ����� Ű ���� ���� Ʈ�������� �θ����� Ű ���� �ٸ��� �����Ǵ� ���, �߰��� ��� +1�� ����
					int ret = insertDataBST(pTree, nodes2[2 * i - 1], NULL);
					if (ret == 1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[2 * i - 1]);
					
				}

			} 

		}

		else if (count2 > count1) { //�� Ʈ�� �߿� ��� ���� �� ���� (���� ���� �� ����) Ʈ���� ���� �����ؼ� ����Ǵ� ������ ����� �ּ�ȭ�ϱ� ����
			for (int i = 0; i < second_tree; i++) {  // ����� ������ ���� Ʈ�� ���� ����
				if (i == 0)
					insertDataBST(pTree, nodes2[0], NULL);
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[2 * i - 1]);
					int ret = insertDataBST(pTree, nodes2[2 * i - 1], NULL);
					if (ret ==1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[2 * i - 1]);
				}

			}

			for (int i = 0; i < first_tree; i++) { //���� for������ ������ Ʈ���� �ٸ� 1���� Ʈ���� ������ 1���� �߰�
				if (i == 0) {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes1[0]);
					int ret = insertDataBST(pTree, nodes1[0], NULL);
					if (ret == 1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes1[0]);
				}
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes1[2 * i - 1]);
					if (parentNode_key != nodes1[2 * i - 2])
						rm_edges++, add_edges++;
					int ret = insertDataBST(pTree, nodes1[2 * i - 1], NULL);
					if (ret == 1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes1[2 * i - 1]);

				}

			}
		}


		fprintf(fp2, "%d\n%d", add_edges, rm_edges);

		
		/*printf("�߰��� ���: %d, ������ ���: %d\n", add_edges, rm_edges);
		displayBinSearchTree(pTree->pRootNode, 0, '-'); */

		deleteBinSearchTree(pTree);
	}
	
	fclose(fp);
	fclose(fp2);
	return 0;
}






