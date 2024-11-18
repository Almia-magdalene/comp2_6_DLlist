#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
    if (!l || !p) return;

    p->pNext = l->header;  // 現在の先頭ノードを次ノードに設定
    p->pPrev = NULL;

    if (l->header)
    {
        l->header->pPrev = p;  // 現在の先頭ノードの前ノードを更新
    }
    else
    {
        l->footer = p;  // リストが空の場合はfooterも更新
    }

    l->header = p;  // 新しいノードを先頭に設定
}


// 末尾にデータを追加
void push_back(list* l, node* p)
{
    if (!l || !p) return;

    p->pNext = NULL;
    p->pPrev = l->footer;  // 現在の末尾ノードを前ノードに設定

    if (l->footer)
    {
        l->footer->pNext = p;  // 現在の末尾ノードの次ノードを更新
    }
    else
    {
        l->header = p;  // リストが空の場合はheaderも更新
    }

    l->footer = p;  // 新しいノードを末尾に設定
}


// pのノードを削除
void remove_node(list* l, node* p)
{
    if (!l || !p) return;

    if (p->pPrev)
    {
        p->pPrev->pNext = p->pNext;  // 前のノードがあれば、その次ノードを更新
    }
    else
    {
        l->header = p->pNext;  // pが先頭ならheaderを更新
    }

    if (p->pNext)
    {
        p->pNext->pPrev = p->pPrev;  // 次のノードがあれば、その前ノードを更新
    }
    else
    {
        l->footer = p->pPrev;  // pが末尾ならfooterを更新
    }

    // ノードを完全に切り離す
    p->pNext = NULL;
    p->pPrev = NULL;
}


// pの次のノードを削除
void remove_next(list* l, node* p)
{
    if (!l || !p || !p->pNext) return;

    remove_node(l, p->pNext);
}


// pの前のノードを削除
void remove_prev(list* l, node* p)
{
    if (!l || !p || !p->pPrev) return;

    remove_node(l, p->pPrev);
}



// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
