#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinSearchTreeNodeType //노드
{
	int key;
	char value;

	struct BinSearchTreeNodeTyoe* pLeftChild;
	struct BinSearchTreeNodeTyoe* pRightChild;
} BinSearchTreeNode;

typedef struct BinSeachTreeType
{
	BinSearchTreeNode* pRootNode; //트리
} BinSearchTree;

BinSearchTree* createBinSearchTree()
{
	BinSearchTree* pReturn = NULL;
	pReturn = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = NULL;
	}
	else {
		printf("오류, 메모리 할당, createBinSearchTree()\n");
	}

	return pReturn;
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
	BinSearchTreeNode* pReturn = NULL;

	if (pBinSearchTree == NULL) {  //검색하려는 트리가 빈 트리면 null을 반환하고 끝내겠다
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
			printf("오류, 중복된 키-[%d], getParentNode()\n", key);
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
{                                                                    //제거 대상이 될 노드를 찾는 함수
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
		pChildNode = pDelNode->pLeftChild; //삭제될 노드의 자식 노드를 저장해뒀다가 나중에 삭제된 노드위에 다시 붙여주기 위해 저장해둠
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

	pPredecessor = pDelNode;             //가장 오른쪽 노드 찾아가는 과정
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
	else {  //삭제되는 노드가 루트 노드인 경우
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
		printf("오류, 존재하지 않는 키-[%d],deleteDataBST()\n", key);
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

void deleteBinSearchTree(BinSearchTree* pBinSearchTree) //트리 전체를 삭제
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


int countNode(BinSearchTreeNode* pTreeNode) //노드 개수 구하는 함수
{
	int count = 0;
	if (pTreeNode != NULL)
	{
		count = 1 + countNode(pTreeNode->pLeftChild) + countNode(pTreeNode->pRightChild);
	}
	return count;
}

void arrayNode(BinSearchTreeNode* pTreeNode, int level)   //트리에 있는 노드들 배열에 넣어서 반환
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

int return_getParentNode(BinSearchTreeNode* pCurrentNode, int key) //insert할 노드의 부모 노드를 찾아서 부모노드의 키를 출력해주는 함수
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
		printf("파일열기 실패\n");
		return 1;
	}

	FILE* fp2 = fopen("C:\\bintree\\hw_output.txt", "w+");
	if (fp2 == NULL) {
		printf("파일열기 실패\n");
		return 1;
	}

	int nodes1[200], nodes2[200];
	char line[100] = { '0' }; //파일을 읽어오기 위한 변수
	int line_count = 1; //첫번째 트리의 노드 수 -1 만큼 읽기위해 파일에서 읽은 줄 count 하기 위한 것
	int count1 = 0, count2 = 0; //노드들을(엣지를?) 저장할 배열 크기

	fgets(line, sizeof(line), fp); //노드 수는 배열에 저장 안할거니까 노드 수 부분은 그냥 읽기만 함
	int first_tree = atoi(line); //엣지 수 -1 (= 첫번째 트리)의 노드들까지만 읽기 위해서  first_tree에 첫번째 트리의 노드 수 저장해둠

	while (line_count != first_tree) // 첫 번째 트리의 엣지들을 읽어서 nodes 배열에 저장
	{
		fgets(line, sizeof(line), fp);
		char* ptr = strtok(line, " ");
		nodes1[count1++] = atoi(ptr);
		ptr = strtok(NULL, " ");
		nodes1[count1++] = atoi(ptr);
		line_count++;
	}

	fgets(line, sizeof(line), fp); //노드 수는 배열에 저장 안할거니까 엣지 수 부분은 그냥 읽기만 함
	int second_tree = atoi(line);

	while (feof(fp) == 0) //// 두 번째 트리의 엣지들을 읽어서 nodes 배열에 저장
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

	int add_edges = 1, rm_edges = 0; //추가된 엣지, 삭제된 엣지의 개수 저장할 변수 (트리1에 트리2가 붙여지는 거니까 엣지가 무조건 1개는 추가되니까 그냥 초기값을 1로 함)
	int parentNode_key; //return_getParentNode() 함수의 값을 저장하기 위한 변수

	if (pTree != NULL)
	{
		if(count1>=count2){ //두 트리 중에 노드 수가 더 많은 (엣지 수가 더 많은) 트리를 먼저 생성해서 변경되는 엣지의 비용을 최소화하기 위함
			for (int i = 0; i < first_tree; i++) { // 노드의 개수가 많은 트리 먼저 생성
				if (i == 0) //엣지를 순서대로 배열에 저장해뒀기 때문에 맨 처음 index에 있는 노드는 따로 처리되도록 해서 루트 노드 먼저 생성함
					insertDataBST(pTree, nodes1[0], NULL);
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes1[2 * i - 1]); //맨처음 index를 따로 처리해서 루트노드를 생성했으니까 엣지에서 뒷 부분에 있는 노드(추가될 노드)의 부모를 가져옴
					int ret = insertDataBST(pTree, nodes1[2 * i - 1], NULL); //엣지에서 뒷부분에 있는 노드(추가될 노드)를 추가
					if (ret == 1) //insertDataBST()가 정상적으로 실행됐을 경우에만 output 파일에 출력될 수 있도록 하기 위함
						fprintf(fp2, "%d %d\n", parentNode_key, nodes1[2 * i - 1]); //output 파일에 부모 노드와 추가되는 노드를 출력해서 엣지를 표현
				}

			} // 노드의 개수가 많은 트리 먼저 생성

			for (int i = 0; i < second_tree; i++) { //위의 for문에서 생성된 트리에 다른 1개의 트리의 노드들을 1개씩 추가
				if (i == 0) {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[0]);
					int ret = insertDataBST(pTree, nodes2[0], NULL);
					if (ret == 1) //insertDataBST()가 정상적으로 실행됐을 경우에만 output 파일에 출력될 수 있도록 하기 위함
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[0]);
				}
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[2 * i - 1]);
					if (parentNode_key != nodes2[2 * i - 2])
						rm_edges++, add_edges++; //새롭게 추가될 노드의 부모노드될 노드의 키 값이 원래 트리에서의 부모노드의 키 값과 다르면 삭제되는 노드, 추가된 노드 +1씩 해줌
					int ret = insertDataBST(pTree, nodes2[2 * i - 1], NULL);
					if (ret == 1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[2 * i - 1]);
					
				}

			} 

		}

		else if (count2 > count1) { //두 트리 중에 노드 수가 더 많은 (엣지 수가 더 많은) 트리를 먼저 생성해서 변경되는 엣지의 비용을 최소화하기 위함
			for (int i = 0; i < second_tree; i++) {  // 노드의 개수가 많은 트리 먼저 생성
				if (i == 0)
					insertDataBST(pTree, nodes2[0], NULL);
				else {
					parentNode_key = return_getParentNode(pTree->pRootNode, nodes2[2 * i - 1]);
					int ret = insertDataBST(pTree, nodes2[2 * i - 1], NULL);
					if (ret ==1)
						fprintf(fp2, "%d %d\n", parentNode_key, nodes2[2 * i - 1]);
				}

			}

			for (int i = 0; i < first_tree; i++) { //위의 for문에서 생성된 트리에 다른 1개의 트리의 노드들을 1개씩 추가
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

		
		/*printf("추가된 노드: %d, 삭제된 노드: %d\n", add_edges, rm_edges);
		displayBinSearchTree(pTree->pRootNode, 0, '-'); */

		deleteBinSearchTree(pTree);
	}
	
	fclose(fp);
	fclose(fp2);
	return 0;
}






